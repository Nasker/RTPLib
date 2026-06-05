/*
	RTPClickButton.h - Class for reading and managing a PushButton with click fancy shit.
	Created by Oscar Martínez Carmona @ RockinTechProjects, August 30, 2017.
*/

#ifndef RTPClickButton_h
#define RTPClickButton_h

#include "Arduino.h"

#define CLICKBTN_PULLUP HIGH

class RTPClickButton{
  public:
    RTPClickButton(uint8_t buttonPin);
    RTPClickButton(uint8_t buttonPin, bool active);
    RTPClickButton(uint8_t buttonPin, bool active, bool internalPullup);
    void Update();
    int clicks;                   // button click counts to return
    bool depressed;            // the currently debounced button (press) state (presumably it is not sad :)
    long debounceTime;
    long multiclickTime;
    long longClickTime;
    void callbackOnClicks( void (*userFunc)(String) );
    
  private:
    uint8_t _pin;                 // Arduino pin connected to the button
    bool _activeHigh;          // Type of button: Active-low = 0 or active-high = 1
    bool _btnState;            // Current appearant button state
    bool _lastState;           // previous button reading
    int _clickCount;              // Number of button clicks within multiclickTime milliseconds
    long _lastBounceTime;         // the last time the button input pin was toggled, due to noise or a press
};


#endif