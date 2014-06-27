#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
   int cases;
   cin >> cases;
   string line;

   for(int i = 0; i < cases; i++) {
      int maxspeed = 0;
      int scary;
      cin >> scary;
      for(int j = 0; j < scary; j++) {
	 int speed;
	 cin >> speed;
	 maxspeed = max(speed, maxspeed);
      }
      cout << "Case " << i+1 << ": " << maxspeed << endl;

   }
   
   return 0;
}
