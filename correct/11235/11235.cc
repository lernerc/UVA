#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <iomanip>
using namespace std;

const int MAX_N = 100000;

// RMQ:
//   call constructRMQ to get data structure M                   O(n)
//   call getmax to get the maximum from [a..b] inclusive        O(log n)
//   call update to change a value in the array                  O(log n)
int size;

void constructRMQ(int A[MAX_N], int M[4*MAX_N], int n) {
  size = 1; while(size < n) size <<= 1;
  for (int i=0; i < size; i++) M[size-1+i] = (i < n ? A[i] : INT_MIN);
  for (int i=size-2; i>=0; i--) M[i] = max(M[2*i+1],M[2*i+2]);
}

int getmax(int M[4*MAX_N], int a, int b, int st=0,int en=size,int ind=0) {
  if (a > b || a >= en || b < st)         return INT_MIN;
  if ((a <= st && en <= b) || st+1 >= en) return M[ind];
  int mid = (st+en)/2;
  return max(getmax(M,a,b,st,mid,2*ind+1), getmax(M,a,b,mid,en,2*ind+2));
}

void update(int A[MAX_N], int M[4*MAX_N], int i, int val){
  A[i] = val; M[i += size-1] = val;
  while((i = (i-1)/2)) M[i] = max(M[2*i+1],M[2*i+2]);
}

int main() {

   int orig[MAX_N], occur[MAX_N], start[MAX_N];
   int tree[4*MAX_N];
   int n, q;
   while(cin >> n >> q && n != 0) {
      for(int i = 0; i < n; ++i) {
	 cin >> orig[i];
      }
      for(int i = 0; i < n; ) {
	 int number = orig[i];
	 int j = i + 1;
	 while((j<n) && (orig[j] == number)) {
	    j++;
	 }
	 for(int k = i; k < j; ++k) {
	    occur[k] = j - i;
	    start[k] = i;
	 }
	 i = j;
      }
  
      constructRMQ(occur, tree, n);
      
      // go through queries
      for(int w = 0; w < q; ++w) {
	 int i , j;
	 cin >> i >> j;
	 i--;
	 j--;
	 int a = start[i] + occur[i], b = start[j] - 1;
	 int maxlength = max(getmax(tree, a, b),
			     max(occur[i] - i + start[i],
				 j - start[j] + 1));

	 if(start[i] == start[j]){
	    maxlength = j - i + 1;
	 }
	 cout << maxlength << endl;
      }
   }
   
   return 0;
}
