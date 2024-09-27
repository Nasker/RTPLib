#include "RTPOptoEncoder.hpp"

RTPOptoEncoder::RTPOptoEncoder(uint8_t ID, uint8_t pin_left, uint8_t pin_right) {
    _ID = ID;
    _pin_left = pin_left;
    _pin_right = pin_right;
    pinMode(_pin_left, INPUT);
    pinMode(_pin_right, INPUT);
    _read();
    _state = IDLE;
}

void RTPOptoEncoder::callbackOnRotation(void (*userFunc)(uint8_t, bool)) {
    _read();
    if(!_changed())
        return;
    switch (_state) {
        case IDLE:
            if(_value_left  && !_value_right)
                _state = START_LEFT;
            else if(_value_right && !_value_left)
                _state = START_RIGHT;
            return;
        case START_LEFT:
            if(_value_right && _value_left)
                _state = ON_LEFT;
            else if(!_value_left && !_value_right)
                _state = IDLE;
            return;
        case ON_LEFT:
            if(_value_right && !_value_left)
                _state = END_LEFT;
            else if(_value_left && !_value_right)
                _state = START_LEFT;
            return;
        case END_LEFT:
            if(!_value_right && !_value_left){
                _state = IDLE;
                userFunc(_ID, TURN_LEFT);    //CALLBACK!!!!
            }  
            else if(_value_left && _value_right)
                _state = ON_LEFT;
            return;
        case START_RIGHT:
            if(_value_left && _value_right)
                _state = ON_RIGHT;
            else if(!_value_left && !_value_right)
                _state = IDLE;
            return;
        case ON_RIGHT:
            if(_value_left && !_value_right)
                _state = END_RIGHT;
            else if(!_value_left && _value_right)
                _state = START_RIGHT;
            return;
        case END_RIGHT:
            if(!_value_left && !_value_right) {
                _state = IDLE;
                userFunc(_ID, TURN_RIGHT);   //CALLBACK!!!!
            }
            else if(_value_left && _value_right)
                _state = ON_RIGHT;
            return;
    }
}

void RTPOptoEncoder::_read(){
    _previous_value_left = _value_left;
    _previous_value_right = _value_right;
    _value_left = !digitalRead(_pin_left);
    _value_right = digitalRead(_pin_right);
}

bool RTPOptoEncoder::_changed(){
    return (_value_left != _previous_value_left) || (_value_right != _previous_value_right);
}