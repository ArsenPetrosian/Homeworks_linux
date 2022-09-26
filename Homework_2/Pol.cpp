#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
   int N = argv[1];
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
   int value;
   std::cout << calculate(72) << "\n";
   pol.derive();
   pol.print();
   return 0;
}
