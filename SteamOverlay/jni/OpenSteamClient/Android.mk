LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

MY_MODULE_DIR 		:= OpenSteamClient

APP_STL := gnustl_static

LOCAL_MODULE    	:= $(MY_MODULE_DIR)
LOCAL_SRC_FILES		:= \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/*.c*)) \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Messages/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Messages/*.c*)) \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Protobufs/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Protobufs/*.c*))
LOCAL_LDLIBS 		:= -lm -llog
LOCAL_C_INCLUDES 	:= \
	$(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Include
	
LOCAL_CFLAGS 		:= -DNULL=0 -DSOCKLEN_T=socklen_t
LOCAL_CPPFLAGS 		:= -DBSD=1 -fexceptions -frtti
	
include $(BUILD_STATIC_LIBRARY)