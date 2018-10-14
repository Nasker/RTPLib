/*
	RTPRelay.cpp - Class for controlling a Relay
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 14, 2018.
*/


#include "Arduino.h"
#include "RTPRelay.h"


RTPRelay::RTPRelay(byte relayOutputPin){
  _relayOutputPin = relayOutputPin;
  _state = false;
  write();
}

bool RTPRelay::isCoilActive(){
	return _state;
}

void RTPRelay::setState(bool state){
	_state = state;
	write();
}

void RTPRelay::switchState(){
	_state = !_state;
	write();
}


void RTPRelay::write(){
	digitalWrite(_relayOutputPin, _state);
}