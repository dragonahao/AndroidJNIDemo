LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_LDLIBS := -llog 
LOCAL_MODULE    := hellolog
LOCAL_SRC_FILES := native.c framebuffer_info.c
include $(BUILD_SHARED_LIBRARY)

#编译能完成加法的第一个so文件，静态库文件
include $(CLEAR_VARS)
LOCAL_LDLIBS 	:= -llog
LOCAL_MODULE    := libplus
LOCAL_SRC_FILES := plus.c
include $(BUILD_STATIC_LIBRARY)

#second lib, which will depend on and include the first one
include $(CLEAR_VARS)
LOCAL_LDLIBS 	:= -llog
LOCAL_MODULE    := libplus-jni
LOCAL_SRC_FILES := plus_jni.c
LOCAL_STATIC_LIBRARIES := libplus
include $(BUILD_SHARED_LIBRARY)