http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

```
$ cd debian7_with_dir
$ javac -d lib src/java/com/example/HelloWorld.java
$ javah -jni -classpath lib -d lib com.example.HelloWorld
$ gcc -fPIC -g -I./lib -I/usr/lib/jvm/java-7-openjdk-amd64/include -fclasspath=lib -foutput-class-dir=lib -c -o lib/HelloWorld.o src/cpp/HelloWorld.cpp
$ gcc -shared -o jni/libHelloWorld.so lib/HelloWorld.o
$ java -classpath lib -Djava.library.path=$PWD/jni com.example.HelloWorld
Exception in thread "main" java.lang.UnsatisfiedLinkError: com.example.HelloWorld.print()V
        at com.example.HelloWorld.print(Native Method)
        at com.example.HelloWorld.main(HelloWorld.java:6)
```
