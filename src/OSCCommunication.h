#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class OSCCommunication {
    // Osc
    ofxOscReceiver receiver;
    ofxOscSender sender;
    ofxOscMessage message;

	public:
		void setup();
		void sendPosition(float x, float y);
		void nextMessage(ofxOscMessage* message);
		bool hasMessage(); 
};