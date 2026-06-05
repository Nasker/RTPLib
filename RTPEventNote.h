/*
    RTPEventNote.h - RTPEventNote, Simple state/note/velocity object
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 30, 2015.
*/

#ifndef RTPEventNote_h
#define RTPEventNote_h   
#include "Arduino.h" 

class RTPEventNote{
    bool _state;
    uint8_t    _note;
    int	    _read;
    uint8_t 	_velocity;

	public:
    RTPEventNote(bool state, uint8_t note);
    RTPEventNote(bool state, uint8_t note, uint8_t velocity);
    bool eventState();
    uint8_t getEventNote();
    int getEventRead();
    uint8_t getEventVelocity();
    void setEventState(bool state);
    void setEventNote(uint8_t note);
    void setEventRead(int read);
    void setEventVelocity(uint8_t velocity);
    void switchState();
};

#endif