package com.tooflya.fruitninja;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;

public class Game extends Cocos2dxActivity {

	@SuppressLint("NewApi")
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
	}

	static {
		System.loadLibrary("game");
	}
}
