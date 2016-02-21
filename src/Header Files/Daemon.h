#ifndef __INTERCHANGE_DAEMON_H
#define __INTERCHANGE_DAEMON_H

#include <boost/circular_buffer.hpp>
#include <string>
#include <functional>
#include <vector>
#include "Handler.h"
#include "Datum.h"

/*
* @author Marcus Plutowski
*/
class Handler;
class Daemon {
    friend class Handler;
public:
    Daemon(std::string uniqueName, Handler* parentHandler,
                            std::function<void(std::string)> useData); 
    // uniqueName defines the Daemon for the Handler.

    void sendData(std::string, std::string protocolName);
    void sendData(std::string, std::string protocolName,
                                     std::string target);
private:
    void pullData();

    std::function<void(std::tring)> useData;

    std::map<std::string, Datum::Datum> lastReceived;
    Handler* handler;
    std::string name;
};

#endif //__INTERCHANGE_DAEMON_H
