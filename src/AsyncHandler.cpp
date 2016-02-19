#include "AsynchHandler.h"
#include <pair>

/*
*@author Marcus Plutowski
*/
AsynchHandler::AsynchHandler(IPAddr targetAddress, Timer* timer)
{
    daemonTickPeriod = 20;
    protocolTickPeriod = 10;
    this->target = targetAddress;
    this->timer = timer;

    lastProtocolTick = timer.getTime();
    lastDaemonTick = timer.getTime();

    pthread_create(&clock, NULL, &regulateHandler, NULL);
}
AsynchHandler::AsynchHandler(IPAddr targetAddress, Timer* timer, Timer::milliseconds daemonTickPeriod, Timer::milliseconds protocolTickPeriod){
    this->daemonTickPeriod = daemonTickPeriod;
    this->protocolTickPeriod = protocolTickPeriod;
    this->target = targetAddress;
    this->timer = timer;

    lastProtocolTick = timer.getTime();
    lastDaemonTick = timer.getTime();

    pthread_create(&clock, NULL, &regulateHandler, NULL);
}
AsynchHandler::~AsynchHandler()
{
    
}

void AsynchHandler::addDaemon(Daemon* newDaemon) override
{
    Daemons.insert( std::pair< std::string, Daemon* >(newDaemon->getName(), newDaemon);
}
void AsynchHandler::removeDaemon(std::string name) override
{
    Daemons.erase(name);
}

void AsynchHandler::addProtocol(Protocol* newProtocol) override
{
    Protocols.insert(std::pair< std::string, Protocol* >(newProtocol->getName(), newProtocol);
}
void AsynchHandler::removeProtocol(std::string name) override
{
    Daemons.erase(name);
}

void AsynchHandler::stageData(Datum data, std::string protocolName)
{
    
}
void AsynchHandler::retData(Datum data, std::string protocolName)
{
}

void* AsynchHandler::regulateHandler(void* arg)
{
    while (true) {
	if((timer.getTime() - lastDaemonTick) >= daemonTickRate){
       	    this->tickDaemons();
        }
        if((timer.getTime() - lastProtocolTick) >= protocolTickRate){
            this->tickProtocols();
        }
    }
}
void AsynchHandler::tickDaemons()
{
    for (Daemon* daemon : Daemons) {
        daemon->pullData();
        /* TODO FINISH REGULATION */
    }
}
void AsynchHandler::tickProtocols()
{
    for (Protocol* protocol : Protocol) {
        protocol->pullData();
        /* TODO IMPLEMENT Protocol::fetchData() & FINISH REGULATION */
    }
}
