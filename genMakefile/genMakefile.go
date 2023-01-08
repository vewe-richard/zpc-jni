package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

func copy(src string, dst string) error {
	// Read all content of src to data, may cause OOM for a large file.
	data, err := ioutil.ReadFile(src)
	if err != nil {
		println("ReadFile error", err)
		return err
	}
	// Write data to dst
	err = ioutil.WriteFile(dst, data, 0644)
	if err != nil {
		println("WriteFile", err)
		return err
	}
	return nil
}

func linkLine(makefile *os.File, line string) {
	words := strings.Fields(line)
	makefile.WriteString("\nLDLIBS\t=\\\n")
	for _, s := range words {
		var tocopy string
		if s[0] == '/' {
			tocopy = s
		} else if s[0] == '-' {
			println("link option", s)
			continue
		} else {
			tocopy = "build/" + s
		}
		if len(tocopy) < 1 {
			continue
		}
		if tocopy[len(tocopy)-1] == '+' || tocopy[len(tocopy)-1] == 'w' || tocopy[len(tocopy)-2:] == ".o" {
			continue
		}
		_, err := os.Stat(tocopy)
		if err == nil {
			//println("tocopy", tocopy, filepath.Base(tocopy))
			err := copy(tocopy, "zpc-jni/libs/"+filepath.Base(tocopy))
			if err == nil {
				makefile.WriteString("\t\tlibs/" + filepath.Base(tocopy) + "\\\n")
			}
		} else {
			println("Err: can not copy", s)
		}
	}
	makefile.WriteString("\t\t-pthread -ldl\n")
}

func compileLine(makefile *os.File, line string) {
	makefile.WriteString("CC=/usr/bin/cc\n")

	println("CFLAGS=-DCMAKE_PROJECT_VERSION=\\\"1.0.3\\\" -Werror -Wall -std=gnu99 \\")
	makefile.WriteString("CFLAGS=-DCMAKE_PROJECT_VERSION=\\\"1.0.3\\\" -Werror -Wall -std=gnu99\\\n")
	words := strings.Fields(line)
	for _, s := range words {
		if strings.Contains(strings.ReplaceAll(s, string('"'), string("")), "-I..") {
			//println("\t" + s + "\\")
			if strings.Contains(s, string('"')) || strings.Contains(s, string('{')) || strings.Contains(s, string('}')) {
				continue
			}
			makefile.WriteString("\t" + s + "\\\n")
		} else if strings.Contains(s, "-I") {
			dir := "build/" + s[2:]
			out := "build/" + s[2:]
			//println("\t-I" + out + "\\")
			makefile.WriteString("\t-I" + out + "\\\n")

			if false { //set to false after copy is done
				println(dir)
				println(out)
				cmd := exec.Command("mkdir", "-p", out)
				err := cmd.Run()
				if err != nil {
					log.Fatal(err)
				}
				items, _ := ioutil.ReadDir(dir)
				for _, item := range items {
					if !item.IsDir() {
						tocopy := dir + "/" + item.Name()
						fmt.Println(tocopy)

						cmd := exec.Command("cp", tocopy, out)
						err := cmd.Run()
						if err != nil {
							log.Fatal(err)
						}
					}
				}
			}
		} else {
			println(s)
		}
	}
	println(words)
}

func main() {
	err := os.Chdir("/home/richard/disks/sdb6/2023/pytronic/UnifySDK/")
	if err != nil {
		log.Fatal(err)
	}
	//buildzpc.sh is from `ninja -v > buildzpc.sh 2>&1` after change main.c in zpc directory
	//
	readFile, err := os.Open("build/buildzpc.sh")
	if err != nil {
		log.Fatal(err)
	}
	fileScanner := bufio.NewScanner(readFile)
	fileScanner.Split(bufio.ScanLines)

	makefile, err := os.Create("zpc-jni/Makefile")

	if err != nil {
		log.Fatal(err)
	}

	defer makefile.Close()

	for fileScanner.Scan() {
		if strings.Contains(fileScanner.Text(), "/usr/bin/cc") {
			fmt.Println("----------------------------------------------compile line-------------------------------------")
			compileLine(makefile, fileScanner.Text())

		} else if strings.Contains(fileScanner.Text(), "/usr/bin/c++") {
			fmt.Println("-----------------------------------------------link line----------------------------------------")
			linkLine(makefile, fileScanner.Text())
		}
	}
	makefile.WriteString("\nLDFLAGS\t=-pipe -Werror -Wall\n")
	makefile.WriteString("\n%.o: %.c $(DEPS)\n")
	makefile.WriteString("\t$(CC) -c -o $@ $< $(CFLAGS)\n")
	makefile.WriteString("zpc: main.o \n")
	makefile.WriteString("\t/usr/bin/c++ $(LDFLAGS) -o zpc main.o $(LDLIBS)")

	readFile.Close()
}
