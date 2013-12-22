#include "ofMain.h"
#include "ofxOsc.h"
#include "IRTracking.h"

void IRTracking::setup(){
    wm.setup();
}

/*void IRTracking::newIRMessage(ofxOscMessage msg){
	if(msg.getAddress() == "/wii/ir/x"){
		int i = msg.getArgAsInt32(1);
		float x = msg.getArgAsFloat(2);
		if(i < trackPoints.size()){
			trackPoints.at(i).x = x;
		}
		else{
			trackPoint point;
			point.x = x;
			// différent trackPoints.at(i) -> dépend de si la wiimote envoie les points par ordre croissant
			trackPoints.push_back(point);
		}
	}
	if(msg.getAddress() == "/wii/ir/y"){
		int i = msg.getArgAsInt32(1);
		float y = msg.getArgAsFloat(2);
		if(i < trackPoints.size()){
			trackPoints.at(i).y = y;
		}
		else{
			trackPoint point;
			point.y = y;
			// différent trackPoints.at(i) -> dépend de si la wiimote envoie les points par ordre croissant
			trackPoints.push_back(point);
		}
	}
}*/

void IRTracking::draw(int x, int y, int h, int w){
	ofSetColor(0);
    ofFill();
    ofRect(x, y, w, h);

    ofSetColor(230, 150, 150);
	/*for (vector<trackPoint>::iterator it = trackPoints.begin() ; it != trackPoints.end(); ++it){
		ofCircle(x + ((*it).x)*320, y + ((*it).y)*240, 3);
		cout <<  "x " << (*it).x << " y " << (*it).y << endl;
	}*/
	for(unsigned j=0; j < CWIID_IR_SRC_COUNT; j++){
		cwiid_ir_mesg ir_msg;
		ir_msg = wm.getIRData();
		if(ir_msg.src[j].valid == 1){
			ofCircle(x + ir_msg.src[j].pos[0] * w / CWIID_IR_X_MAX, y + h - ir_msg.src[j].pos[1] * h / CWIID_IR_Y_MAX, 5);			
		}
	}
}

bool IRTracking::getDiaboloPosition(float *x, float *y){
	cwiid_ir_mesg ir_msg;
	ir_msg = wm.getIRData();
	if(ir_msg.src[0].valid == 1){
		*x = (float) ir_msg.src[0].pos[0] / CWIID_IR_X_MAX;
		*y = (float) ir_msg.src[0].pos[1] / CWIID_IR_Y_MAX;
		return true;
	}
	return false;

}