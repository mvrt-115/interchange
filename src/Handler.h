#ifndef __INTERCHANGE_HANDLER_H
#define __INTERCHANGE_HANDLER_H

#include <vector>
#include "IPAddr.h"
#include "Datum.h"
#include "Daemon.h"
#include "Protocol.h"

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
	void retData(Datum data, std::string protocolName);

	std::map<std::string, std::vector<std::string> > recieveBuffer;
	std::map<std::string, std::vector<Datum::Datum> > sendBuffer;

	IPAddr target;
};

#endif //__INTERCHANGE_HANDLER_H
