/*
	RTPRotary.cpp - Class for reading and managing a Rotary Encoder.
	Created by Oscar Martínez Carmona @ RockinTechProjects, September 18 2018.
*/


#include "Arduino.h"
#include "RTPRotary.h"

void RTPRotary::callbackOnRotation( void (*userFunc)(int,String,int) ){
	long newPosition = read()/4;
  	if (newPosition < _oldPosition) {
   		_oldPosition = newPosition;
   		(*userFunc)(_ID,"ROTATING LEFT",newPosition);
  	}
  	else if (newPosition > _oldPosition) {
   		_oldPosition = newPosition;
   		(*userFunc)(_ID,"ROTATING RIGHT",newPosition);
  	}
}