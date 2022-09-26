#include "Polinomial.h"

using namespace _Polinomial;

void Polinomial::add(int coef, int degree)
{
   _coefs.push_back(coef);
   _degrees.push_back(degree);
}

void Polinomial::print() const
{
   for(size_t i = 0; i < _coefs.size(); ++i)
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
   for(size_t i = 0; i < _coefs.size(); ++i)
   {
      current = std::pow(xValue,degree[i]);
      current *= _coefs[i];
      result += current;
   }
   return result;
}

void Polinomial::derive() const
{
   for(size_t i = 0; i < _coefs.size(); ++i)
   {
      _coefs[i] *= _degrees[i];
      --_degrees[i];
   }
}
