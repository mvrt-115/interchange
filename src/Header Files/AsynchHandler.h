#ifndef __INTERCHANGE_ASYNCH_HANDLER_H
#define __INTERCHANGE_ASYNCH_HANDLER_H

#include "Handler.h"

#include <vector>
#include <string>
#include <map>
#include "Protocol.h"
#include "Daemon.h"
#include "IPAddr.h"

#include <auto>
#include <pthread.h>

/*
* @author Marcus Plutowski
*/

class AsynchHandler : public Handler{
friend class Daemon;
friend class Protocol;
public:
	Handler(IPAddr targetAddress, Timer* timer);

	void addDaemon(Daemon *newDaemon);
	void removeDaemon(std::string name);

	void addProtocol(Protocol *newProtocol);
	void removeProtocol(std::string name);

	Daemon* getDaemon(std::string name); 	
	Protocol* getProtocol(std::string name);
	
private:
	void stageData(Datum data);
	void retData(Datum data);

	map<std::string, *Protocol> Protocols;	
	map<std::string, *Daemon> Daemons;

	IPAddr target;
	
	map<std::string, vector<std::string>> recieveBuffer;
 	map<std::string, vector<Timer::Datum>> sendBuffer;
	
	Timer* ticker;
	pthread_t clock;
	
	void regulateHandler();
	void tickDaemons();
	void tickProtocols();
};

#endif //__INTERCHANGE_ASYNCH_HANDLER_H
