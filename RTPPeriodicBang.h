/*
	RTPPeriodicBang.h - Class that gives a callback at a periodic rate.
	Created by Oscar Martínez Carmona @ RockinTechProjects, June 21, 2014.
*/

#ifndef RTPPeriodicBang_h
#define RTPPeriodicBang_h

#include "Arduino.h"

class RTPPeriodicBang{
	unsigned int _figurePeriod;
	unsigned long _millisPast;
	
	public:
		RTPPeriodicBang(unsigned figurePeriod);
		void setFigurePeriod(unsigned int figurePeriod);
		int getFigurePeriod();
		void callbackPeriodBang( void (*f)(String) );
};

#endif