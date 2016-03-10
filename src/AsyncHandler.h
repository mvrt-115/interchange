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
    ~AsyncHandler();

    void regulateHandler();
protected:

    Timer* timer;
    pthread_t clock;


    Timer::milliseconds lastProtocolTick;
    Timer::milliseconds lastDaemonTick;
    Timer::milliseconds protocolTickPeriod;
    Timer::milliseconds daemonTickPeriod;


    static void* threadedExecutor(void* targetClass);
    void tickDaemons();
    void tickProtocols();

    bool runHandler;
};

#endif //__INTERCHANGE_ASYNCH_HANDLER_H
