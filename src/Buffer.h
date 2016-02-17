#ifndef __INTERCHANGE_BUFFER_H
#define __INTERCHANGE_BUFFER_H

#include <queue>
#include <string>

template<class T>
class Buffer{
public:
	Buffer(std::string identifier, unsigned short initSize);

	std::string getIdentifier();
	void setIdentifier(std::string identifier);

	void push(T newData);
	T pop();
	T get();

	void resize(unsigned short newSize);
	unsigned short getSize();

private:
	std::string identifier;
	std::deque<T> data;
	unsigned short size;
};

#endif //__INTERCHANGE_BUFFER_H
