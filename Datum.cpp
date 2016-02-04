#include "Datum.h"

Datum::Datum(std::string initData){
	data = initData;
}

void Datum::timeStamp(Timer* timer){
	timestamps.push_back(timer.getTime);	
}
timestamp Datum::getTimeStamp(int num){
	return timestamps[num];
}

void Datum::setData(std::string newData){
	data = newData;
}
std::string Datum::getData(){
	return data;
}
