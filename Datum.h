#ifndef __INTERCHANGE_DATUM_H
#define __INTERCHANGE_DATUM_H

#include <string>
#include "Timer.h"
#include <vector>

class Datum{
public:
	Datum(std::string initData);

	void timeStamp(Timer* timer);
	Timer::timestamp getTimeStamp(int num); 

	void setData(std::string newData);
	std::string getData();
private:
	std::string data;
	std::vector<timestamp> timestamps;
};


#endif
