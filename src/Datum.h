#ifndef __INTERCHANGE_DATUM_H
#define __INTERCHANGE_DATUM_H

#include <string>
#include "Timer.h"
#include <vector>

class Datum{
public:
	Datum(std::string initData, std::string target);

	void timeStamp(Timer* timer);
	Timer::chronon getTimeStamp(int num); 

	void setData(std::string newData);
	std::string getData();
	
	std::string getTarget();
private:
	std::string data;
	std::vector<Timer::chronon> timestamps;
	std::string targetName;
};


#endif
