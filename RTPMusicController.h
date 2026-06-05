/*
	RTPMusicController.h - Controlador Musical per als projectes de RTP.
	Created by Oscar Martínez Carmona @ RockinTechProjects, May 8, 2014.
*/

#ifndef RTPMusicController_h
#define RTPMusicController_h   

#include "Arduino.h" 
#include "RTPDiatonicMatrix.h"
#include "RTPChordMatrix.h"

enum PART_TYPE{
        SCALE,
        FULL_CHORD,
        ARP_CHORD,
        DRUM
};

const char scaleName[14][16] ={"Chromatic","Ionian",
        "Dorian","Phrygian","Lydian","Mixolydian",
        "Aeolian","Locrian","Harmonic","Gipsy","Hawaian",
        "Blues","Japanese", "Drum"};

const char chordName[N_CHORDS][16] = {
    "mono", "Major", "minor", "Major7th", "minor7th", 
    "Dominant7th", "Diminished", "Diminished7th", 
    "HalfDim7th", "Augmented", "Major9th", "minor9th", 
    "Dominant9th", "Suspended4th", "Suspended2th", "Sixth"
};

const char rootName[12][4] = {"C","C#","D","D#",
	"E","F","F#","G","G#","A","A#","B"}; 

class RTPMusicController{ 	
	uint8_t _CNote;
	uint8_t _currentNote;
	uint8_t _lastNote;
	uint8_t _currentStep;
        uint8_t _currentScaleStep;
        uint8_t _currentChordStep;
        uint8_t _currentArpChordStep;
	uint8_t _currentRootNote;
	uint8_t _currentOctave;
        uint8_t _octaveOffset;
	uint8_t _currentScale;
	uint8_t _currentChord;
	uint8_t _lastChord;
	uint8_t _voices;
	uint8_t _numberOctaves;
	uint8_t _velocity;
	uint8_t _midiChannel;
	//String _rootName[12];
	//String _scaleName[13];

	public:        
	RTPDiatonicMatrix scales,chromatic;
	RTPChordMatrix chords;     
                
	RTPMusicController();  
		//setters...
	void setCurrentNote(uint8_t currentNote);  
	void setLastNote(uint8_t lastNote);
        void setCurrentRootNote(uint8_t currentRootNote);
        void setCurrentStep(uint8_t currentStep);
        void setCurrentScaleStep(uint8_t currentStep);
        void setCurrentChordStep(uint8_t currentStep);
        void setCurrentArpChordStep(uint8_t currentStep);
        void setCurrentOctave(uint8_t currentOctave);
        void setCurrentScale(uint8_t currentOctave);
        void setCurrentChord(uint8_t currentChord);
        void setLastChord(uint8_t lastChord);
        void setVoices(uint8_t voices);
        void setVelocity(uint8_t velocity);
        void setNumberOctaves(uint8_t numberOctaves);
        void setMidiChannel(uint8_t midiChannel); 
        void upOctave();
        void downOctave();      
        //getters...
        uint8_t getCurrentNote();  
        uint8_t getCurrentMidiNote();
        uint8_t getCurrentScaleMidiNote();
        uint8_t getCurrentChordMidiNote();
        uint8_t getCurrentArpChordMidiNote();
        uint8_t getLastNote() ;
        uint8_t getCurrentRootNote();
        uint8_t getCurrentScale();
        uint8_t getCurrentChord();
        uint8_t getLastChord() ;
        uint8_t getVoices();
        uint8_t getVelocity();
        uint8_t getCurrentOctave();
        uint8_t getOctaveOffset();
        uint8_t getNumberOctaves();  
        uint8_t getMidiChannel(); 
        String getCurrentRootNoteName();
        String getScaleName();
        String getChordName();
};

#endif