#include <iostream>
using namespace std;

bool divisor[50002];

int main() {

   int n;
   while(cin >> n && n > 1) {
      fill(divisor, divisor + 50001, false);
      int sum = 0;
      for(int i = 1; i < n/2 + 1; i++) {
	 if(n % i == 0) {
	    divisor[i] = true;
	    sum += i;
	 }
      }
      if(sum == n) {
	 cout << n << " = 1";
	 for(int i = 2; i < n/2 + 1; i++ ) {
	    if(divisor[i])
	       cout << " + " << i;
	 }
	 cout << endl;
      } else {
	 cout << n << " is NOT perfect." << endl;
      }
   }
   
   return 0;
}
