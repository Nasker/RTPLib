#pragma once

#include <Arduino.h>

enum RTPOptoEncoderState {
    IDLE,
    START_LEFT,
    ON_LEFT,
    END_LEFT,
    START_RIGHT,
    ON_RIGHT,
    END_RIGHT
};

enum RTPOptoEncoderDirection {
    TURN_LEFT,
    TURN_RIGHT
};

class RTPOptoEncoder {
public:
    RTPOptoEncoder(uint8_t ID, uint8_t pin_left, uint8_t pin_right);
    void callbackOnRotation(void (*userFunc)(uint8_t, bool));
private:
    uint8_t _ID;
    uint8_t _pin_left;
    uint8_t _pin_right;
    bool _previous_value_left;
    bool _previous_value_right;
    bool _value_left;
    bool _value_right;
    uint8_t _state;
    void _read();
    bool _changed();
};