#include <iostream>
using namespace std;

int main() {

   int s, c, p, l;
   int cases = 1;
   while(cin >> s >> c >> p >> l && ( s != 0 || c != 0 || p != 0 || l != 0)) {
      bool happen = false;
      cout << "Case " << cases++ << ": ";
      int prong = p, link = l; 
      for(int i = 0; i < s*c; i++) {
	 // I have no idea what I am doing
      }
      if(!happen) {
	 cout << "Never" << endl;
      }
   }
   return 0;
}
