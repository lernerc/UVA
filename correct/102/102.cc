#include <iostream>
using namespace std;

class bin {
public:
   int c[3];
   friend istream& operator>>(istream& oss, bin& a);
};

istream& operator>>(istream& oss, bin& a) {
   oss >> a.c[0] >> a.c[1] >> a.c[2];
   return oss;
}

int main() {
   
   bin a[3];
   while( cin >> a[0] >> a[1] >> a[2]) {
      char colorInBin[3] = {0,0,0};

   }
   
   return 0;
}
