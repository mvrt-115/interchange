#ifndef __INTERCHANGE_DAEMON_H
#define __INTERCHANGE_DAEMON_H

#include <string>
#include <vector>
#include "Handler.h"
#include "Timer.h"
#include "Datum.h"

/*
* @author Marcus Plutowski
*/
class Daemon{
friend class Handler;

public:
	Daemon(std::string uniqueName, Handler* parentHandler, int initRefreshRate); //uniqueName defines the Daemon for the Handler. refreshRate is in ms
	void sendData(Datum::Datum Data, std::string protocolName);
	
	std::string getData(string protocolName); //Retrieves the last data retrieved by the Daemon from said protocol
	std::string waitData(string protocolName); //Waits for new data from said protocol

	void setRefreshRate(unsigned int newRefreshRate);
	unsigned int getRefreshRate();
private:
	void pullData();
	
	std::map<std::string, Datum::Datum> lastRecieved;
	Handler* handler;
	std::string name;
	
	unsigned int refreshRate;
	
	enum class ReadStatus = {Immediate, Last, Distant}; 
	std::map<std::string, ReadStatus> readStatus;
};

#endif //__INTERCHANGE_DAEMON_H
