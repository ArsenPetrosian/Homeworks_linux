#include "MyVector.h"
#include <iostream>

my_vector::MyVector<int> vec;
void *pthr(void *p)
{
    vec.push_back(5);
    vec.push_back(6);
    vec.pop_back();
    std::cout << "From thread\n";
    vec.print();
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t p;
    pthread_create(&p, NULL, pthr, NULL);
    vec.push_back(1);
    vec.push_back(2);
    vec.print();
    vec.pop_back();
    vec.print();
    pthread_join(p, NULL);

    return 0;
}