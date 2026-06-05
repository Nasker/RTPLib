/*
	RTPLedArray.cpp - Class for managing an array of LEDS
	Created by Oscar Martínez Carmona @ RockinTechProjects, June 10, 2014.
*/


#include "Arduino.h"
#include "RTPLedArray.h"


RTPLedArray::RTPLedArray(uint8_t firstPin, uint8_t nLeds){ 
  _firstPin = firstPin;
  _nLeds = nLeds;
  for(uint8_t i = _firstPin ; i < _firstPin+_nLeds; i++){
    pinMode(i,OUTPUT);
  }
  } 
/*
RTPLedArray::RTPLedArray(uint8_t ledArray[], uint8_t nLeds){
	_nLeds = nLeds;
	for(uint8_t i=0; i<nLeds; i++){
		_ledArray[i] = ledArray[i];
		pinMode(_ledArray[i], OUTPUT);
	}
}
*/
void RTPLedArray::update(uint8_t value){
for(uint8_t i = _firstPin ; i < _firstPin+_nLeds; i++){
    if(value + _firstPin == i) digitalWrite(i,true);
    else digitalWrite(i,false);
  }  
}
/*
void RTPLedArray::updateArray(uint8_t value){
for(uint8_t i = 0 ; i < _nLeds; i++){
    if(value == i) digitalWrite(i,true);
    else digitalWrite(i,false);
  }  
}*/