#include "..\\Header Files\UDP_Protocol"

/*
* @author Arushi Rai
*/

UDP_Protocol::UDP_Protocol (int port) : Protocol(port){ 
	std::string address = " ";
	name = "UDP Protocol";
	address = new IPAddr(addr);
	client = new UDP_Client(address.getIPString(), port);
	server = new UDP_Server(address.getIPString(), port);
}

std::string UDP_Protocol::getName() {
	return name;
}

void UDP_Protocol::start() { } //will start thread to run client and server simultaniously

std::string UDP_Protocol::receive() {
	return server.empty();
}

void UDP_Protocol::send(string message) {
	client.addToSendBuffer(message);
}