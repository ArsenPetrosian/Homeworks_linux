#include "MyVector.h"
#include "Atomic.h"

using namespace my_atomic;
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
void MyVector<T>::thread_push_back(const T &value, void* input)
{
    my_atomic::AtomicInt* v = reinterpret_cast<my_atomic::AtomicInt*>(input);
    if (size() == capacity())
    {
        reserve(2 * size() + 1);
    }
    _arr[_size++] = value;
}

template <typename T>
void MyVector<T>::thread_pop_back(void* input)
{
    my_atomic::AtomicInt* v = reinterpret_cast<my_atomic::AtomicInt*>(input);
    --_size;
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] _arr;
    _arr = nullptr;
}