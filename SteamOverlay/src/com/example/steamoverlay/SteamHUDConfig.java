package com.example.steamoverlay;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.example.steamoverlay.OpenSteamClient.OpenSteamClient;

public class SteamHUDConfig {
	public float scaleFactor;
	
	public List<SteamHUDNote> notes;
	
	public SteamHUDInput hudInput;
	public SteamHUDRender hudRender;
	public Random r;
	
	public OpenSteamClient steamClient;
	
	public SteamHUDConfig()
	{
		notes = new ArrayList<SteamHUDNote>();
		steamClient = new OpenSteamClient();
		r = new Random();
		scaleFactor = 1.0f;
	}
	
	public void cleanNotes()
	{
		for (int i=0;i<notes.size();i++)
		{
			if (notes.get(i).remove)
			{
				notes.remove(i--);
			}
		}
	}
}