#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"

#include "GRT/GRT.h"

class color
{
    public:

        float hue, sat;

        ofVec2f pos;
};

class testApp : public ofBaseApp{

    ofImage circle_templ_img;

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

    // Osc
    ofxOscSender sender;
    ofxOscMessage message;

    string dataTrainingFilename;

    //GRT
    GRT::LabelledTimeSeriesClassificationData trainingData;      //This will store our training data
    GRT::MatrixDouble timeseries;                                //This will store a single training sample
    GRT::GestureRecognitionPipeline pipeline;                    //This is a wrapper for our classifier and any pre/post processing modules
    bool record;                                            //This is a flag that keeps track of when we should record training data
    GRT::UINT trainingClassLabel;                                //This will hold the current label for when we are training the classifier
    string infoText;                                        //This string will be used to draw some info messages to the main app window


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
        void setJitter(bool s);
        void toggleJitter();



};
