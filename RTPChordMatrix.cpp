/*	
  RTPChordMatrix.cpp - Class to create and manage a matrix of Chords
  Created by Oscar Martínez Carmona @ RockinTechProjects, May 10, 2014.
  Modified in October 4, 2019.
*/

#include "Arduino.h"
#include "RTPChordMatrix.h"

RTPChordMatrix::RTPChordMatrix(){
    _chordType = 0;
    _stepChord = 0;
    setChordType(_chordType);
    _numberChords = N_CHORDS;
}

void RTPChordMatrix::setChordType(byte chordType){
    _chordType = chordType;
    if(_chordType<=1) _nSteps = 4;
    else if(_chordType==2) _nSteps = 6;
    else if(_chordType<=12) _nSteps = 8;
    else _nSteps = 7;
}

void RTPChordMatrix::setArpChordType(byte chordType){
    _chordType = chordType;
    if(_chordType==0) _nArpSteps = 1;
    else if(_chordType<=2) _nArpSteps = 2;
    else if(_chordType > 4  && _chordType <= 4) _nArpSteps = 4;
    else _nArpSteps = 3;
}

byte RTPChordMatrix::getChordType(){
    return _chordType;
}

int RTPChordMatrix::getChordStep(byte step){
    return chordStep[_chordType][step];
}

int RTPChordMatrix::getArpChordStep(byte step){
    return arpChordStep[_chordType][step];
}

byte RTPChordMatrix::getChordSteps(){
    return _nSteps;
}

byte RTPChordMatrix::getArpChordSteps(){
    return _nArpSteps;
}

byte RTPChordMatrix::getNumberChords(){
    return _numberChords;
}