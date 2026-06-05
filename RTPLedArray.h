/*
	RTPLedArray.h - Class for managing an array of LEDS
	Created by Oscar Martínez Carmona @ RockinTechProjects, June 10, 2014.
*/

#ifndef RTPLedArray_h
#define RTPLedArray_h

#include "Arduino.h"

class RTPLedArray{
	uint8_t _firstPin;
	uint8_t _nLeds;
	uint8_t _ledArray[];
	
	public:
		RTPLedArray(uint8_t firstPin, uint8_t nLeds);
		//RTPLedArray(uint8_t ledArray[], uint8_t nLeds);

		void update(uint8_t value);
		//void updateArray(uint8_t value);
};

#endif