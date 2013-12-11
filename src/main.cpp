#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( int argc, char* argv[] ){

	//ofSetupOpenGL(660,240,OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(320,300,OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	testApp* app = new testApp();
	ofRunApp(app);	

}
