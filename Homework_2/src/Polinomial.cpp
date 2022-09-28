#include <iostream>
#include <cmath>
#include "Polinomial.h"

using namespace _Polinomial;

void Polinomial::add(int coef, int degree)
{
   _coefs.push_back(coef);
   _degrees.push_back(degree);
}

void Polinomial::print() const
{
   for(int i = 0; i < _coefs.size(); ++i)
   {
      if(_coefs[i] != 0)
         std::cout << _coefs[i] << "x^" << _degrees[i];
      if(i < _coefs.size() - 1)
         std::cout << " + ";
   }
   std::cout << "\n";
}

int Polinomial::calculate(int xValue) const
{
   int result = 0;
   int current = 0;
   for(int i = 0; i < _coefs.size(); ++i)
   {
      current = pow(xValue,_degrees[i]);
      current *= _coefs[i];
      result += current;
   }
   return result;
}

Polinomial Polinomial::derive() const
{
   Polinomial result;
   for(int i = 0; i < _coefs.size(); ++i)
   {
      result._coefs[i] = _coefs[i] * _degrees[i];
      result._degrees[i] = _degrees[i] - 1;
   }
   return result;
}
