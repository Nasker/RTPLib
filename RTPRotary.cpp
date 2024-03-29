/*
	RTPRotary.cpp - Class for reading and managing a Rotary Encoder.
	Created by Oscar Martínez Carmona @ RockinTechProjects, September 18 2018.
*/


#include "Arduino.h"
#include "RTPRotary.h"

void RTPRotary::callbackOnRotation( void (*userFunc)(int,String,int,int) ){
	long newPosition = read()/_divider;
	if (newPosition < _oldPosition) {
		_oldPosition = newPosition;
		(*userFunc)(_ID,"LEFT",-1,newPosition);
	}
	else if (newPosition > _oldPosition) {
		_oldPosition = newPosition;
		(*userFunc)(_ID,"RIGHT",1,newPosition);
	}
}

void RTPRotary::callbackOnRotation( void (*userFunc)(int,int,int,int) ){
	long newPosition = read()/_divider;
	if (newPosition < _oldPosition) {
		_oldPosition = newPosition;
		(*userFunc)(_ID,UP,-1,newPosition);
	}
	else if (newPosition > _oldPosition) {
		_oldPosition = newPosition;
		(*userFunc)(_ID,DOWN,1,newPosition);
	}
}