#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"

JNIEXPORT void JNICALL Java_HelloJNI_hello(JNIEnv *env, jobject obj) {
    printf("Hello from C!\n");
}