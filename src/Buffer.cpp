#include "Buffer.h"

template<class T>
Buffer<T>::Buffer(std::string identifer, unsigned short initSize){
	this->identifier = identifier;
	size = initSize;
	
}

template<class T>
std::string Buffer<T>::getIdentifier(){
	return identifier;
}

template<class T>
void Buffer<T>::setIdentifier(std::string identifier){
	this->identifier = identifier;
}

template<class T>
void Buffer<T>::push(T newData){
	if(size = 0){return;}

	while(data.getSize() = size){
		this->pop();
	}
	data.push(newData);	
}

template<class T>
T Buffer<T>::pop(){
	if(!data.empty()){
		T buff;
		buff = data.front();
		data.pop_back();
		return buff;
	}
}

template<class T>
T Buffer<T>::get(){
	if(!data.empty()){
		return data.front();
	}
}

template<class T>
void Buffer<T>::resize(unsigned short newSize){
	data.resize(newSize);
}

unsigned short getSize(){
	return size;
}
