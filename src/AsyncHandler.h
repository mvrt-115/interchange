#ifndef __INTERCHANGE_ASYNCH_HANDLER_H
#define __INTERCHANGE_ASYNCH_HANDLER_H

#include "Handler.h"

#include <vector>
#include <string>
#include <map>
#include "IPAddr.h"

#include <auto>
#include <pthread.h>

/*
* @author Marcus Plutowski
*/

class AsyncHandler : public Handler {
public:
    AsynchHandler(IPAddr targetAddress, Timer* timer);
    AsynchHandler(IPAddr targetAddress, Timer* timer, Timer::milliseconds daemonTickPeriod, Timer::milliseconds protocolTickPeriod);
    void addDaemon(Daemon* newDaemon);
    void removeDaemon(std::string name);

    void addProtocol(Protocol* newProtocol);
    void removeProtocol(std::string name);

    Daemon* getDaemon(std::string name);
    Protocol* getProtocol(std::string name);

private:
    void stageData(Datum data);
    void retData(Datum data);

    map<std::string, *Protocol> Protocols;
    map<std::string, *Daemon> Daemons;

    Timer* timer;
    pthread_t clock;
    
    Timer::milliseconds lastProtocolTick;
    Timer::milliseconds lastDaemonTick;
    Timer::milliseconds protocolTickRate;
    Timer::milliseconds daemonTickRate;

    void *regulateHandler(void* arg);
    void tickDaemons();
    void tickProtocols();
    
    bool runHandler;
};

#endif //__INTERCHANGE_ASYNCH_HANDLER_H
