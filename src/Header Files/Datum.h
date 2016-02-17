#ifndef __INTERCHANGE_DATUM_H
#define __INTERCHANGE_DATUM_H

#include <string>
#include "Timer.h"
#include <vector>

/*
* @author Marcus Plutowski
*/

class Datum{
public:
	Datum(std::string initData, std::string target, std::string protocol);

	void timeStamp(Timer* timer);
	Timer::chronon getTimeStamp(int num); 

	void setData(std::string newData);
	std::string getData();
	std::string getSendable();
	
	std::string getTarget();
	
	void setProtocol(std::string protocolName);
	std::std getProtocol();
private:
	std::string data;
	std::vector<Timer::chronon> timestamps;
	
	std::string protocolTransited;
	std::string targetName;
};


#endif
