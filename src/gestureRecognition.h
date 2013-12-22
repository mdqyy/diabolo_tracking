#pragma once

#include "GRT/GRT.h"

class gestureRecognition {
    //GRT
    GRT::LabelledTimeSeriesClassificationData trainingData;      //This will store our training data
    GRT::MatrixDouble timeseries;                                //This will store a single training sample
    GRT::GestureRecognitionPipeline pipeline;                    //This is a wrapper for our classifier and any pre/post processing modules
    bool record;                                            //This is a flag that keeps track of when we should record training data
    GRT::UINT trainingClassLabel;                                //This will hold the current label for when we are training the classifier
    string dataTrainingFilename;
    string infoText;

	public:
		void setup();
		void update(float x, float y);
		void draw(int x, int y, int h, int w);
		void recordGesture();
		void decreaseClassLabel();
		void increaseClassLabel();
		void trainPipeline();
		void saveTrainingData();
		void clearTrainingData();
		void setTrainingDataFilename(char* filename);

};