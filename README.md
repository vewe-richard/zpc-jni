# Play with zpc-jni project
## For x86
1. pull build environment
```
$ docker pull jiangjqian/ud103:v1
```

2. clone UnifySDK
```
$ git clone git@github.com:SiliconLabs/UnifySDK.git
$ cd UnifySDK
$ git checkout ver_1.0.3 -b ver_1.0.3  #use old version as compiling issue with latest versions
```

3. clone zpc-jni inside UnifySDK
```
# in directory of UnifySDK
$ git checkout git@github.com:vewe-richard/zpc-jni.git
```

4. run docker and build zpc-jni
```
# inside UnifySDK
$ docker run -it --rm  -v`pwd`:`pwd` -w `pwd` jiangjqian/ud103:v1

# build zpc-jni
$ cd zpc-jni
$ make
```

## For arm64 
TODO

# How to build docker image jiangjqian/ud103:v1 ?
## For x86
```
$ git clone git@github.com:SiliconLabs/UnifySDK.git
$ cd UnifySDK
$ git checkout ver_1.0.3 -b ver_1.0.3  #use old version as compiling issue with latest versions

$ cd docker
$ ./build_docker.sh amd64 jiangjqian/ud103:v1
```

## For arm64
TODO  
Note: as build environment is huge and heavily depends on network speed, suggest to build it from aws cloud instance


# How to create Makefile for zpc-jni?
1. create buildzpc.sh 
Follow 'Play with zpc-jni project' step 2 to checkout UnifySDK,
```
$mkdir build
$cd build
$cmake -GNinja ..
$ninja

# Change ../applications/zpc/main.c a bit to make it build
$ninja -v > buildzpc.sh 2>&1

# generate makefile
$ cd ..  # to root directory of UnifySDK
$ ./zpc-jni/genMakefile
```



