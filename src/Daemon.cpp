#include "Daemon.h"

/*
* @author Marcus Plutowski
*/
Daemon::Daemon(std::string uniqueName, Handler* parentHandler, int initRefreshRate){
	name = uniqueName;
	handler = parentHandler;
	refreshRate = initRefreshRate;
} 

void Daemon::sendData(std::string data, std::string protocolName){
	data.setProtocol(protocolName);
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
	while(readStatus[protocolName] = Daemon::ReadStatus::Distant){}
	return Daemon::getData(protocolName);
}


std::void Daemon::pullData(){
	for(auto& protocolBuffer : handler->recieveBuffer){
		for(auto itr = protocolBuffer.begin(); itr != protocolBuffer.end(); ++itr){
			if(itr->getTarget() == name){
				this->readStatus[itr->getProtocol()] = Daemon::ReadStatus::Immediate;		
				this->lastRecieved[itr->getProtocol()] = *itr;
				protocolBuffer.erase(itr);
				break;
			}
			this->readStatus[protocolBuffer.begin()->getProtocol()] = max(Daemon::ReadStatus::Distant, this->readStatus[protocolBuffer.begin()->getProtocol()] - 1);
	}
}

