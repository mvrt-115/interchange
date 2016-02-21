#ifndef _INTERCHANGE_PROTOCOL_H
#define _INTERCHANGE_PROTOCOL_H

#include "Handler.h"
#include <string>

/*
* @author Marcus Plutowski
*/

class Handler;

class Protocol {

public:
    Protocol(std::string name, void (*retData)(std::string), int port);

    virtual void setName(std::string newName) = 0;
    virtual std::string getName() = 0;

protected:
    std::string name;
    int targetPort;

    void pullData();
};

#endif
