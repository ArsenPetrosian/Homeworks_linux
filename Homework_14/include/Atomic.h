#ifndef Atomic_is_defined
#define Atomic_is_defined

#include <pthread.h>

namespace my_atomic
{
    class AtomicInt
    {
    public:
        AtomicInt();
        AtomicInt(const AtomicInt &rhs) = delete;
        AtomicInt &operator=(const AtomicInt &rhs) = delete;
        void write(int value);
        int read() const;
        ~AtomicInt();

    private:
        int _value;
        pthread_mutex_t _mutex;
    };
}

#endif