/*
	RTPPeriodicBang.cpp - Class that gives a callback at a periodic rate.
	Created by Oscar Martínez Carmona @ RockinTechProjects, June 21, 2014.
*/


#include "Arduino.h"
#include "RTPPeriodicBang.h"


  RTPPeriodicBang::RTPPeriodicBang(unsigned int figurePeriod){
    _figurePeriod = figurePeriod;
    _millisPast = millis();
  }

  void RTPPeriodicBang::setFigurePeriod(unsigned int figurePeriod){
    _figurePeriod = figurePeriod;
  }

 int RTPPeriodicBang::getFigurePeriod(){
    return _figurePeriod;
  }

  void RTPPeriodicBang::callbackPeriodBang( void (*f)(String) ){
    if( millis() >= (_millisPast + _figurePeriod) ){
      (*f)("BANG");
      _millisPast=millis();
    }
  }
