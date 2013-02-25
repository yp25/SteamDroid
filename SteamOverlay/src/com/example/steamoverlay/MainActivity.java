package com.example.steamoverlay;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

import uk.co.thomasc.steamkit.*;

public class MainActivity extends Activity implements OnClickListener {
    private String user = "DownsiderT";
    private String pass = "dsjsdjsd";
    
    Button buttonStart, buttonStop;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        buttonStart = (Button) findViewById(R.id.start_button);
        buttonStop = (Button) findViewById(R.id.stop_button);
        
        buttonStart.setOnClickListener(this);
        buttonStop.setOnClickListener(this);
    }
    
    public void onClick(View src) {
        switch (src.getId()) {
        case R.id.start_button:
          startService(new Intent(this, SteamOverlayService.class));
          break;
        case R.id.stop_button:
          stopService(new Intent(this, SteamOverlayService.class));
          break;
        }
    }

    private void update()
    {
    	try {
    		Thread.sleep(500);
    	}
    		
    	catch (Exception e)
    	{
    		e.printStackTrace();
    	}
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
