#include "Daemon.h"

/*
* @author Marcus Plutowski
*/
Daemon::Daemon(std::string uniqueName, Handler* parentHandler, Timer* timer, int initRefreshRate){
	name = uniqueName;
	handler = parentHandler;
	refreshRate = initRefreshRate;
	clock = timer;
} 

void Daemon::sendData(std::string data, std::string protocolName){
	handler.stageData(data, protocolName);
}
	
void Daemon::setRefreshRate(unsigned int newRefreshRate){
	refreshRate = newRefreshRate;
}

unsigned int Daemon::getRefreshRate(){
	return refreshRate;
}


std::string Daemon::getData(string protocolName){
	return lastRecieved[protocolName];	
}
std::string Daemon::waitData(string protocolName){
	while(readStatus = Daemon::Distant){}
	return Daemon::getData(protocolName);
}


std::void Daemon::pullData(){
	for(auto& protocolBuffer : handler->recieveBuffer){
		for(auto itr = protocolBuffer.begin(); itr != protocolBuffer.end(); ++itr){
			if(itr->getTarget() == name){
				this->readStatus[itr->getProtocol()] = Immediate;		
				this->lastRecieved[itr->getProtocol()] = *itr;
				protocolBuffer.erase(itr);
				break;
			}
			this->readStatus[protocolBuffer.begin()->getProtocol()] = max(Distant, this->readStatus[protocolBuffer.begin()->getProtocol()] - 1);
	}
}

