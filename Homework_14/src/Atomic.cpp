#include <stdexcept>
#include <string>

#include "Atomic.h"

my_atomic::AtomicInt::AtomicInt()
{
    _value = 0;
    if (pthread_mutex_init(&_mutex, NULL) != 0)
    {
        throw std::runtime_error("Unable to create a mutex!");
    }
}

void my_atomic::AtomicInt::write(int value)
{
    pthread_mutex_lock(&_mutex);
    _value = value;
    pthread_mutex_unlock(&_mutex);
}

int my_atomic::AtomicInt::read() const
{
    return _value;
}

my_atomic::AtomicInt::~AtomicInt()
{
    pthread_mutex_destroy(&_mutex); 
}