#pragma once
#include <android/log.h>

#define LOGI(msg) __android_log_write(ANDROID_LOG_INFO, "VideoKit", msg);
#define LOGE(msg) __android_log_write(ANDROID_LOG_ERROR, "VideoKit", msg);
#define LOGD(msg) __android_log_write(ANDROID_LOG_DEBUG, "VideoKit", msg);

#define LOGDF(msg, ...) \
		{ \
			char buffer[4096]; \
			sprintf(buffer, msg, __VA_ARGS__); \
			LOGD(buffer); \
		}

