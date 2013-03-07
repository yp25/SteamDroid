LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

MY_MODULE_DIR 		:= cryptopp

LOCAL_MODULE    	:= $(MY_MODULE_DIR)
LOCAL_SRC_FILES		:= \
	$(subst $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/,,$(wildcard $(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/*.c*))

LOCAL_C_INCLUDES 	:= \
        $(LOCAL_PATH)/android \
		$(MY_BASE_JNI_PATH)/$(MY_MODULE_DIR)/
	
LOCAL_CPPFLAGS		+= -march=armv7a -fno-coalesce-templates -fno-coalesce-static-vtables
LOCAL_LDLIBS 		+= -lm -lz -lgnustl_static
LOCAL_LDFLAGS		+= -flat_namespace -undefined suppress -m
LOCAL_SHARED_LIBRARIES := \
    libz libcutils libutils
	
include $(BUILD_SHARED_LIBRARY)