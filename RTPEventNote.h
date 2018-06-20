/*
    RTPEventNote.h - RTPEventNote, Simple state/note/velocity object
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 30, 2015.
*/

#ifndef RTPEventNote_h
#define RTPEventNote_h   
#include "Arduino.h" 

class RTPEventNote{
    boolean state;
    byte    note;
    int	read;
    byte 	velocity;

	public:
    RTPEventNote(boolean _state, byte _note);
    RTPEventNote(boolean _state, byte _note, byte _velocity);
    boolean eventState();
    byte getEventNote();
    int getEventRead();
    byte getEventVelocity();
    void setEventState(boolean _state);
    void setEventNote(byte _note);
    void setEventRead(int _read);
    void setEventVelocity(byte _velocity);
    void switchState();
};

#endif