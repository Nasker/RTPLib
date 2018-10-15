/*
	RTPPhotoDiodeTrigger.h - Class to generate triggers from PhotoDiodes
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#ifndef RTPPhotoDiodeTrigger_h
#define RTPPhotoDiodeTrigger_h

#include "Arduino.h"

class RTPPhotoDiodeTrigger{
	int _photoInput;

	int _photoRead;
	bool _state;
	bool _prevState;
	int _threshold;
	int _envMax;
	int _envMin;
	bool _shootGuard;
    int _coundGuardCycles;  
    int _countGuard;  
	
	
	public:
		RTPPhotoDiodeTrigger(int photoInput);
		void callibrate(int threshold);
		void setThreshold(int threshold);
		void setCountGuard(int countGuardCycles);
		void readnShoot(void (*f)(String));
		bool overThreshold();
};

#endif