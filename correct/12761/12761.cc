#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;
const int MAX = 50;

void mult(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int n) {
   for(int i = 0 ;i < n; i++) {
      for(int j = 0; j < n; j++) {
	 result[i][j] = 0;
	 for(int k = 0; k < n; k++) {
	    result[i][j] += a[i][k] * b[k][j] % n;
	    result[i][j] %= n;
	 }
      }
   }
}

void square(int a[MAX][MAX], int result[MAX][MAX], int n) {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	 result[i][j] = 0;
	 for(int k = 0; k < n; k++) {
	    result[i][j] += a[i][k] * a[k][j] % n;
	    result[i][j] %= n;
	 }
      }
   }
}
int ans[MAX][MAX];
void exp(int a[MAX][MAX], int k, int n, int result[MAX][MAX]) {
   if(k == 0) {
      for(int i = 0; i < n; i++) {
	 for(int j = 0; j < n; j++)
	    result[i][j] = 0;
	 result[i][i] = 1;
      }
      return;
   } else if (k == 1) {
      for(int i = 0; i < n; i++)
	 copy(a[i], a[i]+n, result[i]);
   } else if (k % 2 == 0) {
      exp(a, k/2, n, result);
      square(result, ans, n);
      for(int i = 0; i < n; i++)
	copy(ans[i], ans[i] + n, result[i]);
   } else {
      exp(a, k/2, n, result);
      square(result, ans, n);
      mult(ans, a, result, n);
   }
}

int v[MAX];
int p[MAX];
int main() {

   int a[MAX][MAX];
   int result[MAX][MAX];
   int T, N, K, D;   
   cin >> T;
   while(T--) {
      cin >> N >> K >> D;
      for(int i = 0; i < N; i++) {
	 cin >> v[i];
	 fill(a[i], a[i] + N, 0);
      }
      for(int i = 0; i < N; i++) {
	 for(int j = 1; j <= D; j++) {
	    a[i][(i+j)%N] = 1;
	    a[i][(i-j+N)%N] = 1;
	 }
      }
      for(int i = 0; i < N; i++)
	 copy(a[i], a[i] + N, ans[i]);
      
      exp(a, K, N, result);
      /*    for(int i = 0; i < N; i++) {
	 for(int j = 0; j < N; j++) 
	    cout << result[i][j] << " ";
	 cout << endl;
	 }
	 cout << endl;
      */
      for(int i = 0; i < N; i++) {
	 p[i] = 0;
	 for(int j = 0; j < N; j++) {
	    p[i] += result[i][j] * v[j] % N;
	    p[i] %= N;
	 }
      }
/*
  for(int i = 0; i < N; i++)
	 cout << p[i] << " ";
      cout << endl;
*/
      int minim = p[0];
      for(int i = 1; i < N; i++) {
	 minim = min(minim, p[i]);
      }
      cout << minim << endl;
      vector<int> ps;
      for(int i = 0; i < N; i++) 
	 if(p[i] == minim)
	    ps.push_back(i+1);
      for(int i = 0; i < (int)(ps.size()); i++) {
	 if(i != 0)
	    cout << " ";
	 cout << ps[i];
      }
      cout << endl;
   }
   return 0;
}
