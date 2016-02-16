#ifndef __INTERCHANGE_UDP_SERVER_H
#define __INTERCHANGE_UDP_SERVER_H

#include <string>
#include <queue>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h> //used for fprintf

using namespace std;

/*
* @author Arushi Rai
*/

class UDP_Server {
private:
	char recipientAddr[32];
	int server_socket;
	int PORT;
	queue <string> buffer;
	
	void start();	
	void timestamp(string* data, bool add);
	bool validate(string data); //validates the buffer

public:
	UDP_Server(string address, int port);
	void receive();
	string empty(); //empties buffer //use a more intuitive name
};

#endif