#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    tracked = false;
    x = 0;
    y = 0;

//####### GRT setup #######

    //Initialize the training and info variables
    infoText = "";
    gr.setup();
    oc.setup();
    tracking.setup();
//####### End GRT setup #######

}

//--------------------------------------------------------------
void testApp::update(){
    tracked = tracking.update(&x, &y);
    if(tracked){
        oc.sendPosition(x, y);
        gr.update(x, y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    tracking.draw();
    gr.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    switch( key ){
        cout << key << endl;
        case 'j':
            tracking.toggleJitter();
            break;
        case 'r':
            gr.recordGesture();
            break;
        case 53:
            gr.decreaseClassLabel();
            break;
        case 45:
            gr.increaseClassLabel();
            break;
        case 't':
            gr.trainPipeline();
            break;
        case 's':
            gr.saveTrainingData();
            break;
        case 'c':
            gr.clearTrainingData();
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(button == 0) {
        tracking.selectColor(x, y);
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::setTrainingDataFilename(char* filename){
    gr.setTrainingDataFilename(filename);
}