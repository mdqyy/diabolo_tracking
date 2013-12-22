#include "ofMain.h"
#include "testApp.h"

#define USAGE printf("=====================================================================\n \
Usage : \n\n \
\
\t f :\t toggle fullscreen\n \
\t m :\t switch between color tracking mode and IR tracking mode\n\n \
\
Gesture recognition options :\n\n \
\t r :\t record gesture\n \
\t [ :\t decrease class label\n \
\t ] :\t increase class label\n \
\t t :\t train pipeline and active gesture recognition\n \
\t s :\t save training data\n \
\t c :\t clear training data\n\n \
Color tracking options :\n\n \
\t j :\t toggle jitter for color tracking\n\n \
=====================================================================\n")

//========================================================================
int main( int argc, char* argv[] ){
	cout << USAGE << endl;
	//ofSetupOpenGL(660,240,OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(1280,1024,OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	testApp* app = new testApp();
	if(argc > 1){
		app->setTrainingDataFilename(argv[1]);		
	}
	else{
		app->setTrainingDataFilename("");
	}
	ofRunApp(app);	

}
