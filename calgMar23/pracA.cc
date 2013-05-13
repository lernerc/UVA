#include <iostream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      int a, b;
      cin >> a >> b;
      int ans = 1;
      for(int j = 0; j < b; j++) {
	 ans *= a;
      }
      cout << ans % 10 << endl;
   }
   
   return 0;
}
