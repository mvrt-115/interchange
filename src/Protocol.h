#ifndef _INTERCHANGE_PROTOCOL_H
#define _INTERCHANGE_PROTOCOL_H

#include "Handler.h"
#include <Boost/asio.hpp>
#include <string>

/*
* @author Marcus Plutowski
*/

class Handler;

class Protocol{

public:
	Protocol(std::string name, void (*retData) (std::string), int port);

	virtual void setName(std::string newName) = 0;
	virtual std::string getName() = 0;
protected:
	void (*retData) (std::string);
	boost::asio::io_service io_service;
	std::string name;
	int targetPort;
};

#endif

