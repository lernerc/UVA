#include <iostream>
using namespace std;

const int MAX_i = 31623;

int square[MAX_i];
bool works[MAX_i] = {false};

int main() {

   for(int i = 1; i < MAX_i; i++) {
      square[i] = i*i;
   }
   int sq = 2;
   int num = 3;
   for(int i = 3; num < 1000000000; i++) {
      if(num >= square[sq])
	 sq++;
      else if(num == square[sq] - 1) {
	 works[sq] = true;
      }
      num += i;
   }

  // figure out triangle
   int a, b;
   int cases = 1;
   while(cin >> a >> b && (a != 0 || b != 0)) {
      cout << "Case " << cases++ << ": ";
      int times = 0;
      for(int i = 0; i < MAX_i; i++) {
	 if(square[i] <= a) continue;
	 if(square[i] >= b) break;
	 if(works[i])
	    times++;
      }
      cout << times << endl;
   }
   return 0;
}
