#ifndef IRARRAY_H
#define IRARRAY_H
#include "Arduino.h"
class IRArray{
	public:
	
	IRArray(int portA, int portB, int portC, int portD){
		sensors[0] = portA;
		sensors[1] = portB;
		sensors[2] = portC;
		sensors[3] = portD;
		for(int i = 0; i != SENSOR_COUNT; i++){
			pinMode(sensors[i], INPUT);
		}
	}
	int getDistances(){
		return distances;
	}
	void readSensors(){
		distances = 0;
		for(int i = 0; i != SENSOR_COUNT; i++){
				distances |= ((digitalRead(sensors[i]) == LOW) << i);
		}
	}
	
	private:
		int sensors[4];
		int distances;
		static constexpr int SENSOR_COUNT = 4;
};
#endif