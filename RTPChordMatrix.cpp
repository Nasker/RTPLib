
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
}

void RTPChordMatrix::setChordType(byte chordType){
    _chordType = chordType;
    if (_chordType==0) _nSteps = 1;
    else if(_chordType==1) _nSteps = 2;
    else if(_chordType==2) _nSteps = 3;
    else if(_chordType==15) _nSteps = 6;
    else _nSteps = 4;
}

byte RTPChordMatrix::getChordType(){
    return _chordType;
}

byte RTPChordMatrix::getChordStep(byte step){
    return chordStep[_chordType][step];
}

byte RTPChordMatrix::getChordSteps(){
    return _nSteps;
}
