#include<vector>
#include<cstddef>

#ifndef Polinomial_is_defined
#define Polinomial_is_defined

namespace _Polinomial
{
   class Polinomial
   {
      private:
         size_t _size;
         std::vector<int> _coefs;
      	 std::vector<int> _degrees;
      public:
         Polinomial();
         std::vector<int> get_coefs();
         std::vector<int> get_degrees();
         size_t size();
      	 void add(int coef, int degree);
      	 void print() const;
      	 int calculate(int xValue) const;
      	 Polinomial derive() const;
      	 Polinomial& operator=(Polinomial& other);
   };
}

#endif
