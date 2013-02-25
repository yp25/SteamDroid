package com.example.steamoverlay;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

import android.animation.LayoutTransition;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Picture;
import android.graphics.PixelFormat;
import android.graphics.Rect;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.animation.Animation;
import android.view.animation.Animation.AnimationListener;
import android.view.animation.AnimationUtils;
import android.view.animation.GridLayoutAnimationController.AnimationParameters;
import android.view.animation.LayoutAnimationController;
import android.widget.RelativeLayout;
import android.widget.Toast;

public class SteamHUDInput extends ViewGroup {
	public SteamHUDConfig config;
	
	public SteamHUDInput(Context context, SteamHUDConfig config) {
		super(context);
		this.config = config;
	}
	
	public void addNote(SteamHUDNote note)
	{
		config.notes.add(note);
	
		WindowManager.LayoutParams params = (WindowManager.LayoutParams)getLayoutParams();
		WindowManager wm = (WindowManager) getContext().getSystemService(Context.WINDOW_SERVICE);
		
		params.height = (int)(74 * config.notes.size() * config.scaleFactor);
		
		wm.updateViewLayout(this, params);
	}
	
	public void removeNote()
	{
		if (config.notes.size() <= 0)
			return;
		
		boolean removing = false;
		
		for (int i=0;i<config.notes.size();i++)
		{
			SteamHUDNote note = config.notes.get(i);
			if (!note.removing)
			{
				note.removing = true;
				break;
			} else if (i == config.notes.size() - 1) {
				return;
			}
		}
	
		WindowManager.LayoutParams params = (WindowManager.LayoutParams)getLayoutParams();
		WindowManager wm = (WindowManager) getContext().getSystemService(Context.WINDOW_SERVICE);
		
		params.height = (int)(74 * config.notes.size() * config.scaleFactor);
		
		wm.updateViewLayout(this, params);
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event)
	{
		if (event.getAction() == MotionEvent.ACTION_OUTSIDE)
		{
			SteamHUDNote note = new SteamHUDNote();
			note.action = "says:";
			note.user = "dajoh";
			note.text = "im fat " + config.r.nextInt();
			note.offset = 74;
			note.deathTime = System.currentTimeMillis() + 2000;
		
			addNote(note);
		}
		
		if (event.getAction() == MotionEvent.ACTION_DOWN)
		{
			removeNote();
		}
		
		config.hudRender.invalidate();
		return super.onTouchEvent(event);
	}

	@Override
	protected void onLayout(boolean changed, int l, int t, int r, int b) {
	}
}
