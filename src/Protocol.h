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
	virtual Protocol(string name, void (*retData) (string), int port) = 0;

	virtual void setName(string newName) = 0;
	virtual string getName() = 0;
protected:
	void (*retData) (string);
	boost::asio::io_service io_service;
	string name;
	int targetPort;
};

#endif

