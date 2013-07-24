#include <iostream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   int x, y;
   for(int i = 0; i < cases; i++) {
      cin >> x >> y;
      if(x < y) {
	 cout << "<" << endl;
      } else if (x > y) {
	 cout << ">" << endl;
      } else {
	 cout << "=" << endl;
      }
   }
   
   return 0;
}
