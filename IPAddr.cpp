#include "IPAddr.h"
#include <sstream>
#include <algorithm>

IPAddr::IPAddr(int blockA, int blockB, int blockC, int blockD){
	this->setAddr(blockA, blockB, blockC, blockD);	
}
IPAddr::IPAddr(string address){
	this->setAddr(address);
}

void IPAddr::setAddr(int blockA, int blockB, int blockC, int blockD){
	address[0] = blockA;
	address[1] = blockB;
	address[2] = blockC;
	address[3] = blockD;
}
void IPAddr::setAddr(string addressString){
	std::string buf = "";
	
	for(int i = 0; i < 4; i++){
		for(int x = 0; x < 3; x++){
			buf+=addressString[i+3*x];	
		}
		address[i] = std::stoi(buf);
		buf = "";
	}
}

string IPAddr::getIPString(){

	std::string output = "";

	for(int i = 0; i < 4; i++){
		if(this->getBlock(i) < 10){output+="0";}
		if(this->getBlock(i) < 100){output+="0";}
		std::to_string(this->getBlock(i));
	}

	return output;
	
}
int IPAddr::getBlock(int blockNo){
	return address[std::min(3, std::max(blockNo, 0))];	
}


