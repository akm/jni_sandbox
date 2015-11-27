https://newcircle.com/bookshelf/java_fundamentals_tutorial/_java_native_interface_jni

mkdir classes
javac -d ./classes/ ./src/com/marakana/jniexamples/Hello.java
cd classes
javah -jni com.marakana.jniexamples.Hello
