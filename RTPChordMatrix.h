/*
	RTPChordMatrix.h - Class to create and manage a matrix of Chords
	Created by Oscar Martínez Carmona @ RockinTechProjects, May 10, 2014.
  	Modified in October 4, 2019.
*/

#ifndef RTPChordMatrix_h
#define RTPChordMatrix_h  

#define N_CHORDS 16
#define N_STEPS 6

#include "Arduino.h" 

   const byte chordStep[N_CHORDS][N_STEPS]={
      {0},  //Monophonic
      {0,12}, //Octave
      {0,7,12},   //PowerChord
      {0,4,7,12},  //Major
      {0,3,7,12},  //Minor
      {0,4,7,11},  //Major 7th
      {0,3,7,10},  //Minor 7th
      {0,4,7,10},  //Dominant 7th
      {0,3,6,12}, //Diminished
      {0,4,8,12}, //Augmented
      {0,4,10,15},  //Hendrixian
      {0,3,6,12}, //Sus2
      {0,5,7,12}, //Sus4
      {0,4,8,12},  //Dominant Ninth
      {0,6,10,16,21,26} //Mystic
    };

class RTPChordMatrix{

  byte _chordType;
  byte _stepChord;
  byte _nSteps;

	public:                      
	RTPChordMatrix();         
    void setChordType(byte chordType);
    byte getChordStep(byte step);
    byte getChordSteps();
    byte getChordType();
};

#endif