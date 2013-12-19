#include "ofMain.h"
#include "ofxOsc.h"
#include "IRTracking.h"

void IRTracking::setup(){

}

void IRTracking::newIRMessage(ofxOscMessage msg){
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
}

void IRTracking::draw(int x, int y){
	ofSetColor(0);
    ofFill();
    ofRect(x, y, 320, 240);

    ofSetColor(230, 150, 150);
	for (vector<trackPoint>::iterator it = trackPoints.begin() ; it != trackPoints.end(); ++it){
		ofCircle(x + (*it).x, y + (*it).y, 3);
	}
	    //std::cout << ' ' << *it;

}