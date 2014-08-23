#include <iostream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {

      int hole;
      cin >> hole;
      int days=1;
      while(hole>0) {
	 hole -= days++;
      }
      cout << --days << endl;
   }
   
   return 0;
}
