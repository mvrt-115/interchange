#ifndef __INTERCHANGE_HANDLER_H
#define __INTERCHANGE_HANDLER_H

#include <vector>
#include "Datum.h"
#include "Daemon.h"
#include "Protocol.h"
#include "Timer.h"

/*
* @author Marcus Plutowski
*/
class Handler{
friend class Daemon;
friend class Protocol;

public:
	void addDaemon(Daemon* newDaemon);
	void removeDaemon(std::string name);
	
	void addProtocol(Protocol* newProtocol);
	void removeProtocol(std::string name);

	Daemon* getDaemon(std::string name);
	Protocol* getProtocol(std::string name);		
	
	Timer::milliseconds getTime();
protected:
	void stageData(Datum data, std::string protocolName);	
	void retData(Datum data, std::string protocolName)
	
	map<std::string, vector<std::string>> recieveBuffer;
	map<std::string, vector<Timer::Datum>> sendBuffer;

	IPAddr target;
};

#endif //__INTERCHANGE_HANDLER_H
