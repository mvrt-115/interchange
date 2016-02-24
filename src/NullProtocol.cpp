#include "NullProtocol.h"

NullProtocol::NullProtocol(Handler* handler){
    this->ProtocolFactory("", -1, handler);
}
void NullProtocol::ProtocolFactory(std::string name, int port, Handler* handler){
    this->port = port;
    this->name = name;
    this->handler = handler;
    handler->addProtocol(this);
}
void Daemon::pullData() {
    for(Handler::dataBuffer::iterator buff = handler->receiveBuffer.begin(); buff != handler->receiveBuffer.end(); buff++){
        for(std::vector<Datum>::iterator itr = (buff->second).begin(); itr != (buff->second).end(); itr++){
            if(itr->getTarget() == this->name){
                (buff->second).erase(itr);
            }
        }
    }
}
