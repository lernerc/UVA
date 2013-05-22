#include <iostream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; ++i) {
      int sum, diff;
      cin >> sum >> diff;
      bool sol= false;
      for(int i = sum; i >= diff; --i) {
	 if( ((sum - i) >= 0) && ((2*i - sum) == diff) ) {
	    sol = true;
	    cout << i << " " << sum - i << endl;
	    break;
	 }
      }
      if(!sol) {
	 cout << "impossible" << endl;
      }
   }

   
   return 0;
}
