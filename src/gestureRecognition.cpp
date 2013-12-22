#include "ofMain.h"
#include "gestureRecognition.h"

void gestureRecognition::setup(){

	trainingClassLabel = 1;
    record = false;

    //The input to the training data will be the [x y] from the mouse, so we set the number of dimensions to 2
    trainingData.setNumDimensions( 2 );

    //Initialize the DTW classifier
    GRT::DTW dtw;

    //Turn on null rejection, this lets the classifier output the predicted class label of 0 when the likelihood of a gesture is low
    dtw.enableNullRejection( true );

    //Set the null rejection coefficient to 3, this controls the thresholds for the automatic null rejection
    //You can increase this value if you find that your real-time gestures are not being recognized
    //If you are getting too many false positives then you should decrease this value
    dtw.setNullRejectionCoeff( 3 );

    //Turn on the automatic data triming, this will remove any sections of none movement from the start and end of the training samples
    dtw.enableTrimTrainingData(true, 0.1, 90);

    //Offset the timeseries data by the first sample, this makes your gestures (more) invariant to the location the gesture is performed
    dtw.setOffsetTimeseriesUsingFirstSample(true);

    //Add the classifier to the pipeline (after we do this, we don't need the DTW classifier anymore)
    pipeline.setClassifier( dtw );

    if(dataTrainingFilename != ""){
        //Load training data
        if( trainingData.loadDatasetFromFile(dataTrainingFilename) ){
            cout << "Training data loaded from file" << endl;
        }
        else{
            cout <<  "WARNING: Failed to load training data from file" << endl;
        }
        //Train the pipeline
        pipeline.train( trainingData );
    }

}

void gestureRecognition::update(float x, float y){
	//Grab the current diabolo tracking position
	GRT::VectorDouble sample(2);
	sample[0] = x;
	sample[1] = y;

	// Predict gesture
	if( pipeline.getTrained() ){
	    pipeline.predict( sample );
	}

	//If we are recording training data, then add the current sample to the training data set
	if( record ){
	    timeseries.push_back( sample );
	}
}

void gestureRecognition::draw(int x, int y, int h, int w){
    string text;
    int textX = 20;
    int textY = h + 20;

    //Draw the training info
    ofSetColor(255, 255, 255);
    text = "------------------- TrainingInfo -------------------";
    ofDrawBitmapString(text, textX,textY);

    if( record ) ofSetColor(255, 0, 0);
    else ofSetColor(255, 255, 255);
    textY += 15;
    text = record ? "RECORDING" : "Not Recording";
    ofDrawBitmapString(text, textX,textY);

    ofSetColor(255, 255, 255);
    textY += 15;
    text = "TrainingClassLabel: " + ofToString(trainingClassLabel);
    ofDrawBitmapString(text, textX,textY);

    textY += 15;
    text = "NumTrainingSamples: " + ofToString(trainingData.getNumSamples());
    ofDrawBitmapString(text, textX,textY);


    //Draw the prediction info
    textY += 30;
    text = "------------------- Prediction Info -------------------";
    ofDrawBitmapString(text, textX,textY);

    textY += 15;
    text =  pipeline.getTrained() ? "Model Trained: YES" : "Model Trained: NO";
    ofDrawBitmapString(text, textX,textY);

    textY += 15;
    text = "PredictedClassLabel: " + ofToString(pipeline.getPredictedClassLabel());
    ofDrawBitmapString(text, textX,textY);

    textY += 15;
    text = "Likelihood: " + ofToString(pipeline.getMaximumLikelihood());
    ofDrawBitmapString(text, textX,textY);

    textY += 15;
    text = "SampleRate: " + ofToString(ofGetFrameRate(),2);
    ofDrawBitmapString(text, textX,textY);

    if( record ){
        ofFill();
        for(GRT::UINT i=0; i<timeseries.getNumRows(); i++){
            double x = timeseries[i][0];
            double y = timeseries[i][1];
            double r = ofMap(i,0,timeseries.getNumRows(),0,255);
            double g = 0;
            double b = 255-r;

            ofSetColor(r,g,b);
            ofEllipse(x,y,5,5);
        }
    }

    if( pipeline.getTrained() ){

        //Draw the data in the DTW input buffer
        GRT::DTW *dtw = pipeline.getClassifier< GRT::DTW >();

        if( dtw != NULL ){
            vector< GRT::VectorDouble > inputData = dtw->getInputDataBuffer();
            for(GRT::UINT i=0; i<inputData.size(); i++){
                double x = inputData[i][0];
                double y = inputData[i][1];
                double r = ofMap(i,0,inputData.size(),0,255);
                double g = 0;
                double b = 255-r;

            }
        }
    }

    //Draw the info text
    textY += 30;
    text = "InfoText: " + infoText;
    ofDrawBitmapString(text, textX,textY);
}

void gestureRecognition::recordGesture(){
	record = !record;
	if( !record ){
	    trainingData.addSample(trainingClassLabel, timeseries);
	    //Clear the timeseries for the next recording
	    timeseries.clear();
	}
}

void gestureRecognition::decreaseClassLabel(){
	if( trainingClassLabel > 1 )
		trainingClassLabel--;
}

void gestureRecognition::increaseClassLabel(){
	trainingClassLabel++;
}

void gestureRecognition::trainPipeline(){
	if( pipeline.train( trainingData ) ){
	    infoText = "Pipeline Trained";
	}
	else infoText = "WARNING: Failed to train pipeline";
}

void gestureRecognition::saveTrainingData(){
	if( trainingData.saveDatasetToFile("TrainingData.txt") ){
		infoText = "Training data saved to file";
	}
	else infoText = "WARNING: Failed to save training data to file";
}

void gestureRecognition::clearTrainingData(){
	trainingData.clear();
	infoText = "Training data cleared";
}

void gestureRecognition::setTrainingDataFilename(char* filename){
	dataTrainingFilename = filename;
}