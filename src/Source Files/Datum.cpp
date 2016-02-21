#include "..\\Header Files\Datum.h"

/*
* @author Marcus Plutowski, Arushi Rai
*/
Datum::Datum()
{
    // Use null protocol rather than this or check for empty protocol
    data = "";
    targetName = "";
    protocolTransited = "";
}

Datum::Datum(std::string initData, std::string target, std::string protocol){
	data = initData;
	targetName = target;
	protocolTransited = protocol;

std::string Datum::getTarget() { return targetName; }

void Datum::timeStamp(Timer* timer) { timestamps.push_back(timer->getTime()); }
Timer::milliseconds Datum::getTimeStamp(int num) { return timestamps[num]; }

std::string Datum::getSendable(){
	std::string sendable; 
	sendable = protocolTransited;
	sendable += "; "; //seperation characters
	sendable += data;

	if (protocolTransited[0] == 'T') {
		//enter TCP data string format
	}

	return sendable;
}

void Datum::setData(std::string newData) { data = newData; }
std::string Datum::getData() { return data; }

void Datum::setProtocol(std::string newProtocol) { protocolTransited = newProtocol; }
std::string Datum::getProtocol() { return protocolTransited; }
