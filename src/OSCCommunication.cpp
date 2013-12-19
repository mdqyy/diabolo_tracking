#include "ofMain.h"
#include "OSCCommunication.h"

void OSCCommunication::setup(){
	sender.setup("192.168.0.14", 12001);
	receiver.setup(57120);
}

void OSCCommunication::sendPosition(float x, float y){
	message.setAddress("/hello");
	message.addFloatArg(x);
	message.addFloatArg(y);
	sender.sendMessage(message);
	message.clear();	
}

bool OSCCommunication::hasMessage(){
	return receiver.hasWaitingMessages();
}

void OSCCommunication::nextMessage(ofxOscMessage* message){
	if(receiver.hasWaitingMessages()){
		receiver.getNextMessage(message);		
	}
}
