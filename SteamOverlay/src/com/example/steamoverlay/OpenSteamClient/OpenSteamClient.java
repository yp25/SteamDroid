package com.example.steamoverlay.OpenSteamClient;

public class OpenSteamClient {
	public native void logIn(String username, String password);
	public native void logout();
	
	public native void startEventLoop();
	public native void pollMessages();
}