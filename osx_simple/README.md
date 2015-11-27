http://mrjoelkemp.com/2012/01/getting-started-with-jni-and-c-on-osx-lion/

cd osx_simple
javac HelloWorld.java
javah -jni HelloWorld
g++ -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers -c HelloWorld.cpp
g++ -dynamiclib -o libhelloworld.jnilib HelloWorld.o
