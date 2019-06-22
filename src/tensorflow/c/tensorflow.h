#include <jni.h>
#include <stdio.h>
#include <tensorflow/c/c_api.h>

JNIEXPORT jstring JNICALL Java_io_mattmoore_tensorflow_Tensorflow_hello(JNIEnv *env, jobject obj);

JNIEXPORT jstring JNICALL Java_io_mattmoore_tensorflow_Tensorflow_version(JNIEnv *env, jobject obj);

JNIEXPORT jobject JNICALL Java_io_mattmoore_tensorflow_Tensorflow_tensor(JNIEnv *env, jobject klass, jstring name);
