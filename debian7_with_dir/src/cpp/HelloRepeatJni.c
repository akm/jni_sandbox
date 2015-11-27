#include <stdio.h>
#include "com_example_HelloRepeat.h"
#include "HelloRepeat.h"

JNIEXPORT jint JNICALL Java_com_example_HelloRepeat_helloRepeat
(JNIEnv *env, jobject obj, jstring who, jint times) {
  jboolean iscopy;
  char *name;
  name = (*env)->GetStringUTFChars(env, who, &iscopy);
  return (jint)hello_repeat(name, (int)times);
}
