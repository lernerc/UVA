#include <iostream>
using namespace std;

int fast_exp(int b, int n, int m) {
   int res = 1;
   long long x = b;

   while(n > 0) {
      if(n & 0x01) {
	 n--;
	 res = (res * x) % m;
      } else {
	 n >>= 1;
	 x = ( x * x) % m;
      }
   }
   return res;
}

int main() {
   int b, n, m;
   while(cin >> b >> n >> m) {
      cout << fast_exp(b, n, m) << endl;
   }
   
   
   return 0;
   
}
