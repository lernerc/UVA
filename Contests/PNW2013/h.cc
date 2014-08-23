#include <iostream>
using namespace std;

typedef long long ll;
ll pow[19];

int digits(ll a) {
   int i;
   if(a == 1) return 1;
   for(i = 0; i < 19 && a >= pow[i]; i++) {
   }
   return i;
}

int rec(ll y, int digs, bool first) {
   //cout << "y: " <<  y << endl;
   //cout << "digits: " << digs << endl;
   if(y < 0) {
      return 0;
   }
   if(digs == 1) {
      return y % 2  == 0LL && y <= 18;
   } else if(digs == 0) {
      return y == 0LL;
   }
   // recursive call
   int d = y % 10;
   return (d + !first)*rec((y - d - d*pow[digs - 1])/10, digs - 2, false)
      + (9 - d)*rec((y - (10 + d)*(1 + pow[digs - 1]))/10, digs - 2, false);
}

int main() {

   ll tmp = 1;
   for(int i = 0; i < 19; i++) {
      pow[i] = tmp;
      tmp *= 10;
      // cout << pow[i] << "  ";
   }
   // cout << endl;
   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      ll y;
      cin >> y;
      int digs = digits(y);
      // cout << "digits: " << digs << endl;
      int number = rec(y, digs, true) + rec(y, digs - 1, true);
      cout << number << endl;
   }
   
   return 0;
}
