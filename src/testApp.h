#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class color
{
    public:

        float hue, sat;

        ofVec2f pos;
};

class testApp : public ofBaseApp{

    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;

    int R,G,B;

    ofxCvColorImage		    colorImg;       //Main color image which is gonna get wrapped
    ofxCvColorImage		    colorImgHSV;    //the image doing the wrapping

    ofxCvGrayscaleImage		hueImg;     //Hue map
    ofxCvGrayscaleImage		satImg;     //Saturation map
    ofxCvGrayscaleImage             briImg;     //Brightness map

    ofxCvGrayscaleImage     reds;               //Grayscale image we are gonna run the contour finder over to find our color

    color                   one;                //color that we're gonna track

    unsigned char *         colorTrackedPixelsRed;      //just some raw images which we are gonna put pixels into
    ofTexture               trackedTextureRed;          //color texture that we are gonna draw to

    ofxCvContourFinder      finderRed;                  //contour finder, very handy

	public:
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

    /*private:
        ofxCvImage getMask(unsigned char * pixels);*/
};
