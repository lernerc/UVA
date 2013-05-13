#include <iostream>
using namespace std;

int main() {

   double table[20][20];
   int n;
   while(cin >> n) {
      for(int i = 0; i < n; ++i) {
	 for(int j = 0; j < n; ++j) {
	    if(i == j) {
	       table[i][j] = 1.0;
	    } else {
	       cin >> table[i][j];
	    }
	 }
      }
   }
   return 0;
}
