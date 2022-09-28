#include "Polinomial.h"
#include <iostream>

using namespace _Polinomial;

int main(int argc, char** argv)
{
   int N = argv[1][0];
   Polinomial pol;
   int coef{}, degree{};
   for (size_t i = 1; i <= N; ++i)
   {
      if (i % 2 == 1)
         coef = argv[i + 1][0];
      else
      {
         degree = argv[i + 1][0];
         pol.add(coef, degree);
      }
   }
   pol.print();
   std::cout << pol.calculate(72) << "\n";
   Polinomial derive = pol.derive();
   derive.print();
   return 0;
}
