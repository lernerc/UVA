#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
using namespace std;

long long road[100][100];
long long reach[100][100];
long long inf = 1000000000002LL;

bool test(long long k, int N, int charges) {
   for(int i = 0; i < N; i++) {
      fill(reach[i], reach[i] + N, inf);
      reach[i][i] = 0;
   }
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
	 if(road[i][j] <= k) {
	    reach[i][j] = 1;
	 }
      }
      reach[i][i] = 0;
   }
   //floyd
   for(int k = 0; k < N; k++) {
      for(int i = 0; i < N; i++) {
	 for(int j = 0; j < N; j++) {
	    reach[i][j] = min(reach[i][j], reach[i][k] + reach[k][j]);
	 }
      }
   }

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
	 if(reach[i][j] > charges && i != j) {
	    return false;
	 }
      }
   }
   return true;
}

int main() {

   int cases;
   cin >> cases;
   for(int w = 0; w < cases; w++) {
      long long hi = 0, lo = 0;
      //data
      int N, K, M;
      cin >> N >> K >> M;
      for(int q = 0; q < N; q++) {
	 fill(road[q], road[q] + N, inf);
	 road[q][q] = 0;
      }
      for(int q = 0; q < M; q++) {
	 long long u, v, d;
	 cin >> u >> v >> d;
	 road[u][v] = road[v][u] = min(d, road[u][v]);
	 hi +=  d;
      }
      //floyd
      for(int k = 0; k < N; k++) {
	 for(int i = 0; i < N; i++) {
	    for(int j = 0; j < N; j++) {
	       if(road[i][k] < inf && road[k][j] < inf) {
		  road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
	       }
	    }
	 }
      }
      /*for(int i = 0; i < N; i++) {
	 for(int j = 0; j < N; j++) {
	    cout << road[i][j] << " ";
	 }
	 cout << endl;
	 }
      */
      //binary search
      while(hi - lo > 1) {
	 long long mid = (hi - lo)/2 + lo;
	 if(test(mid, N, K)) {
	    hi = mid;
	 } else {
	    lo = mid;
	 }
      }
      
      if(test(hi, N, K)) {
	 cout << hi << endl;
      } else if(test(lo, N, K)) {
	 cout << lo << endl;
      }
      //  cout << "hi: " << hi << " lo: " << lo << endl;
   }
   
   return 0;
}
