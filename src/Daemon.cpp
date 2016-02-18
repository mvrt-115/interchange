#include "Daemon.h"
#include "Datum.h"

/*
* @author Marcus Plutowski
*/
Daemon::Daemon(std::string uniqueName, Handler* parentHandler, int initRefreshRate){
	name = uniqueName;
	handler = parentHandler;
	refreshRate = initRefreshRate;
}

void Daemon::sendData(Datum::Datum data, std::string protocolName){
	data.setProtocol(protocolName);
	handler->stageData(data, protocolName);
}

void Daemon::setRefreshRate(unsigned int newRefreshRate){
	refreshRate = newRefreshRate;
}

unsigned int Daemon::getRefreshRate(){
	return refreshRate;
}

Daemon Daemon::getData(std::string protocolName){
	return lastRecieved[protocolName];
}

Daemon Daemon::waitData(std::string protocolName){
	while(readStatus[protocolName] == Daemon::ReadStatus::Distant){}
	return Daemon::getData(protocolName);
}


void Daemon::pullData(){
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
}

