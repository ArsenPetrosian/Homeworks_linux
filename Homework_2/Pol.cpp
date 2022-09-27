#include "Polinomial.h"
#include "Polinomial.cpp"

int main(int argc, char** argv)
{
   int N;
   std::cin >> N;
   Polinomial pol;
   int coef{}, degree{};
   for (int i = 1; i <= N; ++i)
   {
      if (i % 2 == 1)
         std::cin >> coef;
      else
      {
         std::cin >> degree;
         pol.add(coef, degree);
      }
   }
   pol.print();
   std::cout << pol.calculate(72) << "\n";
   Polinomial derive = pol.derive();
   derive.print();
   return 0;
}
