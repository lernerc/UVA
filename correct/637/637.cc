#include<iostream>
using namespace std;

// last page with first page is a multiple of 4
void output(int num, int n) {
   if(num <= n) {
      cout << num;
   } else {
      cout << "Blank";
   }
}

int main() {
   int high, low, n;
   while(cin >> n && n != 0) {
      low = 1;
      if((n % 4) == 0) {
	 high = n;
      } else {
	 high = (n/4)*4 + 4; // I am aware of integer division
      }
      cout << "Printing order for " << n << " pages:" << endl;
      int sheet = 1;
      //cerr << "HIGH: " << high << endl;
      while(high > low) {
	 cout << "Sheet " << sheet << ", front: ";
	 output(high,n);
	 cout << ", ";
	 output(low, n);
	 cout << endl;
	 low++;
	 high--;
	 if( low <= n || high <= n) {
	    cout << "Sheet " << sheet << ", back : ";
	    output(low, n);
	    cout << ", ";
	    output(high, n);
	    cout << endl;
	 }
	 low++;
	 high--;
	 sheet++;
      }
   }
   
   return 0;
}
