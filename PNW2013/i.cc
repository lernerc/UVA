#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int planets[4002];

void doCase() {
   int N;
   cin >> N;
   for(int i = 0; i < N; i++) {
      cin >> planets[i];
   }
   sort(planets, planets + N);
   int left, right;
   double half = (double)(planets[N-1] - planets[0])/2.0 + planets[0];
   for(int i = 0; i < N; i++) {
      if(planets[i] < half)
	 left = planets[i] - planets[0];
      else {
	 right = planets[N-1] - planets[i];
	 break;
      }
   }
   cout << max(left, right) << endl;
}

int main() {

   // max of range of nodes on left half and range of nodes of right half
   int cases;
   cin >> cases;
   for(int i = 0; i< cases; i++) {
      doCase();
   }
   return 0;
}
