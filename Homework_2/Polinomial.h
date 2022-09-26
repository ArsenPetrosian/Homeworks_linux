namespace _Polinomial
{
   #include <vector>
   class Polinomial
   {
      private:
         std::vector<int> _coefs;
      	 std::vector<int> _degrees;
      public:
      	 void add(int coef, int degree);
      	 void print() const;
      	 int calculate(int xValue) const;
      	 void derive() const;
   }
}
