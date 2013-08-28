#include <iostream>
using namespace std;

bool possible[50002];
bool now[50002];
int coins[100];

void gothrough(const int totsum, const int num) {
   fill(possible, possible + 50002, false);
   possible[0] = true;
   for(int i = 0; i < num; i++) {
      for(int j = totsum - 1; j > 0; j--) {
	 if(j - coins[i] < 0) continue;
	 if(possible[j - coins[i]]) possible[j] = true;
      }
   }
}

// find the possible closest to half and the difference is the abs(total sum - 2*possible num) 
int main() {
   int cases;
   cin >> cases;
   for(int w = 0; w < cases; w++) {
      int num;
      fill(possible, possible + 50002, false);
      possible[0] = true;
      cin >> num;
      int sum = 0;
      for(int q = 0; q < num; q++) {
	 cin >> coins[q];
	 sum += coins[q];
      }
      
      gothrough(sum/2 + 1, num);

      int broken = true;
      for(int i = sum / 2; i > 0; i--) {
	 if(possible[i]) {
	    cout << sum - 2 * i << endl;
	    broken = false;
	    break;
	 }
      }
      if(broken) {
	 cout << sum << endl;
      }
   }
   return 0;
}
