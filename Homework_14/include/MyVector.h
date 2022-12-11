#ifndef my_vector_is_defined
#define my_vector_is_defined

#include <iostream>
#include <Atomic.h>

namespace my_vector
{

    template <typename T>
    class MyVector
    {
    public:
        typedef size_t size_type;
        typedef T &reference_type;

        class iterator
        {
        private:
            T *_ptr;

        public:
            using value_type = T;
            using pointer = value_type *;
            using reference = value_type &;

            bool operator==(const iterator &other)
            {
                return _ptr == other._ptr;
            }
            bool operator!=(const iterator &other)
            {
                return _ptr != other._ptr;
            }

            reference operator*()
            {
                return *_ptr;
            }
            pointer operator->()
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
        void push_back(const T &value)
        {
            my_atomic::AtomicInt v;
            thread_push_back(value, (void*)&v);
        }

        void pop_back()
        {
            my_atomic::AtomicInt v;
            thread_pop_back((void*)&v);
        }

        void clear();

        //operator[] and at
        reference_type operator[](size_type indx) const
        {
            return _arr[indx];
        }

        reference_type at(size_type indx) const
        {
            if (indx >= _size)
                throw std::runtime_error("Out of range!\n");
            else
                return _arr[indx];
        }

        reference_type front()
        {
            return _arr[0];
        }

        reference_type back()
        {
            return _arr[_size - 1];
        }

        MyVector(size_type size)
        {
            T* arr = new T[size];
            for(size_type i = 0; i < size; ++i)
                arr[i] = 0;
            _arr = arr;
        }

        ~MyVector()
        {
            delete[] _arr;
            _arr = nullptr;
            _size = 0;
            _capacity = 0;
        }

    private:
        T *_arr;
        size_type _size;
        size_type _capacity;
        void thread_push_back(const T &value, void* input);
        void thread_pop_back(void* input);
    };
}

#endif