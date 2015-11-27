http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

```
$ cd debian7_with_dir
$ javac -d classes src/java/com/example/HelloWorld.java
$ javah -jni -classpath classes -d lib com.example.HelloWorld
$ gcc -fPIC -o jni/libHelloWorld.so -lc -shared -I/usr/lib/jvm/java-7-openjdk-amd64/include -I/usr/lib/jvm/java-7-openjdk-amd64/include/linux -Ilib src/cpp/HelloWorld.cpp
$ export LD_LIBRARY_PATH=jni
$ java -classpath classes com.example.HelloWorld
```
