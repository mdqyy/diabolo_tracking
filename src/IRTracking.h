#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class trackPoint {
	public:
		float x;
		float y;
		// 0: ??? / 1: baguette / 2: diabolo
		unsigned type;
};

class IRTracking {

	vector<trackPoint> trackPoints;

	public:

		void setup();
		void newIRMessage(ofxOscMessage msg);
		void draw(int x, int y);

};