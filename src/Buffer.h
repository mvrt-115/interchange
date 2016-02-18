#ifndef __INTERCHANGE_BUFFER_H
#define __INTERCHANGE_BUFFER_H

#include <deque>
#include <string>

template <class T>
class Buffer {
public:
    Buffer(std::string identifier, typename std::deque<T>::size_type initSize);

    std::string getIdentifier();
    void setIdentifier(std::string identifier);

    void push(T newData);
    T pop();
    T get();

    void resize(typename std::deque<T>::size_type newSize);
    auto getSize();
    auto getMaxSize();

private:
    std::string identifier;
    std::deque<T> data;
};

#endif //__INTERCHANGE_BUFFER_H
