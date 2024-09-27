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

const int chordStep[N_CHORDS][N_STEPS] = {
    {0, 12, -12, 24},        // Monophonic
    {0, 4, 7, 12, -12, 16, 19}, // Major
    {0, 3, 7, 12, -12, 15, 19}, // Minor
    {0, 4, 7, 11, -12, 16, 19}, // Major 7th
    {0, 3, 7, 10, -12, 15, 19}, // Minor 7th
    {0, 4, 7, 10, -12, 16, 19}, // Dominant 7th
    {0, 3, 6, 12, -12, 15, 18}, // Diminished
    {0, 3, 6, 9, 12, -12, 15, 18}, // Diminished 7th
    {0, 3, 6, 10, 12, -12, 15, 18}, // Half Diminished 7th
    {0, 4, 8, 12, -12, 16, 20}, // Augmented
    {0, 4, 7, 10, 14, 12, -12}, // Major 9th
    {0, 3, 7, 10, 14, 12, -12}, // Minor 9th
    {0, 4, 7, 10, 14, 12, -12}, // Dominant 9th
    {0, 5, 7, 12, -12, 24, 17, 19}, // Suspended 4th
    {0, 2, 7, 12, -12, 24, 17, 19}, // Suspended 2th
    {0, 4, 7, 9, 12, -12, 16, 19}  // Sixth
};

const int arpChordStep[N_CHORDS][N_STEPS] = {
    {0},        // Monophonic
    {0, 4, 7},  // Major
    {0, 3, 7},  // Minor
    {0, 4, 7, 11}, // Major 7th
    {0, 3, 7, 10}, // Minor 7th
    {0, 4, 7, 10}, // Dominant 7th
    {0, 3, 6},  // Diminished
    {0, 3, 6, 9},  // Diminished 7th
    {0, 3, 6, 10}, // Half Diminished 7th
    {0, 4, 8},  // Augmented
    {0, 4, 7, 10, 14}, // Major 9th
    {0, 3, 7, 10, 14}, // Minor 9th
    {0, 4, 7, 10, 14}, // Dominant 9th
    {0, 5, 7},  // Suspended 4th
    {0, 2, 7},  // Suspended 2th
    {0, 4, 7, 9}  // Sixth
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