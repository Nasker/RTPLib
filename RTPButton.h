/*
	RTPButton.h - Class for reading and managing a PushButton.
	Created by Oscar Martínez Carmona @ RockinTechProjects, February 4, 2014.
*/

#ifndef RTPButton_h
#define RTPButton_h

#include "Arduino.h"

#define NORMAL 0
#define PULLUP 1

class RTPButton{
	uint8_t _buttonInput;
	int _ID;
	bool _state;
	bool _prevState;
	int _coundGuardCycles;  
	int _countGuard;
	bool _shootGuard;
	unsigned int _holdCounter;
	int _mode;
	
	public:
		RTPButton(uint8_t buttonInput, int mode);
		RTPButton(uint8_t ID, uint8_t buttonInput, int mode);
		bool pressed();
		void callbackClick( void (*f)(String) );
		void callbackDeClick( void (*f)(String) );
		void callback(void (*f)(int,String));
		void callbackHold( void (*f)(String) );
		void setCountGuard(int countGuardCycles);

	private:
		void read();
};

#endif