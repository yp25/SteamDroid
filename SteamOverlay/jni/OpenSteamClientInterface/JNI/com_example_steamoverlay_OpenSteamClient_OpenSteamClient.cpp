#include "com_example_steamoverlay_OpenSteamClient_OpenSteamClient.h"
#include "log.h"

JNIEXPORT void JNICALL Java_com_example_steamoverlay_OpenSteamClient_OpenSteamClient_constructNative
  (JNIEnv *, jobject)
{
	LOGD("Constructed new OSC object");
	LOGD("Sent from native code");
}

JNIEXPORT void JNICALL Java_com_example_steamoverlay_OpenSteamClient_OpenSteamClient_pollMessages
  (JNIEnv *, jobject)
{
	LOGD("Polling from native code");
}
