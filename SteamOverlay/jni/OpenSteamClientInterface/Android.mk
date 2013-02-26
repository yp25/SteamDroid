LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

MY_MODULE_DIR 			:= OpenSteamClientInterface

LOCAL_MODULE    		:= $(MY_MODULE_DIR)
LOCAL_SRC_FILES 		:= \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/src/*.c*))
LOCAL_LDLIBS 			:= -lm -llog -lz 

#\
#	-L$(CURDIR)/${NDK_APP_PROJECT_PATH}/libs/$(TARGET_ABI_SUBDIR) -ljnix
LOCAL_C_INCLUDES 		:= \
	$(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/jni-include \
	$(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/include \
	$(MY_BASE_JNI_PATH)/OpenSteamClient/include
LOCAL_STATIC_LIBRARIES	:= \
	opensteamclient
	
include $(BUILD_SHARED_LIBRARY)