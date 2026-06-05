/*
	RTPRelay.h - Class for controlling a Relay
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 14, 2018.
*/

#ifndef RTPRelay_h
#define RTPRelay_h

#include "Arduino.h"


class RTPRelay{
	uint8_t _relayOutputPin;
	bool _state;
	bool _prevState;
	bool _isInvertedLogic;
	
	public:
		RTPRelay(uint8_t relayOutputPin);
		RTPRelay(uint8_t relayOutputPin, bool isInvertedLogic);
		bool getState();
		void setState(bool state);
		void switchState();

	private:
		void write();
};

#endif