#include "Datum.h"

Datum::Datum(std::string initData, std::string target){
	data = initData;
	targetName = target;
}

std::string Datum::getTarget(){
	return targetName;
}

void Datum::timeStamp(Timer* timer){
	timestamps.push_back(timer->getTime);	
}
Timer::chronon Datum::getTimeStamp(int num){
	return timestamps[num];
}

void Datum::setData(std::string newData){
	data = newData;
}
std::string Datum::getData(){
	return data;
}
