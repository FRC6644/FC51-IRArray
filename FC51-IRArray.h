#ifndef IRARRAY_H
#define IRARRAY_H
#include "Arduino.h"
namespace FRC6644 {
	template <int N>
	class FC51_IRArray{
		public:
		FC51_IRArray(std::initializer_list<int> ports){
			std::initializer_list<int>::iterator it;
			auto list_pos = ports.begin();
			for(int i = 0; i != size; i++, list_pos++){
				sensors[i] = *list_pos;
				pinMode(sensors[i], INPUT);
			}
		}
		
		int getDistances(){
			return distances;
		}
		
		int getSize(){
			return size;
		}
		
		void readSensors(){
			distances = 0;
			for(int i = 0; i != size; i++){
					distances |= ((digitalRead(sensors[i]) == LOW) << i);
			}
		}
		void printFormattedIRData(FC51_IRArray array){
			int data = array.getDistances();
			for(int i = 0; i != array.getSize(); i++){
				int value = (data & (1 << i)) >> i;
				Serial.println("Sensor " + String(i) + " :" + " " + String(value));
			}
			Serial.println();
		}
		private:
			int sensors[N];
			int distances;
			const int size = N;
	};
	
};
#endif