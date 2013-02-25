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

class SteamHUDNote
{
	public int type;
	public int offset;

	public boolean removing;
	public boolean remove;
	
	public long deathTime;
	
	public String user;
	public String action;
	public String text;
}

public class SteamHUDRender extends ViewGroup {
	public SteamHUDConfig config;
	
	private Paint loadPaint, userPaint, textPaint;
	private Bitmap bitmap_alertBox, bitmap_alertBox_avatarBox;
	private Matrix scaleMatrix;
	private Random r;
	
	private int cornerX;
	private int cornerY;
	
	private int originX;
	private int originY;
	
	public SteamHUDRender(Context context, SteamHUDConfig config) {
		super(context);
		this.config = config;
		AssetManager am = getContext().getAssets();
		
		scaleMatrix = new Matrix();
		scaleMatrix.reset();
		scaleMatrix.postScale(config.scaleFactor, config.scaleFactor, 1.0f, 1.0f);
		
		Toast.makeText(getContext(), "Created HUD", Toast.LENGTH_LONG).show();
		loadPaint = new Paint();
		loadPaint.setAntiAlias(true);
		loadPaint.setTextSize(22);
		loadPaint.setARGB(255, 255, 255, 255);
		
		userPaint = new Paint();
		userPaint.setAntiAlias(true);
		userPaint.setTextSize(10);
		userPaint.setARGB(255, 135, 180, 215);
		
		textPaint = new Paint();
		textPaint.setAntiAlias(true);
		textPaint.setTextSize(10);
		textPaint.setARGB(255, 165, 165, 150);
		
		this.setClipChildren(false);
		
		try {
			bitmap_alertBox = BitmapFactory.decodeStream(am.open("images/alert_box.png"));
			bitmap_alertBox_avatarBox = BitmapFactory.decodeStream(am.open("images/alert_box_avatarbox.png"));
		}
		
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@Override
	protected void onDraw(Canvas canvas)
	{
		WindowManager.LayoutParams params = (WindowManager.LayoutParams)getLayoutParams();
		super.onDraw(canvas);
		
		boolean invalid = false;
		
		originX = -240;
		originY = 0;
		
		int ro = 0;
		int[] runningOffset = new int[config.notes.size()];
		for (int i=config.notes.size() - 1;i>=0;i--)
		{
			ro += config.notes.get(i).offset - 74;
			runningOffset[i] = ro;
		}
		
		for (int i=0;i<config.notes.size();i++)
		{
			int ofs = config.notes.size() - i;
			SteamHUDNote note = config.notes.get(i);
			
			int offset = runningOffset[i];
			
			drawImageScaled(canvas, bitmap_alertBox, 0, offset, loadPaint, 0.0f);
			drawImageScaled(canvas, bitmap_alertBox_avatarBox, 17, 17 + offset, loadPaint, 0.0f);
			
			drawTextScaled(canvas, note.user, 64, 25 + offset, userPaint);
			drawTextScaled(canvas, note.action, 64, 25 + 14 + offset, textPaint);
			drawTextScaled(canvas, note.text, 64, 25 + 28 + offset, textPaint);

			if (!note.removing)
			{
				if (note.offset > 0)
				{
					note.offset -= 8;
					invalid = true;
				}
			
				if (note.offset <= 0)
				{
					note.offset = 0;
				}
			}
			else
			{
				if (note.offset < 74)
				{
					note.offset += 8;
					invalid = true;
				}
			
				if (note.offset >= 74)
				{
					note.remove = true;
				}
			}
		}
		
		config.cleanNotes();
		
		if (invalid)
			this.postInvalidate();
	}
	
	private void drawImageScaled(Canvas c, Bitmap b, int x, int y, Paint p, float scale)
	{
		if (scale == 0.0f)
			scale = config.scaleFactor;
		
		x = (int)(x * scale + (cornerX + originX * scale));
		y = (int)(y * scale + (cornerY + originY * scale));
			
		c.drawBitmap(b, 
				new Rect(0, 0, b.getWidth(), b.getHeight()),
				new Rect(x, y, (int)(x + b.getWidth() * scale), (int)(y + b.getHeight() * scale)),
				loadPaint);
	}
	
	private void drawTextScaled(Canvas c, String text, int x, int y, Paint p)
	{
		x = (int)(x * config.scaleFactor + (cornerX + originX * config.scaleFactor));
		y = (int)(y * config.scaleFactor + (cornerY + originY * config.scaleFactor));
		
		float os = p.getTextSize();
		p.setTextSize(p.getTextSize() * config.scaleFactor);
			
		c.drawText(text, x, y, p);
		
		p.setTextSize(os);
	}

	@Override
	protected void onLayout(boolean changed, int l, int t, int r, int b) {
		cornerX = r;
		cornerY = b;
	}
}
