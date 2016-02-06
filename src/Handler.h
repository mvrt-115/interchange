#ifndef __INTERCHANGE_HANDLER_H
#define __INTERCHANGE_HANDLER_H

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

class Handler{
friend class Daemon;
friend class Protocol;
public:
	Handler(IPAddr targetAddress, Timer* timer);

	void addDaemon(Daemon *newDaemon, std::string name);
	void removeDaemon(std::string name);

	void addProtocol(Protocol *newProtocol, std::string name);
	void removeProtocol(std::string name);

	Daemon getDaemon(std::string name); 	
	
	
private:
	void stageData(std::string data, std::string protocol);
	void sendData(std::string data);
	void retData(std::string data);

	map<std::string, *Protocol> Protocols;	
	map<std::string, *Daemon> Daemons;

	IPAddr target;
	
	map<std::string, vector<std::string>> recieveBuffer;
 	map<std::string, vector<Timer::Datum>> sendBuffer;
	
	Timer* ticker;
	pthread_t clock;

	void tickDaemons();
	void tickProtocols();
};

#endif //__INTERCHANGE_HANDLER_H
