#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class OSCCommunication {
    // Osc
    ofxOscSender sender;
    ofxOscMessage message;

	public:
		void setup();
		void sendPosition(float x, float y);
};