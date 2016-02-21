#ifndef __INTERCHANGE_UDP_SERVER_H
#define __INTERCHANGE_UDP_SERVER_H

#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h> //used for fprintf
#include <netdb.h>

#include "..\Buffer.h"
#include "..\Datum.h"

#define BUFFER_SIZE 64;

using namespace std;

/*
* @author Arushi Rai
*/

class UDP_Server {
private:
	char recipientAddr[32];
	Buffer <Datum> buffer;

	int server_socket;
	int PORT;
	
	void start();	
	void timestamp(Datum* data, bool add);
	bool validate(string data); //validates the buffer
	struct sockaddr_in remaddr; // remote address 
	socklen_t addrlen; //length of addresses 
	
public:
	UDP_Server(string address, int port);
	void receive();
	string empty(); //empties buffer //use a more intuitive name
};
	
#endif