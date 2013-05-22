#include<iostream>
using namespace std;

int sol[13];
bool calc[13];

int derangement(const int& x) {
   if(calc[x]) {
      return sol[x];
   }
   return (x - 1) * (derangement(x - 1) + derangement(x - 2));
}

int main() {
   fill(calc, calc + 13, false);
   sol[0] = sol[1] = 0;
   sol[2] = 1;
   calc[0] = calc[1] = calc[2] = true;
   int cases;
   cin >> cases;
   for(int i = 0; i < cases; ++i) {
      // total is n!
      // number of ways for EVERYONE to take the wrong hat?
      int n;
      cin >> n;
      int total = 1;
      for(int i = 2; i <= n; ++i) {
	 total *=i;
      }
      int wrong = derangement(n);
      cout << wrong << "/" << total << endl;
   }
   
   return 0;
}
