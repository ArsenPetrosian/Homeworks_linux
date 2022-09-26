#include <iostream>
#include <vector>

void insertion_sort_descending(std::vector<int>& vector) {
   int temp = 0, j = 0;
   for(int i = 1; i < vector.size(); ++i) {
      temp = vector[i];
      j = i - 1;
      while(j >= 0 && temp >= vector[j]) {
         vector[j + 1] = vector[j];
         --j;
      }
      vector[j + 1] = temp;
   }
}

int main(int argc, char** argv) {
   int N = argv[1];
   std::vector<int> vector(N);
   for(int i = 0; i < N; ++i)
      std::cin >> vector[i];
   insertion_sort_descending(vector);
   for(int i = 0; i < N; ++i)
      std::cout << vector[i] << ' ';
   return 0;
}
