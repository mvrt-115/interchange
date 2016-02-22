#include "AsyncHandler.h"
#include <utility>

/*
*@author Marcus Plutowski
*/
AsyncHandler::AsyncHandler(IPAddr targetAddress, Timer* timer)
{
    daemonTickPeriod = 20;
    protocolTickPeriod = 10;
    this->target = targetAddress;
    this->timer = timer;

    lastProtocolTick = timer->getTime();
    lastDaemonTick = timer->getTime();

    runHandler = true;
    pthread_create(&clock, NULL, &AsyncHandler::regulateHandler, NULL);
}
AsyncHandler::AsyncHandler(IPAddr targetAddress, Timer* timer, Timer::milliseconds daemonTickPeriod, Timer::milliseconds protocolTickPeriod)
{
    this->daemonTickPeriod = daemonTickPeriod;
    this->protocolTickPeriod = protocolTickPeriod;
    this->target = targetAddress;
    this->timer = timer;

    lastProtocolTick = timer->getTime();
    lastDaemonTick = timer->getTime();

    runHandler = true;
    pthread_create(&clock, NULL, &threadedExecutor, NULL);
}

void AsyncHandler::addDaemon(Daemon* newDaemon)
{
    Daemons.insert( std::pair< std::string, Daemon* >(newDaemon->getName(), newDaemon));
}
void AsyncHandler::removeDaemon(std::string name)
{
    Daemons.erase(name);
}

void AsyncHandler::addProtocol(Protocol* newProtocol)
{
    Protocols.insert(std::pair< std::string, Protocol* >(newProtocol->getName(), newProtocol));
}
void AsyncHandler::removeProtocol(std::string name)
{
    Daemons.erase(name);
}

void AsyncHandler::stageData(Datum data, std::string protocolName)
{
    receiveBuffer[protocolName].push_back(data);
}
void AsyncHandler::retData(Datum data, std::string protocolName)
{
    receiveBuffer[protocolName].push_back(data);
}

void* AsyncHandler::regulateHandler(void* arg)
{
    while (runHandler) {
        if ((timer->getTime() - lastDaemonTick) >= daemonTickPeriod) {
            this->tickDaemons();
        }
        if ((timer->getTime() - lastProtocolTick) >= protocolTickPeriod) {
            this->tickProtocols();
        }
    }
}
void AsyncHandler::tickDaemons()
{
    for (Daemon* daemon : Daemons) {
        daemon->pullData();
        /*TODO FINISH REGULATION */
    }
}
void AsyncHandler::tickProtocols()
{
    for (Protocol* protocol : Protocol) {
        protocol->pullData();
        /*TODO FINISH REGULATION */
    }
}
