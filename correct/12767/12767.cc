#include <iostream>
#include <set>
#include <queue>
using namespace std;

int G[1000];
int P[1000];
bool times[2882];

int result[2882];

int dp(int currT, int n) {
   if(result[currT] != -1)
      return result[currT];
   int maxim = 0;
   for(int i = 0; i < n; i++) {
      if((currT-G[i] > 0) && times[currT-G[i]]) {
	 if(P[i] + dp(currT-G[i], n) > maxim)
	    maxim = P[i] + dp(currT-G[i], n);
      }
   }
   if(dp(currT-1, n) > maxim) {
      maxim = dp(currT-1, n);
   }
   return result[currT] = maxim;
}

int main() {

   int cases;
   cin >> cases;
   while(cases--) {
      int N, M;
      cin >> N >> M;
      fill(result, result + 2882, -1);
      fill(times, times + 2882, false);
      for(int i = 0; i < N; i++) {
	 cin >> G[i] >> P[i];
      }
      int s, e;
      while(M--) {
	 cin >> s >> e;
	 fill(times + s, times + e + 1, true);
      }
      cout << dp(2881, N) << endl;
/*      cout << forward(N) << endl;
 */
   }
   
   return 0;
}
