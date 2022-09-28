#include<vector>
#ifndef Polinomial_is_defined
#define Polinomial_is_defined

namespace _Polinomial
{
   class Polinomial
   {
      private:
         std::vector<int> _coefs;
      	 std::vector<int> _degrees;
      public:
      	 void add(int coef, int degree);
      	 void print() const;
      	 int calculate(int xValue) const;
      	 Polinomial derive() const;
   };
}

#endif
