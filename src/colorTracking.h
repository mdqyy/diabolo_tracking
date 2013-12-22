#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class color
{
    public:

        float hue, sat;

        ofVec2f pos;
};

class colorTracking {

	float xj;
    float yj;

    unsigned traceLength;

    vector<float> traceX;
    vector<float> traceY;

    //list<float*> trace;

    bool jitter = false;

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

    string infoText;

    bool colorSelected;

	public:

		void setup(int width, int height);
		bool update(float* x, float* y);
		void draw();
		void selectColor(int x, int y);
        void setJitter(bool s);
        void toggleJitter();
        void stopVideo();
};