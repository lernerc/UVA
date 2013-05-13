//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10192
// Description: I take the string representing the cities and find the
// longest common subsequence, because this will find the longest string of
// cities that are in the same order.
//*****************************************************************************
/*
 * Longest common subsequence
 *
 * Author: Howard Cheng
 * Reference:
 *   http://www.ics.uci.edu/~eppstein/161/960229.html
 *
 * Given two arrays A and B with sizes n and m respectively, compute the
 * length of the longest common subsequence.  It also returns in s a longest
 * common subsequence (it may not be unique).  One can specify which one
 * to choose when multiple longest common subsequences exist.
 *
 * Running time and space requirement is O(mn).
 *
 */

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

int LCS(vector<char> A, int n, vector<char> B, int m)
{
  
   vector<vector <int> > L(n + 1);
   for(int i = 0; i < n + 1; i++) {
      L[i].resize(m + 1);
   }
   
   int i, j;//, k;
   for (i = n; i >= 0; i--) {
      for (j = m; j >= 0; j--) {
	 if (i == n || j == m) {
	    L[i][j] = 0;
	 } else if (A[i] == B[j]) {
	    L[i][j] = 1 + L[i+1][j+1];
	 } else {
	    L[i][j] = max(L[i+1][j], L[i][j+1]);
	 }
      }
   }
  /* the following is not needed if you are not interested in the sequence */
   /* k = 0;
  i = j = 0;
  while (i < n && j < m) {
    if (A[i] == B[j]) {
      s[k++] = A[i];
      i++;
      j++;
    } else if (L[i+1][j] > L[i][j+1]) {
      i++;
    } else if (L[i+1][j] < L[i][j+1]) {
      j++;
    } else {
   */
    /* put tie-breaking conditions here */

      /* eg. pick the one that starts at the first one the earliest */
   /* j++;
      }
 
      }
   */
   int answer = L[0][0];
     
   return answer;
}

int main(void)
{
      int cases = 1;
   string one, two;
   while (getline(cin, one) &&  one != "#" ) {
      getline(cin, two);
      int n = one.length();
      int m = two.length();
      vector<char> A(n), B(m);
      copy(one.begin(), one.end(), A.begin());
      copy(two.begin(), two.end(), B.begin());
    
      int l = LCS(A, n, B, m);
      
      cout  << "Case #" << cases++ << ": you can visit at most "<< l
	    << " cities." << endl;
   }
   return 0;
}
