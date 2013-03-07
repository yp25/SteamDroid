LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

MY_MODULE_DIR 		:= opensteamclient

LOCAL_CPP_EXTENSION := .cc .cpp

LOCAL_MODULE    	:= $(MY_MODULE_DIR)
LOCAL_SRC_FILES		:= \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/*.c*)) \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Messages/*.c*)) \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Source/Protobufs/*.c*))
LOCAL_LDLIBS 		:= -lm -llog
LOCAL_C_INCLUDES 	:= \
	$(MY_BASE_JNI_PATH) \
	$(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/Include \
	$(MY_BASE_JNI_PATH)/Protobufs/src/

LOCAL_SHARED_LIBRARIES := \
    libcryptopp
	
LOCAL_STATIC_LIBRARIES	:= \
	protobufs
	
include $(BUILD_STATIC_LIBRARY)