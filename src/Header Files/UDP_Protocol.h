#ifndef __INTERCHANGE_UDP_PROTOCOL_H
#define __INTERCHANGE_UDP_PROTOCOL_H

#include "UDP\UDP_Client.h"
#include "UDP\UDP_Server.h"
#include "Protocol.h"
#include "IPAddr.h"

#include <string>
#include <Boost/asio.hpp>

/*
* @author Arushi Rai
*/

class UDP_Protocol :: public Protocol {
private:
	UDP_Server server; //make static?
	UDP_Client client; //make static?
	IPAddr address;
public:
	UDP_Protocol(std::string name, void (*retData) (std::string), int port);
	std::string getName();
	void start(); //will start thread to run client and server simultaniously
	std::string receive();
	void send(string message);
};

#endif