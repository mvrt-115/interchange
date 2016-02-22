#ifndef __INTERCHANGE_ASYNCH_HANDLER_H
#define __INTERCHANGE_ASYNCH_HANDLER_H

#include "Handler.h"

#include <vector>
#include <string>
#include <map>
#include "IPAddr.h"

#include <pthread.h>

/*
* @author Marcus Plutowski
*/

class AsyncHandler : public Handler {
public:
    AsyncHandler(IPAddr targetAddress, Timer* timer);
    AsyncHandler(IPAddr targetAddress, Timer* timer, Timer::milliseconds daemonTickPeriod, Timer::milliseconds protocolTickPeriod);
    void addDaemon(Daemon* newDaemon);
    void removeDaemon(std::string name);

    void addProtocol(Protocol* newProtocol);
    void removeProtocol(std::string name);

    Daemon* getDaemon(std::string name);
    Protocol* getProtocol(std::string name);

private:
    void stageData(Datum data, std::string protocolName);
    void retData(Datum data, std::string protocolName);

    std::map<std::string, Protocol*> Protocols;
    std::map<std::string, Daemon*> Daemons;

    Timer* timer;
    pthread_t clock;


    Timer::milliseconds lastProtocolTick;
    Timer::milliseconds lastDaemonTick;
    Timer::milliseconds protocolTickPeriod;
    Timer::milliseconds daemonTickPeriod;


    void regulateHandler();
    static void* threadedExecutor(void* targetClass);
    void tickDaemons();
    void tickProtocols();

    bool runHandler;
};

#endif //__INTERCHANGE_ASYNCH_HANDLER_H
