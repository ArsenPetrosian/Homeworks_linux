#include "MyVector.h"

using namespace my_vector;

template <typename T>
bool MyVector<T>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template <typename T>
size_t MyVector<T>::size() const
{
    return _size;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
void MyVector<T>::push_back(const T &value)
{
    lock();
    resize();
    _arr[_size++] = value;
    unlock();
}

template <typename T>
void MyVector<T>::pop_back()
{
    lock();
    if (_size == 0)
        throw std::runtime_error("Vector is empty!\n");
    else
        --_size;
    unlock();
}

template <typename T>
void MyVector<T>::clear()
{
    lock();
    _size = 0;
    unlock();
}

template <typename T>
T &MyVector<T>::operator[](size_t indx) const
{
    return _arr[indx];
}

template <typename T>
T &MyVector<T>::front()
{
    return at(0);
}

template <typename T>
T &MyVector<T>::back()
{
    return at(_size - 1);
}

template <typename T>
T &MyVector<T>::at(size_t indx) const
{
    if (indx >= _size)
        throw std::runtime_error("Out of range!\n");
    else
        return _arr[indx];
}

template <typename T>
void MyVector<T>::print()
{
    for (int i = 0; i < _size; ++i)
        std::cout << _arr[i] << ' ';
    std::cout << '\n';
}