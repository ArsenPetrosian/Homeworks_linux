#include <iostream>
#include <cmath>
#include "Polinomial.h"

using namespace _Polinomial;

Polinomial::Polinomial()
{
    _size = 0;
    std::vector<int> vec(0);
    _coefs = vec;
    _degrees = vec;
}

std::vector<int> Polinomial::get_coefs()
{
    return _coefs;
}

std::vector<int> Polinomial::get_degrees()
{
    return _degrees;
}

size_t Polinomial::size()
{
   return _size;
}

void Polinomial::add(int coef, int degree)
{
   ++_size;
   _coefs.push_back(coef);
   _degrees.push_back(degree);
}

void Polinomial::print() const
{
   for(size_t i = 0; i < _size; ++i)
   {
      if (_coefs[i] == 1)
         std::cout << "x^" << _degrees[i];
      else if(_coefs[i] != 0)
         std::cout << _coefs[i] << "x^" << _degrees[i];
      if(i < _size - 1)
         std::cout << " + ";
   }
}

int Polinomial::calculate(int xValue) const
{
   int result = 0;
   for(size_t i = 0; i < _size; ++i)
      result += pow(xValue,_degrees[i]) * _coefs[i];
   return result;
}

Polinomial Polinomial::derive() const
{
   Polinomial result;
   for(size_t i = 0; i < _size; ++i)
      result.add(_coefs[i] * _degrees[i], _degrees[i] - 1);
   return result;
}

Polinomial& Polinomial::operator=(Polinomial& other)
{
   _size = other.size();
   _coefs.resize(_size);
   _degrees.resize(_size);
   for(size_t i = 0; i < other.size(); ++i)
   {
       _coefs[i] = other.get_coefs()[i];
       _degrees[i] = other.get_degrees()[i];
   }
   return *this;
}
