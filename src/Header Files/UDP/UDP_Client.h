#ifndef __INTERCHANGE_UDP_CLIENT_H
#define __INTERCHANGE_UDP_CLIENT_H

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

class UDP_Client {
private:
	char recipientAddr[32];
	queue <string> buffer; 
	int udp_socket;
	int PORT;
	struct sockaddr_in servaddr;

   	void setup();
   	void bindSocket(int s, struct sockaddr_in* myaddr);	
	void timestamp(string* data, bool add);
	bool validate(string data); //validates the buffer
	string empty(); //empties buffer 

public:
	UDP_Client();
	void send(); //sends the next item in the buffer,  empties it as well
	void addToSendBuffer(string message);
};

#endif