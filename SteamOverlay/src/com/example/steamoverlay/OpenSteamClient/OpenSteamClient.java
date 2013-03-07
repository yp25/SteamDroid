package com.example.steamoverlay.OpenSteamClient;

public class OpenSteamClient {
	public native void logIn(String username, String password);
	public native void logout();
	
	public native void pollMessages();
	
	private native void constructNative();
	private native void destructNative();
	
	private static boolean libsInitiated = false;
	
	public static void initLibs()
	{
		if (libsInitiated)
			return;
		
		System.loadLibrary("OpenSteamClientInterface");
		libsInitiated = true;
	}
	
	public OpenSteamClient()
	{
		initLibs();
		constructNative();
	}
}