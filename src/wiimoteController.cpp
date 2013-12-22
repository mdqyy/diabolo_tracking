#include "ofMain.h"
#include "wiimoteController.h"

cwiid_ir_mesg wiimoteController::ir_msg;

void wiimoteController::setup(){
	
	bdaddr_t bdaddr;
	str2ba("00:1A:E9:44:40:E5", &bdaddr);
	if ((wiimote = cwiid_open(&bdaddr, CWIID_FLAG_MESG_IFC)) == NULL){
		cout << "Unable to connect to the Wiimote!" << endl;
	}
	else{
		cout << "Wiimote connected!" << endl;
		//cwiid_set_rumble(wiimote, true);
		//sleep(1);
		//cwiid_set_rumble(wiimote, false);
		//cwiid_enable(wiimote, CWIID_FLAG_NONBLOCK);
		//cwiid_enable(wiimote, CWIID_FLAG_CONTINUOUS);
		cwiid_command(wiimote, CWIID_CMD_RPT_MODE, CWIID_RPT_IR);
		cwiid_set_mesg_callback(wiimote, messageCallback);
	}
}

void wiimoteController::messageCallback(cwiid_wiimote_t *wiiremote, int msg_count, union cwiid_mesg msg[], struct timespec *timestamp){
	for(unsigned i=0; i < msg_count; i++){
		if(msg[i].type == CWIID_MESG_IR){
			ir_msg = msg[i].ir_mesg;
		}
	}
}

cwiid_ir_mesg wiimoteController::getIRData(){
	return ir_msg;
}
