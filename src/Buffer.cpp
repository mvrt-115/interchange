#include "Buffer.h"

template <class T>
Buffer<T>::Buffer(std::string identifer,
                  typename std::deque<T>::size_type initSize)
{
    this->identifier = identifier;
    data.resize(initSize);
}

template <class T>
std::string Buffer<T>::getIdentifier() { return identifier; }

template <class T>
void Buffer<T>::setIdentifier(std::string identifier)
{
    this->identifier = identifier;
}

template <class T>
void Buffer<T>::push(T newData)
{
    if (this->getMaxSize == 0) {
        return;
    }

    this->data.pop_front(); // Should remove enough
    this->data.push_back(newData);
}

template <class T>
T Buffer<T>::pop()
{
    if (!data.empty()) {
        T buff;
        buff = data.front();
        data.pop_front();
        return buff;
    }
}

template <class T>
T Buffer<T>::get()
{
    if (!data.empty()) {
        return data.front();
    }
}

template <class T>
void Buffer<T>::resize(typename std::deque<T>::size_type newSize)
{
    data.resize(newSize);
}

template <class T>
auto Buffer<T>::getMaxSize() { return data.max_size(); }

template <class T>
auto Buffer<T>::getSize() { return data.size(); }
