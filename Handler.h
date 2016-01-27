#ifndef _INTERCHANGE_HANDLER_H
#define _INTERCHANGE_HANDLER_H

#include <vector>
#include <string>
#include <map>
#include "Protocol.h"
#include "Daemon.h"
#include <Boost/asio.hpp>

class Handler{
public:
	Handler(Boost::asio::ip address targetAddress);

	void addDaemon(Daemon *newDaemon, std::string name);
	void removeDaemon(std::string name);

	void addProtocol(Protocol *newProtocol, std::string name);
	void removeProtocol(std::string name);

	Daemon getDaemon(std::string name); 	

	void protocolSend(std::string protocolName, std::string data);
private:
	
	map<std::string, *Protocol> Protocols;	
	map<std::string, *Daemon> Daemons;

	boost::asio::ip::address_v4 Target;

	vector<std::string> recieveBuffer;
 	vector<std::string> sendBuffer;
};

#endif
