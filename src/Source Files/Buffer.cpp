#include "..\\Header Files\Buffer.h"

Buffer<T>::Buffer(std::int identifer, unsigned short initSize){
	this->identifier = identifier;
	size = initSize;
	
}

std::string Buffer<T>::getIdentifier(){
	return identifier;
}
void Buffer<T>::setIdentifier(std::string identifier){
	this->identifier = identifier;
}

void Buffer<T>::push(T newData){
	if(size == 0){return;} //using assignment operator, wrong

	while(data.getSize() == size){ //using assignment operator, wrong
		this->pop();
	}
	data.push(newData);	
}
T Buffer<T>::pop(){
	if(!data.empty()){
		T buff;
		buff = data.front()
		data.pop();
		return buff;
	}
}
T Buffer<T>::get(){
	if(!data.empty()){
		return data.front();
	}
}

void Buffer<T>::resize(unsigned short newSize){
	data.resize(newSize);
}

unsigned short Buffer<T>::getSize(){
	return size;
}
