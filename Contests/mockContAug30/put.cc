#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   int q = 0;
   string a;
   while(cin >> a) {
      cout << "\"" ;
      for(int i = 0; i < (int)a.size(); i++) {
	 cout << (char)tolower(a[i]) ;
      }
      cout << "\", ";
      q++;
   }
   cout << endl << "number = " << q
	<< endl;
   
   return 0;
}
