//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 497
// Description: To hit the most missiles you have to hit the ones in the
// longest ascending subsequence, so I used your code.
//*****************************************************************************


/*
 * Longest Ascending Subsequence
 *
 * Author: Howard Cheng
 * Reference:
 *   Gries, D.  The Science of Programming
 *
 * Given an array of size n, asc_seq returns the length of the longest
 * ascending subsequence, as well as one of the subsequences in S.
 * sasc_seq returns the length of the longest strictly ascending
 * subsequence.  It runs in O(n log n) time.
 *
 * Also included are simplified versions when only the length is needed.
 *
 * Note: If we want to find do the same things with descending
 * subsequences, just reverse the array before calling the routines.
 * 
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <string>
using namespace std;

int asc_seq(vector<int> A, int n, vector<int>& S)
{
  vector<int> last(n+1), pos(n+1), pred(n);
  if (n == 0) {
    return 0;
  }

  int len = 1;
  last[1] = A[pos[1] = 0];

  for (int i = 1; i < n; i++) {
    int j = upper_bound(last.begin()+1, last.begin()+len+1, A[i]) -
      last.begin();
    pred[i] = (j-1 > 0) ? pos[j-1] : -1;
    last[j] = A[pos[j] = i];
    len = max(len, j);
  }

  int start = pos[len];
  for (int i = len-1; i >= 0; i--) {
    S[i] = A[start];
    assert(i == 0 || pred[start] < start);
    start = pred[start];
  }

  return len;
}


int main(void)
{
   int cases;
   
   cin >> cases;
   string blankline;

   getline(cin, blankline);
   getline(cin, blankline);
   
   for(int w=0; w < cases; w++) {
      vector<int> A;
      int k;
      if(w != 0)
	 cout << endl;
      string input;
      while(getline(cin, input) && input != blankline)
      {
	 int c =atoi(input.c_str());
	 A.push_back(c);
      }
        
      vector<int> S(A.size());
      k = asc_seq(A, A.size(), S);
      cout << "Max hits: " << k << endl;
      for(int i = 0; i < k; i++) {
	 cout << S[i] << endl;
      }
   }
   
   
   return 0;
}
