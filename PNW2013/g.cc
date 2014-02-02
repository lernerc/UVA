#include <iostream>
using namespace std;

long long gen[68];

void generate() {
   gen[0] = gen[1] = 1;
   gen[2] = 2;
   gen[3] = 4;
   for(int i = 4; i < 68; i++) {
      gen[i] = gen[i-1] + gen[i-2] + gen[i-3] + gen[i-4];
   }
}

int main() {

   generate();
   
   int cases;
   cin >> cases;
   for(int w = 0; w < cases; w++) {
      int i;
      cin >> i;
      cout << gen[i] << endl;
   }
   
   return 0;
}
