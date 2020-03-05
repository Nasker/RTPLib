/*
	RTPSmartRange.h - Classe de plantilla per a crear objectes de RTP.
	Created by Oscar Martínez Carmona @ RockinTechProjects, May 15, 2014.
*/

#ifndef RTPSmartRange_h
#define RTPSmartRange_h   

#include "Arduino.h" 
#define ANAL_MAX 1023.0

class RTPSmartRange{     
	int _id;
	float _normalizedRead;
	byte _numberZones;       
    byte _currentZone; 
    uint_fast16_t _numberStepsInZone;        
    uint_fast16_t _currentStepInZone;   
    uint_fast16_t _currentStep;
    uint_fast16_t _pastStep;
    float _rangeMaxim;
    float _rangeMinim;
	
	public:                
		RTPSmartRange(byte numberZones, byte numberStepsInZone); 
        RTPSmartRange(byte numberZones, byte numberStepsInZone, float rangeMaxim); 
        RTPSmartRange(int id, byte numberZones, uint_fast16_t numberStepsInZone, float rangeMinim, float rangeMaxim); 

        void setNumberZones(byte numberZones);  
        void setNumberStepsInZone(byte steps);

        void setBoundaries(int rangeMinim, int rangeMaxim);

        float calculateNormalisedRead(int actualRead);

        byte getCurrentZone(int inputRange); 
        byte getCurrentStepInZone(int inputRange);
        byte getCurrentStep(int inputRange);

        void stepChanged(void(*f)(int,String,int,int));    
        void stepInZoneChanged(void(*f)(int,String,int,int));  

        int rectFretBoardRead(int fretBoardRead);
};

#endif