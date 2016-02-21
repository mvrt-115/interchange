#ifndef _INTERCHANGE_PROTOCOL_H
#define _INTERCHANGE_PROTOCOL_H

#include "Handler.h"
#include <boost/asio.hpp>
#include <string>

/*
* @author Marcus Plutowski, Arushi Rai
*/

class Protocol{

public:
	Protocol(int port);
	std::string getName();
protected:
	boost::asio::io_service io_service;
	std::string name;
	int targetPort;

	virtual send(std::string data) = 0;
	virtual receive() = 0;
};

#endif
