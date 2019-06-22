#include "tensorflow.h"
#include <string.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL Java_io_mattmoore_tensorflow_Tensorflow_hello(JNIEnv *env, jobject obj) {
  return (*env)->NewStringUTF(env, "Hello World!");
}

JNIEXPORT jstring JNICALL Java_io_mattmoore_tensorflow_Tensorflow_version(JNIEnv *env, jobject obj) {
  return (*env)->NewStringUTF(env, TF_Version());
}

JNIEXPORT jobject JNICALL Java_io_mattmoore_tensorflow_Tensor_tensor(JNIEnv *env, jobject object, jstring name) {
  //TF_Tensor *tensor;
  jmethodID initMethod;
  jvalue args[1];

  // klass = (*env)->FindClass(env, "io/mattmoore/tensorflow/Tensor");
  // initMethod = (*env)->GetMethodID(env, klass, "<init>", "(Ljava/lang/String;)V");
  jstring test = (*env)->NewStringUTF(env, "TEST");
  // object = (*env)->NewObject(env, klass, initMethod, name);

  jclass klass = (*env)->GetObjectClass(env, object);
  jmethodID getName = (*env)->GetMethodID(env, klass, "getName", "()Ljava/lang/String;");
  jmethodID setName = (*env)->GetMethodID(env, klass, "setName", "(Ljava/lang/String;)V");

  jstring returnValue = (*env)->CallObjectMethod(env, object, getName);

  const char * value = (*env)->GetStringUTFChars(env, returnValue, NULL);
  char * result = (char *)malloc(strlen(value) * sizeof(char));
  strcpy(result, value);
  strcat(result, " Moore");

  (*env)->CallObjectMethod(env, object, setName, (*env)->NewStringUTF(env, result));

  (*env)->ReleaseStringUTFChars(env, returnValue, value);
  free(result);

  return object;
}
