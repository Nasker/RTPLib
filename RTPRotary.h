/*
	RTPRotary.h - Class for reading and managing a Rotary Encoder.
	Created by Oscar Martínez Carmona @ RockinTechProjects, September 18 2018.
*/

#pragma once

#include "Arduino.h"
#include <Encoder.h>

#define QUADRATURE 0
#define SINGLE 1

#define UP 0
#define DOWN 1

class RTPRotary: public Encoder{
    long _oldPosition  = -999;
    int _ID;
    int _type = 0;
    int _divider = 4;
  public:
    RTPRotary(int ID, int leftRotPin, int rightRotPin):Encoder(leftRotPin,rightRotPin){
    	_ID = ID;
    };
    RTPRotary(int ID, int leftRotPin, int rightRotPin, int type):Encoder(leftRotPin,rightRotPin){
    	_ID = ID;
    	_type = type;
    	if(_type == SINGLE)
    		_divider = 2;
    };
    void callbackOnRotation( void (*userFunc)(int,String,int,int) );
    void callbackOnRotation( void (*userFunc)(int,int,int,int) );
  };