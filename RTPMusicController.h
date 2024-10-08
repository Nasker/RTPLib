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
	byte _CNote;
	byte _currentNote;
	byte _lastNote;
	byte _currentStep;
        byte _currentScaleStep;
        byte _currentChordStep;
        byte _currentArpChordStep;
	byte _currentRootNote;
	byte _currentOctave;
        byte _octaveOffset;
	byte _currentScale;
	byte _currentChord;
	byte _lastChord;
	byte _voices;
	byte _numberOctaves;
	byte _velocity;
	byte _midiChannel;
	//String _rootName[12];
	//String _scaleName[13];

	public:        
	RTPDiatonicMatrix scales,chromatic;
	RTPChordMatrix chords;     
                
	RTPMusicController();  
		//setters...
	void setCurrentNote(byte currentNote);  
	void setLastNote(byte lastNote);
        void setCurrentRootNote(byte currentRootNote);
        void setCurrentStep(byte currentStep);
        void setCurrentScaleStep(byte currentStep);
        void setCurrentChordStep(byte currentStep);
        void setCurrentArpChordStep(byte currentStep);
        void setCurrentOctave(byte currentOctave);
        void setCurrentScale(byte currentOctave);
        void setCurrentChord(byte currentChord);
        void setLastChord(byte lastChord);
        void setVoices(byte voices);
        void setVelocity(byte velocity);
        void setNumberOctaves(byte numberOctaves);
        void setMidiChannel(byte midiChannel); 
        void upOctave();
        void downOctave();      
        //getters...
        byte getCurrentNote();  
        byte getCurrentMidiNote();
        byte getCurrentScaleMidiNote();
        byte getCurrentChordMidiNote();
        byte getCurrentArpChordMidiNote();
        byte getLastNote() ;
        byte getCurrentRootNote();
        byte getCurrentScale();
        byte getCurrentChord();
        byte getLastChord() ;
        byte getVoices();
        byte getVelocity();
        byte getCurrentOctave();
        byte getOctaveOffset();
        byte getNumberOctaves();  
        byte getMidiChannel(); 
        String getCurrentRootNoteName();
        String getScaleName();
        String getChordName();
};

#endif