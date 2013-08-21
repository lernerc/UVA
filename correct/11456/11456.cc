#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 2000;

int A[MAX];
int low[MAX];
int high[MAX];

int sq(const int size) {

   //cout << "low: ";
   for(int i = size - 1; i >= 0; i--) {
      low[i] = 1;
      for(int j = size - 1; j > i; j--) {
	 if(A[j] < A[i]) {
	    low[i] = max(low[i], 1 + low[j]);
	 }
      }
      //    cout << low[i] << " " ;
   }
   //cout << endl << "high: ";
   for(int i = size - 1; i >= 0; i--) {
      high[i] = 1;
      for(int j = size - 1; j > i; j--) {
	 if(A[j] > A[i]) {
	    high[i] = max(high[i], 1 + high[j]);
	 }
      }
      // cout << high[i] << " " ;
   }
   //cout << endl;
   
   int maxm = 0;
   for(int i = 0; i < size; i++) {
      if(low[i]+high[i] - 1> maxm) {
	 maxm = low[i] + high[i] - 1;
      }
   }
   return maxm;
}

int main() {
   
   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      int n;
      cin >> n;
      for(int j = 0; j < n; j++) {
	 cin >> A[j];
      }
      cout << sq(n) << endl;
   }
   return 0;
}
