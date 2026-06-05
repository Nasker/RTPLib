/*
	RTPBatteryControl.h - Class for controlling the battery level
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 2, 2018.
*/

#ifndef RTPBatteryControl_h
#define RTPBatteryControl_h

#include "Arduino.h"
#include <RTPSmooth.h>

class RTPBatteryControl{
	int _batteryLevelInputPin;
	int _adcLevels;
	float _batteryLowLevelThreshold;
	float _powerSupplyThreshold;
	float _vccRead;
	bool _prevBatteryState;
	bool _lowBattery;
	bool _vccExternalSource;
	bool _prevLevelState;
	RTPSmooth adcAverage;
	
	public:
		RTPBatteryControl(int batteryLevelInputPin, int adcLevels);
		void setBatteryLowLevelThreshold(float batteryLowLevelThreshold);
		void setPowerSupplyThreshold(float powerSupplyThreshold);
		void monitorBatteryCallbacks(void (*f)(String,float));
		float getVoltageLevel();
		float getVoltageLevelFast();
		float getHueLevel();

	private:
		float calcVoltageLevel();
};

#endif