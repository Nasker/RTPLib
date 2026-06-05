/*
    RTPEventNote.h - RTPEventNote, Simple state/note/velocity object
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 30, 2015.
*/


#include "Arduino.h"
#include "RTPEventNote.h"

RTPEventNote::RTPEventNote(bool state, uint8_t note){
	_state = state;
	_note = note;
	_velocity = 100;
	_read = 0;
}

RTPEventNote::RTPEventNote(bool state, uint8_t note, uint8_t velocity){
	_state = state;
	_note = note;
	_velocity = velocity;
	_read = 0;
}

bool RTPEventNote::eventState(){
	return _state;
}

uint8_t RTPEventNote::getEventNote(){
	return _note;
}

int RTPEventNote::getEventRead(){
	return _read;
}

uint8_t RTPEventNote::getEventVelocity(){
	return _velocity;
}

void RTPEventNote::setEventState(bool state){
	_state = state;
}

void RTPEventNote::setEventNote(uint8_t note){
	_note = note;
}

void RTPEventNote::setEventRead(int read){
	_read = read;
}

void RTPEventNote::setEventVelocity(uint8_t velocity){
	_velocity = velocity;
}

void RTPEventNote::switchState(){
	_state = !_state;
}

