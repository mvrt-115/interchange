#ifndef _INTERCHANGE_HANDLER_H
#define _INTERCHANGE_HANDLER_H

#include <vector>
#include <string>
#include <map>
#include "Protocol.h"
#include "Daemon.h"
#include <Boost/asio.hpp>


/*
* @author Marcus Plutowski
*/

class Handler{
friend class Daemon;
friend class Protocol;
public:
	Handler(Boost::asio::ip address targetAddress);

	void addDaemon(Daemon *newDaemon, std::string name);
	void removeDaemon(std::string name);

	void addProtocol(Protocol *newProtocol, std::string name);
	void removeProtocol(std::string name);

	Daemon getDaemon(std::string name); 	
private:
	void sendData(string data);
	void retData(string data);

	map<std::string, *Protocol> Protocols;	
	map<std::string, *Daemon> Daemons;

	boost::asio::ip::address_v4 Target;

	map<std::string, vector<std::string>> recieveBuffer;
 	map<std::string, vector<std::string>> sendBuffer;
};

#endif
