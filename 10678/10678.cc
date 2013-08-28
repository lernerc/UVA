#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 2 * acos(0.0);

int main() {

   int cases;
   cin >> cases;
   for(int q = 0; q < cases; q++) {
      double pil, rope;
      cin >> pil >> rope;
      double a, b;
      b = rope/2.0;
      a = sqrt(rope * rope / 4.0 - pil * pil / 4.0);
      cout << fixed << setprecision(3);
      cout << PI * a * b << endl;
      
   }
   
   return 0;
}
