#include <string>
#include <vector>
#include "Handler.h"

class Daemon{
public:
	Daemon(std::string uniqueName, Handler* parentHandler, int initRefreshRate); //uniqueName defines the Daemon for the Handler. refreshRate is in ms
	void sendData(std::string Data, std::string protocolName);
	std::string getData(string protocolName); //Retrieves the last data retrieved by the Daemon from said protocol
	std::string waitData(string protocolName); //Waits for new data from said protocol
	void setRefreshRate(int newRefreshRate);
	int getRefreshRate();
private:
	void pullData();
	std::map<std::string, std::string> lastRecieved;
	Handler* handler;
	
};

