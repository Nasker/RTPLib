/*
	RTPTeensyWatchDog.h - Class for managing Teensy 3x watchdog.
	Created by Oscar Martínez Carmona @ RockinTechProjects, December 17, 2018.
*/

#ifndef RTPTeensyWatchDog_h
#define RTPTeensyWatchDog_h

#include "Arduino.h"

class RTPTeensyWatchDog{
	//uint8_t _timeOut;
	
	public:
		RTPTeensyWatchDog();
		void init();
		void kick();
};

#endif