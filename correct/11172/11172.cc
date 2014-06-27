#include <iostream>
using namespace std;

int main() {
   int cases;
   cin >> cases;
   for(int i = 0 ;i < cases; i++) {
      long long a, b;
      cin >> a >> b;
      if(a == b)
	 cout << '=' << endl;
      else if (a > b)
	 cout << '>' << endl;
      else if ( a < b)
	 cout << '<' << endl;
/*
      if(a > b) {
	 cout << ">" << endl;
      } else if ( a < b) {
	 cout << "<" << endl;
      } else if (a == b) {
	 cout << "=" << endl;
	 }
      */
   }
   return 0;
}
