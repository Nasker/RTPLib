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
      {0}, //Octave
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
      /*
      {"major", {4, 7}},
      {"minor", {3, 7}},
      {"diminished", {3, 6}},
      {"augmented", {4, 8}},
      {"major seventh", {4, 7, 11}},
      {"minor seventh", {3, 7, 10}},
      {"dominant seventh", {4, 7, 10}},
      {"half-diminished seventh", {3, 6, 10}},
      {"diminished seventh", {3, 6, 9}},
      {"augmented seventh", {4, 8, 10}},
      {"augmented major seventh", {4, 8, 11}},
      {"sixth", {4, 7, 9}},
      {"minor sixth", {3, 7, 9}},
      {"sixth ninth", {4, 7, 9, 14}},
      {"minor sixth ninth", {3, 7, 9, 13}}
      */
    };

  /*
  #include <algorithm>
#include <vector>

// Reorders the notes in the chord to minimize the distances and finger movements
// by reordering the notes in the chord to have the same order as in the last chord,
// starting with the closest note to the root note
std::vector<int> reorder_chord(std::vector<int> chord, std::vector<int> last_chord) {
  // Sort the notes in the chord in ascending order
  std::sort(chord.begin(), chord.end());

  // Find the note in the last chord that is closest to the root note in the current chord
  int root_note = chord[0];
  int closest_note = *std::min_element(last_chord.begin(), last_chord.end(), [root_note](int a, int b) {
    return abs(a - root_note) < abs(b - root_note);
  });

  // Reorder the notes in the chord to have the same order as in the last chord,
  // starting with the closest note to the root note
  std::vector<int> reordered_chord;
  for (int note : last_chord) {
    if (note == closest_note) {
      reordered_chord.insert(reordered_chord.end(), chord.begin(), chord.end());
    } else {
      reordered_chord.push_back(note);
    }
  }
  */

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
    int getArpChordStep(byte step);
    byte getChordType();
    byte getNumberChords();
};

#endif