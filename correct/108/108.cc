#include <iostream>
using namespace std;
// 1D analysis is keep track of maximum sum so far, and maximum sum ending here, which we only keep if it is >0 otherwise we start at zero again

// turning the rectange into a sum of the rows
/*for(int s = 0; s < m; s++) {
  int B[100] = {0};
  for(int e = s; e < m; e++) {
  for(int c = 0; c < m; c++) B[c] += A[e][c];
  // do 1D analysis
  }
  }
*/
const int MAX = 100;
int square[MAX][MAX];

int lineMax(const int line[], const int N) {
   int overallMax = 0;
   int maxEndingHere = 0;
   int tmp = 0;
   for(int i = 0; i < N; i++) {
      tmp += line[i];
      if(tmp <= 0) {
	 tmp = 0;
      }
      maxEndingHere = tmp;
      if(overallMax < maxEndingHere) {
	 overallMax = maxEndingHere;
      }
   }
   return overallMax;
}

int main() {

   int N;
   cin >> N;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
	 cin >> square[i][j];
      }
   }

  // turning the rectange into a sum of the rows
   int maxn = 0;
   for(int s = 0; s < N; s++) {
      int B[MAX] = {0};
      for(int e = s; e < N; e++) {
	 for(int c = 0; c < N; c++) B[c] += square[e][c];
	 // do 1D analysis
	 int tmp = lineMax(B, N);
	 if(tmp > maxn)
	    maxn = tmp;
      }
   }
   cout << maxn << endl;
   return 0;
}
