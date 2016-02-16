#include "..\\Header Files\Buffer.h"

Buffer::Buffer(std::int identifer, unsigned short initSize){
	this->identifier = identifier;
	size = initSize;
	
}

std::string Buffer::getIdentifier(){
	return identifier;
}
void Buffer::setIdentifier(std::string identifier){
	this->identifier = identifier;
}

void Buffer::push(T newData){
	if(size = 0){return;}

	while(data.getSize() = size){
		this->pop();
	}
	data.push(newData);	
}
T Buffer::pop(){
	if(!data.empty()){
		T buff;
		buff = data.front()
		data.pop();
		return buff;
	}
}
T Buffer::get(){
	if(!data.empty()){
		return data.front();
	}
}

void Buffer::resize(unsigned short newSize){
	data.resize(newSize);
}
unsigned short getSize(){
	return size;
}
