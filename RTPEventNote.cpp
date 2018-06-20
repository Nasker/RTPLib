/*
    RTPEventNote.h - RTPEventNote, Simple state/note/velocity object
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 30, 2015.
*/


#include "Arduino.h"
#include "RTPEventNote.h"

RTPEventNote::RTPEventNote(boolean _state, byte _note){
	state = _state;
	note = _note;
	velocity = 100;
	read = 0;
}

RTPEventNote::RTPEventNote(boolean _state, byte _note, byte _velocity){
	state = _state;
	note = _note;
	velocity = _velocity;
	read = 0;
}

boolean RTPEventNote::eventState(){
	return state;
}

byte RTPEventNote::getEventNote(){
	return note;
}

int RTPEventNote::getEventRead(){
	return read;
}

byte RTPEventNote::getEventVelocity(){
	return velocity;
}

void RTPEventNote::setEventState(boolean _state){
	state = _state;
}

void RTPEventNote::setEventNote(byte _note){
	note = _note;
}

void RTPEventNote::setEventRead(int _read){
	read = _read;
}

void RTPEventNote::setEventVelocity(byte _velocity){
	velocity = _velocity;
}

void RTPEventNote::switchState(){
	state = !state;
}

