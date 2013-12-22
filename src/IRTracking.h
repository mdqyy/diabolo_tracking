#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "wiimoteController.h"

class trackPoint {
	public:
		float x;
		float y;
		// 0: ??? / 1: baguette / 2: diabolo
		unsigned type;
};

class IRTracking {

	vector<trackPoint> trackPoints;
	wiimoteController wm;

	public:

		void setup();
		void draw(int x, int y, int h, int w);

};