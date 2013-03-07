package com.example.steamoverlay;

import com.example.steamoverlay.SteamHUDInput.COMS_MSG;
import com.example.steamoverlay.OpenSteamClient.OpenSteamClient;

import android.annotation.TargetApi;
import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.IBinder;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

public class SteamOverlayService extends Service {
	private static final String TAG = "SteamOverlayService";
	private SteamHUDInput hudViewInput;
	private SteamHUDRender hudViewRender;
	private SteamHUDConfig config;
	
	@Override
	public IBinder onBind(Intent intent) {
		return null;
	}
	
	@Override
	public void onCreate() {
		Toast.makeText(this, "SteamOverlay Service Created", Toast.LENGTH_LONG).show();
		Log.d(TAG, "onCreate");
		
		OpenSteamClient.initLibs();
		
		config = new SteamHUDConfig();
		config.scaleFactor = 1.5f;
		
		hudViewInput = new SteamHUDInput(this, config);
        WindowManager.LayoutParams params = new WindowManager.LayoutParams(
                WindowManager.LayoutParams.TYPE_SYSTEM_ALERT,
                WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE|
                WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL|
                WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH,
                PixelFormat.TRANSLUCENT);
        
        params.gravity = Gravity.RIGHT | Gravity.BOTTOM;
        params.width = (int)(240 * config.scaleFactor);
        params.height = (int)(1);
        params.setTitle("SteamOverlayInput");
        
        WindowManager wm = (WindowManager) getSystemService(WINDOW_SERVICE);
        wm.addView(hudViewInput, params);
		
        hudViewRender = new SteamHUDRender(this, config);
        WindowManager.LayoutParams paramsRender = new WindowManager.LayoutParams(
                WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY,
                WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE|
                WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL|
                WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH,
                PixelFormat.TRANSLUCENT);
       
        params.setTitle("SteamOverlayInput");
        
        wm.addView(hudViewRender, paramsRender);
        
		config.hudInput = hudViewInput;
		config.hudRender = hudViewRender;
	}

	@Override
	public void onDestroy() {
		Toast.makeText(this, "SteamOverlay Service Stopped", Toast.LENGTH_LONG).show();
		Log.d(TAG, "onDestroy");
	}
	
	@Override
	public void onStart(Intent intent, int startid) {
		Toast.makeText(this, "SteamOverlay Service Started", Toast.LENGTH_LONG).show();
		Log.d(TAG, "onStart");
		
		new Thread(new Runnable(){
			public void run() {
				// TODO Auto-generated method stub
				while(true)
				{
					for (int i=0;i<config.notes.size();i++)
					{
						SteamHUDNote note = config.notes.get(i);
						if (!note.removing)
						{
							if (System.currentTimeMillis() >= note.deathTime)
								hudViewInput.handler.sendEmptyMessage(COMS_MSG.REMOVE_NOTE.ordinal());
						}
					}
					
					try {
						Thread.sleep(100);
					}
					
					catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}).start();
	}
	
	@Override
	public int onStartCommand(Intent intent, int flags, int startId) {
		super.onStartCommand(intent, flags, startId);
	    Notification notification = new Notification(R.drawable.ic_action_search, "SteamOverlay service is running",
	            System.currentTimeMillis());
	    Intent notificationIntent = new Intent(this, SteamOverlayService.class);
	    notificationIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP|
	        Intent.FLAG_ACTIVITY_SINGLE_TOP);
	    PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, notificationIntent, 0);
	    notification.setLatestEventInfo(this, "SteamOverlay",
	            "SteamOverlay service is running", pendingIntent);
	    notification.flags|=Notification.FLAG_NO_CLEAR;
	    startForeground(1337, notification);
	    
		return START_STICKY;
	}
} 