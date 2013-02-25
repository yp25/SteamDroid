package com.example.steamoverlay;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SteamHUDConfig {
	public float scaleFactor = 1.0f;
	
	public List<SteamHUDNote> notes = new ArrayList<SteamHUDNote>();;
	
	public SteamHUDInput hudInput;
	public SteamHUDRender hudRender;
	public Random r = new Random();
	
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