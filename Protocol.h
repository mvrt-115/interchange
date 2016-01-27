#ifndef _INTERCHANGE_PROTOCOL_H
#define _INTERCHANGE_PROTOCOL_H

#include "Handler.h"
#include <Boost/asio.hpp>
#include <string>

class Handler;

class Protocol{
public:
	Protocol(string name, void (*retData) (string), int port);
	virtual void sendData(string data) = 0;	
	void setName(string newName);
	string getName();
private:
	void (*retData) (string);
	boost::asio::io_service io_service;
	string name;
	int targetPort;
};

#endif

