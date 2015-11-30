http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

```
$ cd debian7_with_dir
$ javac -d lib src/java/com/example/HelloWorld.java
$ javah -jni -classpath lib -d lib com.example.HelloWorld
$ gcc -fPIC -g -I./lib -I/usr/lib/jvm/java-7-openjdk-amd64/include -fclasspath=lib -foutput-class-dir=lib -c -o lib/HelloWorld.o src/cpp/HelloWorld.cpp
$ gcc -shared -o jni/libHelloWorld.so lib/HelloWorld.o
$ java -classpath lib -Djava.library.path=$PWD/jni com.example.HelloWorld
Oh JNI, how cumbersome you are!
```


## use legacy compiled file

### make legacy compiled file

```
cd debian7_with_dir
gcc -c -fPIC -o lib/HelloRepeat.o src/cpp/HelloRepeat.c
cp src/cpp/HelloRepeat.h lib/HelloRepeat.h
```

### link legacy compiled file

```
cp src/cpp/HelloRepeat.h lib/
javac -d lib src/java/com/example/HelloRepeat.java 
javah -jni -classpath lib -d lib com.example.HelloRepeat
gcc -fPIC -c -g -I./lib -I/usr/lib/jvm/java-7-openjdk-amd64/include -fclasspath=lib -foutput-class-dir=lib -c -o lib/HelloRepeatJni.o src/cpp/HelloRepeatJni.c
ld -r lib/HelloRepeatJni.o lib/HelloRepeat.o -o lib/HelloRepeatJniAll.o
gcc -shared -o jni/libHelloRepeatJni.so lib/HelloRepeatJniAll.o
```

``
$ java -classpath lib -Djava.library.path=$PWD/jni com.example.HelloRepeat foo 2
Hello foo
Hello foo
```

## use legacy archive file

### make legacy archive file

```
cd debian7_with_dir
gcc -c -fPIC -o lib/HelloRepeat.o src/cpp/HelloRepeat.c
ar cr lib/HelloRepeat.a lib/HelloRepeat.o
ar t lib/HelloRepeat.a
rm lib/HelloRepeat.o
```

### link legacy compiled file

```
cp src/cpp/HelloRepeat.h lib/
javac -d lib src/java/com/example/HelloRepeat.java
javah -jni -classpath lib -d lib com.example.HelloRepeat
gcc -fPIC -c -g -I./lib -I/usr/lib/jvm/java-7-openjdk-amd64/include -fclasspath=lib -foutput-class-dir=lib -c -o lib/HelloRepeatJni.o src/cpp/HelloRepeatJni.c
# ar t lib/HelloRepeat.a
# ar x lib/HelloRepeat.a
ld -r lib/HelloRepeatJni.o lib/HelloRepeat.a -o lib/HelloRepeatJniAll.o
gcc -shared -o jni/libHelloRepeatJni.so lib/HelloRepeatJniAll.o
```

``
$ java -classpath lib -Djava.library.path=$PWD/jni com.example.HelloRepeat foo 2
Hello foo
Hello foo
```
