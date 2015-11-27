http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

$ cd osx_with_dir
$ javac -d lib src/java/com/example/HelloWorld.java
$ javah -jni -classpath lib -d lib com.example.HelloWorld
$ g++ -I./lib -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers -c -o lib HelloWorld.cpp

$ g++ -dynamiclib -o libhelloworld.jnilib HelloWorld.o
$ java HelloWorld
Oh JNI, how cumbersome you are!
