package com.example.jnidemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.entity.Girl;

public class MainActivity extends Activity {

	protected static final String TAG = "MainActivity";
	private Button testBtn;
	private Button testBtn2;
	private TextView infoLabel;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		testBtn = (Button)findViewById(R.id.testBtn);
		testBtn2 = (Button)findViewById(R.id.testBtn2);
		infoLabel = (TextView)findViewById(R.id.infoLabel);
		testBtn.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				String str = helloLog();
				Log.v(TAG, "string from native code: " + str);
				infoLabel.setText("string from native: " + str);
				Log.v(TAG, "10 + 32 = " + plus(10, 32));
			}
		});
		testBtn2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Log.d(TAG, "you click button 2");
				Girl g = new Girl();
				g.setAge(22);
				g.setName("shimei");
				passObject(g);
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}
	
	static {
		System.loadLibrary("hellolog"); //²»ÐèÒªÐ´lib
		System.loadLibrary("plus-jni");
	}
	
	private native String helloLog();
	private native void passObject(Girl g);  //pass java class to native level
	
	private native int plus(int i, int j);
}
