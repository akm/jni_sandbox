https://newcircle.com/bookshelf/java_fundamentals_tutorial/_java_native_interface_jni

```
$ cd debian7_with_dir-2nd
$ mkdir classes
$ javac -d ./classes/ ./src/com/marakana/jniexamples/Hello.java
$ cd classes
$ javah -jni com.marakana.jniexamples.Hello
$ gcc -fPIC -o libHelloImpl.so -lc -shared -I/usr/lib/jvm/java-7-openjdk-amd64/include -I/usr/local/jdk1.6.0_03/include/linux com_marakana_jniexamples_Hello.c
$ export LD_LIBRARY_PATH=.
$ java com.marakana.jniexamples.Hello Student 5
Hello Student
Hello Student
Hello Student
Hello Student
Hello Student
```
