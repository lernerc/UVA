#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      int b, r;
      cin >> r >> b;
      cout << fixed << setprecision(3);
      if( b * b > 2 * r * r) {
	 cout << 2.0 * r * r << endl;
      } else {
	 cout << 2.0 * sqrt( r * r - 0.25 * b * b) * b << endl; 
      }
   }
   
   
   return 0;
}
