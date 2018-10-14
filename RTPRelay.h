/*
	RTPRelay.h - Class for controlling a Relay
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 14, 2018.
*/

#ifndef RTPRelay_h
#define RTPRelay_h

#include "Arduino.h"


class RTPRelay{
	byte _relayOutputPin;
	bool _state;
	bool _prevState;
	
	public:
		RTPRelay(byte relayOutputPin);
		bool isCoilActive();
		void setState(bool state);
		void switchState();

	private:
		void write();
};

#endif