#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "framebuffer_info.h"

#define LOG_TAG "native.c"
//Java_packageName_className_methodname
jstring
Java_com_example_jnidemo_MainActivity_helloLog
  (JNIEnv* env, jobject thiz)
{
	getDisplayInfo();
	return (*env)->NewStringUTF(env, "string come from c file!");
}

//c file invoke java file
void
Java_com_example_jnidemo_MainActivity_passObject
	(JNIEnv* env, jobject thiz, jobject jgirl)
{
	jclass girl_class = (*env)->FindClass(env, "com/example/entity/Girl");
	if (girl_class == NULL) {
		__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "class not found!");
	} else {
		__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "class found!");
	}

	jfieldID fieldAge = (*env)->GetFieldID(env, girl_class, "age", "I"); //获得int类型字段
	//jfeildID fieldName = (*env)->GetFieldID(env, girl_class, "name", "Ljava/lang/String;");	 //

	jint girl_age = (*env)->GetIntField(env, jgirl, fieldAge);
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "get girl age %d", girl_age);
	//对应set方法
	//env->SetIntField(obj,fid,a);
}
