#pragma once

#include "ofMain.h"

#include "OSCCommunication.h"
#include "gestureRecognition.h"
#include "colorTracking.h"
#include "IRTracking.h"

#define COLOR_MODE 1
#define IR_MODE 2


class testApp : public ofBaseApp{

	int mode;

    string dataTrainingFilename;

    string infoText; //This string will be used to draw some info messages to the main app window

    string infoWiimote;

    bool tracked;
    float x;
    float y;

    gestureRecognition gr;
    OSCCommunication oc;
    colorTracking color_tracking;
    IRTracking ir_tracking;


	public:

        void setTrainingDataFilename(char* filename);
        void switchMode();

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
