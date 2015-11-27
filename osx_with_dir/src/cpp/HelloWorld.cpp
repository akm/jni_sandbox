#include <jni.h>
#include <iostream>
#include "com_example_HelloWorld.h"
using namespace std;
 
JNIEXPORT void JNICALL 
Java_HelloWorld_print(JNIEnv *, jobject){
    cout << "Oh JNI, how cumbersome you are!\n";
    return;
}
