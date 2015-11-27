http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

$ cd osx_with_dir
$ javac -d lib src/java/com/example/HelloWorld.java
$ javah -jni -classpath lib -d lib com.example.HelloWorld
$ g++ -dynamiclib -o lib/libHelloWorld.jnilib lib/HelloWorld.o
$ java -classpath lib -Djava.library.path=$PWD/lib com.example.HelloWorld
$ g++ -I./lib -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers -c -o lib/HelloWorld.o src/cpp/HelloWorld.cpp
Exception in thread "main" java.lang.UnsatisfiedLinkError: com.example.HelloWorld.print()V
	at com.example.HelloWorld.print(Native Method)
	at com.example.HelloWorld.main(HelloWorld.java:6)
