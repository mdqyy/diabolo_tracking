#pragma once

#include "ofMain.h"

#include "OSCCommunication.h"
#include "gestureRecognition.h"
#include "colorTracking.h"

class testApp : public ofBaseApp{

    string dataTrainingFilename;

    string infoText;                                        //This string will be used to draw some info messages to the main app window

    bool tracked;
    float x;
    float y;

    gestureRecognition gr;
    OSCCommunication oc;
    colorTracking tracking;

	public:

        void setTrainingDataFilename(char* filename);

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
