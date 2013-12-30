#include "plus.h"
#include <jni.h>
#include "hgllog.h"

/*static void printSomeInfo() {
	LOGE("this is static block code");
}*/

jint
Java_com_example_jnidemo_MainActivity_plus
	(JNIEnv* env,
	 jobject object,
	 jint x,
	 jint y)
{
	return plus(x, y);
}
