//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 116
// Description: For each position in the matrix, you calculate the minimum
// sum if you are forced to start at that spot. Then at the end you can just
// find the lowest total in the first column and that is the minimum sum.
//*****************************************************************************

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

// stores the minimum sum of the matrix if you started traversing from that spot
long long A[11][101];

// stores the matrix itself
long long matrix[11][101];

// stores whether or not the A array spot has been determined yet 
bool determined[11][101];

// stores the next spot to go to for the minimum sum
int path[11][101];

int wrap(int i, int m) {
   return (i + m) % m;
}

long long f(int i, int j, int m, int n) {
   if(j == n-1) {
      A[i][j] = matrix[i][j];
      determined[i][j] = true;
      return A[i][j];
   }
   if(determined[i][j]) {
      return A[i][j];
   }
   
   // up
   int x = f(wrap(i - 1, m), j + 1, m, n);

   int pos = wrap(i-1,m);
   int sum = x;

   // same
   int y = f(i, j + 1, m, n);
   if(y < sum) {
      pos = i;
      sum = y;
   } else if(y == sum) {
      pos = min(pos, i);
   }
   
   // down
   int z = f(wrap(i + 1, m), j + 1, m, n);

   if(z < sum) {
      pos = wrap(i + 1, m);
      sum = z;
   } else if(z == sum) {
      pos = min(wrap(i + 1, m), pos);
   }
   
     path[i][j] = pos;
   A[i][j] = matrix[i][j] + A[pos][j + 1];
   determined[i][j] = true;
   return A[i][j];
}

int main() {
   int m,n;
   while(cin >> m >> n) {
      for(int i = 0; i < m; i++) {
	 for(int j = 0; j < n; j++) {
	    cin >> matrix[i][j];
	    determined[i][j] = false;
	 }
      }

      // calculate the answer
      for(int i = 0; i < m; i++) {
	 f(i, 0, m, n);
      }

      // find the smallest number in the rows
      int ans = 0;
      long long sum = A[0][0];
      for(int i = 0; i < m; i++) {
	 if(A[i][0] < sum) {
	    ans = i;
	    sum = A[i][0];
	 }
      }
      // have to add one to the positions because everything is stored in base 0
      cout << ans+1;
      for(int i = 0; i < n-1;i++) {
	 cout << " " << path[ans][i] + 1;
	 ans = path[ans][i];
      }
      cout << endl;
      cout << sum << endl;
   }
   return 0;
}
