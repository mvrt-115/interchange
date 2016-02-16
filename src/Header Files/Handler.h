#ifndef __INTERCHANGE_HANDLER_H
#define __INTERCHANGE_HANDLER_H

#include <vector>
#include "Datum.h"

/*
* @author Marcus Plutowski
*/
class Handler{
public:
	void addDaemon(Daemon* newDaemon);
	void removeDaemon(std::string name);
	
	void addProtocol(Protocol* newProtocol);
	void removeProtocol(std::string name);

	Daemon* getDaemon(std::string name);
	Protocol* getProtocol(std::string name);		
protected:
	void stageData(Datum data);	
	void retData(Datum data)
	
};

#endif //__INTERCHANGE_HANDLER_H
