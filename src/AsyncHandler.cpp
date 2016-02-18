#include "AsyncHandler.h"
#include <pair>

/*
*@author Marcus Plutowski
*/
AsyncHandler::AsyncHandler(IPAddr targetAddress, Timer* timer)
{
}
AsyncHandler::~AsyncHandler()
{
}

void AsyncHandler::addDaemon(Daemon* newDaemon) override
{
        Daemons.insert( std::pair< std::string, Daemon* >(newDaemon->getName(), newDaemon);
}
void AsyncHandler::removeDaemon(std::string name) override
{
    Daemons.erase(name);
}

void AsyncHandler::addProtocol(Protocol* newProtocol) override
{
        Protocols.insert( std::pair< std::string, Protocol* >(newProtocol->getName(), newProtocol);
}
void AsyncHandler::removeProtocol(std::string name) override
{
    Daemons.erase(name);
}

void AsyncHandler::stageData(Datum data, std::string protocolName)
{
}
void AsyncHandler::retData(Datum data, std::string protocolName)
{
}

void AsyncHandler::regulateHandler()
{
    while (true) {
        this->tickDaemons();
        this->tickProtocols();
    }
}
void AsyncHandler::tickDaemons()
{
    for (Daemon* daemon : Daemons) {
        daemon->pullData();
        /* TODO FINISH REGULATION */
    }
}
void AsyncHandler::tickProtocols()
{
    for (Protocol* protocol : Protocol) {
        /* TODO IMPLEMENT Protocol::fetchData() & FINISH REGULATION */
    }
}
