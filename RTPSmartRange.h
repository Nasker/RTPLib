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
	uint8_t _numberZones;       
    uint8_t _currentZone; 
    uint_fast16_t _numberStepsInZone;        
    uint_fast16_t _currentStepInZone;   
    uint_fast16_t _currentStep;
    uint_fast16_t _pastStep;
    float _rangeMaxim;
    float _rangeMinim;
	
	public:                
		RTPSmartRange(uint8_t numberZones, uint8_t numberStepsInZone); 
        RTPSmartRange(uint8_t numberZones, uint8_t numberStepsInZone, float rangeMaxim); 
        RTPSmartRange(int id, uint8_t numberZones, uint_fast16_t numberStepsInZone, float rangeMinim, float rangeMaxim); 

        void setNumberZones(uint8_t numberZones);  
        void setNumberStepsInZone(uint8_t steps);

        void setBoundaries(int rangeMinim, int rangeMaxim);

        float calculateNormalisedRead(int actualRead);

        uint8_t getCurrentZone(int inputRange); 
        uint_fast16_t getCurrentStepInZone(int inputRange);
        uint_fast16_t getCurrentStep(int inputRange);

        void stepChanged(void(*f)(int,String,uint_fast16_t,int));    
        void stepInZoneChanged(void(*f)(int,String,uint_fast16_t,int));  

        int rectFretBoardRead(int fretBoardRead);
};

#endif