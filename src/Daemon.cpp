#include "Daemon.h"
#include "Datum.h"
#include "Handler.h"

/*
* @author Marcus Plutowski
*/
Daemon::Daemon(std::string uniqueName, Handler* parentHandler,
    int initRefreshRate)
{
    name = uniqueName;
    handler = parentHandler;
    refreshRate = initRefreshRate;
}

void Daemon::sendData(Datum::Datum data, std::string protocolName)
{
    data.setProtocol(protocolName);
    handler->stageData(data, protocolName);
}

void Daemon::setRefreshRate(unsigned int newRefreshRate)
{
    refreshRate = newRefreshRate;
}

unsigned int Daemon::getRefreshRate() { return refreshRate; }

auto Daemon::getData(std::string protocolName)
{
    return lastReceived[protocolName];
}

auto Daemon::waitData(std::string protocolName)
{
    while (readStatus[protocolName] == Daemon::ReadStatus::Distant) {
    }
    return Daemon::getData(protocolName);
}

void Daemon::pullData()
{
    // TODO
}
