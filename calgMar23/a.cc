#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for( int w = 0; w < cases; w++) {

      string complexity;
      long long n, t, l;
      cin >> complexity >> n >> t >> l;
      bool passes=true;
      if(complexity == "O(N)") {
	 passes = true; //n <= floor((double)l * 100000000 / t);
      } else if(complexity == "O(N^2)") {
	 passes = (n * n ) <= floor((double)l * 100000000 / t);
      } else if(complexity == "O(N^3)") {
	 passes = (n * n * n) <= floor((double)l * 100000000 / t);
      } else if(complexity == "O(2^N)") {
	 long long ans=1;
	 for(int i = 1; i <= n; i++) {
	    long long temp = ans;
	    ans *= 2;
	    if(ans < temp) {
	       passes = false;
	    }
	 }
	 if(passes)
	    passes = ans <= floor((double)l * 100000000 / t);
      } else if(complexity == "O(N!)") {
	 long long ans=1;
	 for(int i = 1; i <= n; i++) {
	    long long temp = ans;
	    ans *= i;
	    if(ans < temp) {
	       passes = false;
	    }
	 }
	 if(passes)
	    passes = ans <= floor((double)l * 100000000 / t);
      } else {
	 cerr << "not handled" << endl;
      }
      
      if(passes) {
	 cout << "May Pass." << endl;
      } else {
	 cout << "TLE!" << endl;
      }
   }
   
   return 0;
}
