#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( int argc, char* argv[] ){

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
