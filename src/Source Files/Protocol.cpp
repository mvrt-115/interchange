#include "..\\Header Files\Protocol.h"

/*
* @author Arushi Rai
*/

Protocol ::Protocol(int port) {
	name = " ";
	targetPort = port;
}

std::string Protocol::getName() {
	return name;
}
