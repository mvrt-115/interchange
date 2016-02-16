#ifndef _INTERCHANGE_PROTOCOL_H
#define _INTERCHANGE_PROTOCOL_H

#include "Handler.h"
#include <Boost/asio.hpp>
#include <string>

/*
* @author Marcus Plutowski
*/

class Protocol{

public:
	Protocol(int port);
	std::string getName();
protected:
	//void (*retData) (std::string);
	boost::asio::io_service io_service;
	std::string name;
	int targetPort;
};

#endif

