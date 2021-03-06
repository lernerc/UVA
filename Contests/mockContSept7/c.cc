#include <iostream>
using namespace std;

int main() {

   int a, b;
   while(cin >> a >> b && (a != 0 || b != 0)) {
      int carries = 0;
      int num_a, num_b;
      int ca = 0;
      while(a > 0 || b > 0) {
	 num_a = a % 10;
	 num_b = b % 10;
	 ca = num_a + num_b + ca;
	 ca /= 10;
	 if(ca > 0)
	    carries++;
	 a /= 10;
	 b /= 10;
      }
      if(carries == 0) {
	 cout << "No carry operation." << endl;
      } else if(carries == 1) {
	 cout << "1 carry operation." << endl;
      } else {
	 cout << carries << " carry operations." << endl;
      }
   }
   
   return 0;
}
