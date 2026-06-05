/*
	RTPMusicController.cpp - Controlador Musical per als projectes de RTP.
	Created by Oscar Martínez Carmona @ RockinTechProjects, May 8, 2014.
*/

#include "Arduino.h"
#include "RTPMusicController.h"

RTPMusicController::RTPMusicController(){ 		//Constructor
	_CNote = 36;
	_currentNote = _CNote;
	_lastNote = _currentNote;
	_currentRootNote = _CNote;
	_currentOctave = 0;
	_octaveOffset = 0;
	_currentScale = 0;
	_currentChord = 0;
	_lastChord = _currentChord;
	_voices = 1;
	_numberOctaves = 2;
	_velocity = 100;
	_midiChannel = 0x90;
}

void RTPMusicController::setCurrentNote(uint8_t currentNote){
	_currentNote = currentNote;
}   

void RTPMusicController::setCurrentStep(uint8_t currentStep){
	_currentStep = currentStep;
}

void RTPMusicController::setCurrentScaleStep(uint8_t currentScaleStep){
	_currentScaleStep = currentScaleStep;
}

void RTPMusicController::setCurrentChordStep(uint8_t currentChordStep){
	_currentChordStep = currentChordStep;
}

void RTPMusicController::setCurrentArpChordStep(uint8_t currentArpChordStep){
	_currentArpChordStep = currentArpChordStep;
}

void RTPMusicController::setLastNote(uint8_t lastNote){
	_lastNote = lastNote;
} 

void RTPMusicController::setCurrentRootNote(uint8_t currentRootNote){
	_currentRootNote = _CNote + currentRootNote;
}
void RTPMusicController::setCurrentOctave(uint8_t currentOctave){
	_currentOctave = currentOctave;
}
void RTPMusicController::upOctave(){
	if(_octaveOffset < 5 ){
		_octaveOffset++;
	} 
}
void RTPMusicController::downOctave(){
	if(_octaveOffset > 0 ){
		_octaveOffset--;
	} 
}
void RTPMusicController::setCurrentScale(uint8_t currentScale){
	_currentScale = currentScale;
	scales.setTonality(_currentScale);
}
void RTPMusicController::setCurrentChord(uint8_t currentChord){
	_currentChord = currentChord;
	chords.setChordType(currentChord);
}
void RTPMusicController::setLastChord(uint8_t lastChord){
	_lastChord = lastChord;
} 
void RTPMusicController::setVoices(uint8_t voices){
	_voices = voices;
}
void RTPMusicController::setVelocity(uint8_t velocity){
	_velocity = velocity;
}
void RTPMusicController::setNumberOctaves(uint8_t numberOctaves){
	_numberOctaves = numberOctaves;
}
void RTPMusicController::setMidiChannel(uint8_t midiChannel){
	_midiChannel = midiChannel;
}       

uint8_t RTPMusicController::getCurrentMidiNote(){
	return _currentRootNote + scales.getScaleStep(_currentStep) + _currentOctave * 12 + _octaveOffset * 12; 
}

uint8_t RTPMusicController::getCurrentScaleMidiNote(){
	return _currentRootNote + scales.getScaleStep(_currentStep) + _currentOctave * 12 + _octaveOffset * 12; 
}

uint8_t RTPMusicController::getCurrentChordMidiNote(){
	return _currentRootNote + chords.getChordStep(_currentChordStep) + _currentOctave * 12 + _octaveOffset * 12; 
}

uint8_t RTPMusicController::getCurrentArpChordMidiNote(){
	return _currentRootNote + chords.getArpChordStep(_currentChordStep) + _currentOctave * 12 + _octaveOffset * 12; 
}

uint8_t RTPMusicController::getCurrentNote(){
	return _currentNote;
}   
uint8_t RTPMusicController::getLastNote(){
	return _lastNote;
} 

uint8_t RTPMusicController::getCurrentRootNote(){
	return _currentRootNote- _CNote;
}
uint8_t RTPMusicController::getCurrentScale(){
	return _currentScale;
}
uint8_t RTPMusicController::getCurrentChord(){
	return _currentChord;
}
uint8_t RTPMusicController::getLastChord(){
	return _lastChord;
} 
uint8_t RTPMusicController::getVoices(){
	return _voices;
}
uint8_t RTPMusicController::getVelocity(){
	return _velocity;
}
uint8_t RTPMusicController::getNumberOctaves(){
	return _numberOctaves;
}   
uint8_t RTPMusicController::getCurrentOctave(){
	return _currentOctave;
}   

uint8_t RTPMusicController::getOctaveOffset(){
	return _octaveOffset;
} 

uint8_t RTPMusicController::getMidiChannel(){
	return _midiChannel;
} 

String RTPMusicController::getCurrentRootNoteName(){
	uint8_t rootIndex = _currentRootNote - _CNote;
	return rootName[rootIndex];
}  

String RTPMusicController::getScaleName(){
	return scaleName[_currentScale];
} 

String RTPMusicController::getChordName(){
	return chordName[_currentChord];
} 