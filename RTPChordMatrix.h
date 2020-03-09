/*
	RTPChordMatrix.h - Class to create and manage a matrix of Chords
	Created by Oscar Martínez Carmona @ RockinTechProjects, May 10, 2014.
  	Modified in October 4, 2019.
*/

#ifndef RTPChordMatrix_h
#define RTPChordMatrix_h  

#define N_CHORDS 16
#define N_STEPS 8

#include "Arduino.h" 

   const int chordStep[N_CHORDS][N_STEPS]={
      {0,12,-12,24},  //Monophonic
      {0,12,-12,24}, //Octave
      {0,7,12,-12,19},   //PowerChord
      {0,4,7,12,-12,16,19},  //Major
      {0,3,7,12,-12,15,19},  //Minor
      {0,4,7,11,-12,16,19},  //Major 7th
      {0,3,7,10,-12,15,19},  //Minor 7th
      {0,4,7,10,-12,16,19},  //Dominant 7th
      {0,3,6,12,-12,15,18}, //Diminished
      {0,4,8,12,-12,16,20}, //Augmented
      {0,4,10,15,-12,16,22},  //Hendrixian
      {0,3,6,12,-12,15,18}, //Sus2
      {0,5,7,12,-12,24,17,19}, //Sus4 
      {0,4,8,12,-12,24,16,20},  //Dominant Ninth
      {0,3,8,12,-12,24,15,20},  //Dominant Ninth
      {0,6,10,16,21,26,-12,18} //Mystic
    };

    const int arpChordStep[N_CHORDS][N_STEPS]={
      {0},  //Monophonic
      {0,12}, //Octave
      {0,7},   //PowerChord
      {0,4,7},  //Major
      {0,3,7},  //Minor
      {0,4,7,11},  //Major 7th
      {0,3,7,10},  //Minor 7th
      {0,4,7,10},  //Dominant 7th
      {0,3,6}, //Diminished
      {0,4,8}, //Augmented
      {0,4,10},  //Hendrixian
      {0,3,6}, //Sus2
      {0,5,7}, //Sus4 
      {0,4,8},  //Dominant Ninth
      {0,3,8},  //Dominant Ninth
      {0,6,10} //Mystic
    };

class RTPChordMatrix{
  byte _chordType;
  byte _stepChord;
  byte _nSteps;
  byte _nArpSteps;
  byte _numberChords;

	public:                      
	RTPChordMatrix();         
    void setChordType(byte chordType);
    void setArpChordType(byte chordType);
    int getChordStep(byte step);
    byte getSteps();
    byte getChordSteps();
    byte getArpChordSteps();
    byte getChordType();
    byte getNumberChords();
};

#endif