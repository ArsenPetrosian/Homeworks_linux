#include <cstddef>
#include <iostream>
#include <pthread.h>
#include <stdexcept>

#ifndef my_vector_is_defined
#define my_vector_is_defined

namespace my_vector
{
    template <typename T>
    class MyVector
    {
    public:
        MyVector(const MyVector &rhs) = delete;
        MyVector &operator=(const MyVector &rhs) = delete;

        class iterator
        {
        private:
            T *_ptr;

        public:
            bool operator==(const iterator &other)
            {
                return _ptr == other._ptr;
            }
            bool operator!=(const iterator &other)
            {
                return _ptr != other._ptr;
            }

            T &operator*()
            {
                return *_ptr;
            }
            T *operator->()
            {
                return _ptr;
            }
            iterator &operator++() // prefix
            {
                ++_ptr;
                return *this;
            }
            iterator operator++(int x) // postfix
            {
                iterator it = *this;
                ++_ptr;
                return it;
            }
            iterator &operator--() // prefix
            {
                --_ptr;
                return *this;
            }
            iterator operator--(int x) // postfix
            {
                iterator it = *this;
                --_ptr;
                return it;
            }
            iterator operator+=(iterator &other)
            {
                _ptr += other;
                return *this;
            }
            iterator operator-=(iterator &other)
            {
                _ptr -= other;
                return *this;
            }
            iterator operator+(iterator &other)
            {
                _ptr += other;
                return *this;
            }
            iterator operator-(iterator &other)
            {
                _ptr -= other;
                return *this;
            }
            iterator operator<(const iterator &other)
            {
                return _ptr < other._ptr;
            }
            iterator operator>(const iterator &other)
            {
                return _ptr > other._ptr;
            }
            iterator operator<=(const iterator &other)
            {
                return _ptr <= other._ptr;
            }
            iterator operator>=(const iterator &other)
            {
                return _ptr >= other._ptr;
            }
        };

        // begin, end
        iterator begin()
        {
            return iterator(_arr[0]);
        }
        iterator end()
        {
            return iterator(++_arr[size - 1]);
        }

        // Capacity
        bool empty() const;
        size_t size() const;
        size_t capacity() const;

        // Modifiers
        void push_back(const T &value);
        void pop_back();
        void clear();

        // operator[], at, front, back
        T &operator[](size_t indx) const;
        T &front();
        T &back();
        T &at(size_t indx) const;

        void print();

        MyVector()
        {
            _size = 0;
            _capacity = 8;
            _arr = new T[_capacity];
            if (pthread_mutex_init(&_guard, NULL) != 0)
                throw std::runtime_error("Unable to initialize the guard\n");
        }

        ~MyVector()
        {
            delete[] _arr;
            pthread_mutex_destroy(&_guard);
        }

    private:
        T *_arr;
        size_t _size;
        size_t _capacity;
        pthread_mutex_t _guard;

        void lock()
        {
            pthread_mutex_lock(&_guard);
        }
        void unlock()
        {
            pthread_mutex_unlock(&_guard);
        }
        void resize()
        {
            if (_size < _capacity)
                return;
            T *new_arr = new T[_capacity *= 2];

            for (int i = 0; i < _size; ++i)
                new_arr[i] = _arr[i];

            delete[] _arr;
            _arr = new_arr;
        }
    };
}

#endif