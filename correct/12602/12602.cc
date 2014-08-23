#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {

   int N;
   cin >> N;
   char a;
   int f, s;
   while(N--) {
      f = 0;
      for(int i = 0; i < 3; i++) {
	 cin >> a;
	 f *= 26;
	 f += a -'A';;
      }
      cin >> a;
      cin >> s;
      // cout << f << " " << s << endl;
      if(abs(f-s) <= 100)
	 cout << "nice" << endl;
      else
	 cout << "not nice" << endl;
   }
   
   return 0;
}
