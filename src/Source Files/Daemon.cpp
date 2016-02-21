#include "..\\Header Files\Daemon.h"

#include "Daemon.h"
#include "Datum.h"
#include "Handler.h"

/*
* @author Marcus Plutowski
*/
Daemon::Daemon(std::string uniqueName, Handler* parentHandler,
    void (*useData)(std::string)) {
    name = uniqueName;
    handler = parentHandler;
    refreshRate = initRefreshRate;
}

void Daemon::sendData(std::string data, std::string protocolName) {
    Datum data(data, this->name, protocolName);
    handler->stageData(&datum, protocolName);
}
void Daemon::sendData(std::string data, std::string protocolName, std::string target) {
    Datum data(data, target, protocolName);
    handler->stageData(&datum, protocolName);
}

void Daemon::pullData() {
    for(auto buff : handler->recieveBuffer){
        for(auto itr : buff.second){
            if(itr->getTarget() == this->name){
                useData(itr->getData());
                (buff.second).erase(itr);
            }
    }
}
