package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"strings"
)

func linkLine(makefile *os.File, line string) {

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
	makefile.WriteString("\n%.o: %.c $(DEPS)\n")
	makefile.WriteString("\t$(CC) -c -o $@ $< $(CFLAGS)\n")
	makefile.WriteString("zpc: main.o \n")
	makefile.WriteString("\t$(CC) -o zpc main.o")
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
			fmt.Println("compile line")
			compileLine(makefile, fileScanner.Text())

		} else if strings.Contains(fileScanner.Text(), "/usr/bin/c++") {
			fmt.Println("link line")
			linkLine(makefile, fileScanner.Text())
		}
	}

	readFile.Close()
}
