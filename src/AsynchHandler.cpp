#include "AsynchHandler.h"
#include <pair>

/*
*@author Marcus Plutowski
*/
AsynchHandler::AsynchHandler(IPAddr targetAddress, Timer* timer){
	
}
AsynchHandler::~AsynchHandler(){

}

void AsynchHandler::addDaemon(Daemon* newDaemon) override{
	Daemons.insert( std::pair< std::string, Daemon* >(newDaemon->getName(), newDaemon);
}
void AsynchHandler::removeDaemon(std::string name) override{
	Daemons.erase(name);
}

void AsynchHandler::addProtocol(Protocol* newProtocol) override{
	Protocols.insert( std::pair< std::string, Protocol* >(newProtocol->getName(), newProtocol);
}
void AsynchHandler::removeProtocol(std::string name) override{
	Daemons.erase(name);
}

void AsynchHandler::stageData(Datum data, std::string protocolName){

}
void AsynchHandler::retData(Datum data, std::string protocolName){

}

void AsynchHandler::regulateHandler(){
	while(true){
		this->tickDaemons();
		this->tickProtocols();
	}
}
void AsynchHandler::tickDaemons(){
	for(Daemon* daemon : Daemons){
		daemon->pullData();
		/* TODO FINISH REGULATION */
	} 
}
void AsynchHandler::tickProtocols(){
	for(Protocol* protocol : Protocol){
		/* TODO IMPLEMENT Protocol::fetchData() & FINISH REGULATION */
	}
}
