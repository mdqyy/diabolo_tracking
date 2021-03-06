#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);

    mode = COLOR_MODE;

    tracked = false;
    x = 0;
    y = 0;

    width = 640;
    height = 480;

    infoText = "";

    //Gesture recognition setup
    gr.setup();
    //OSC communication setup
    oc.setup();
    //Tracking setup
    color_tracking.setup(width, height);
    //IR tracking setup
    ir_tracking.setup();

}

//--------------------------------------------------------------
void testApp::update(){
    if(mode == COLOR_MODE){
        tracked = color_tracking.update(&x, &y);
        if(tracked){
            oc.sendPosition(x, y);
            gr.update(x, y);
        }   
    }
    else{
        tracked = ir_tracking.getDiaboloPosition(&x, &y);
        if(tracked){
            oc.sendPosition(x, y);
            gr.update(x*640, (1 - y)*480);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(39, 40, 34);
    if(mode == COLOR_MODE){
        color_tracking.draw();
        gr.draw(0, 0, height, width);       
    }
    else{
        ir_tracking.draw(0, 0, 480, 640);
        gr.draw(0, 0, height, width);        
    }
// Wiiosc
    /*infoWiimote = "Receiving data from the Wiimote : ";
    if(oc.hasMessage()){
        infoWiimote += "YES";
        ofxOscMessage message;
        oc.nextMessage(&message);
        if(message.getAddress() == "/wii/ir/x" || message.getAddress() == "/wii/ir/y"){
            ir_tracking.newIRMessage(message);            
        }
        else{
            infoWiimote += " (No IR data)";
        }
    }
    else{
        infoWiimote += "NO";
    }
    ofDrawBitmapString(infoWiimote, 20, 700);*/


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    switch( key ){

        case 'j':
            color_tracking.toggleJitter();
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
        case 59:
            switchMode();
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
        color_tracking.selectColor(x, y);
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

void testApp::switchMode(){
    if(mode == COLOR_MODE){
        mode = IR_MODE;
    }
    else{
        mode = COLOR_MODE;
    }
}

void testApp::exit(){
    color_tracking.stopVideo();
}