#include "Protocol.h"

class NullProtocol : Protocol{
public:
    NullProtocol(Handler* handler);
    void ProtocolFactory(std::string name, int port, Handler* handler) override;

    std::string getName() override;
private:
    void pullData() override;
};
