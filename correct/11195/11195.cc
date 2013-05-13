//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 11195
// Description: The program starts keeps the n queens stored in an array where
// the index represents the row number and the entry is the column number of
// where the queen is placed. 
//*****************************************************************************
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

const int N_MAX=15;
const int D_MAX=28;

// the board where the spots the queens can be placed are marked with '.'
// and where the queens cannot be placed is marked with '*'
char board[N_MAX][N_MAX];

// are the arrays for all the diagonal lines on the board and when a queen is
// place on a diagonal it is true

bool d_sub[D_MAX]={false}; // i+perm[i]+n-1
bool d_add[D_MAX]={false}; // i+perm[i]

// global variable to keep track of the combinations used
long long combinations=0;

void genperm(int perm[],int n,int start=0) {
   if(start>=n) {
      combinations++;  
   }
   for(int i=start;i<n;i++) {
      swap(perm[start],perm[i]);
      // check diagonals so far and if move is possible
      if(!d_sub[start-perm[start]+n-1] && !d_add[start+perm[start]] &&
	 board[start][perm[start]]!='*') {
	 //updating the new diagonals used
	 d_sub[start-perm[start]+n-1]=d_add[start+perm[start]]=true;
	 
	 genperm(perm,n,start+1);
	 
	 // getting rid of the diagonals used
	 d_sub[start-perm[start]+n-1]=d_add[start+perm[start]]=false;	 
	 
      }
      
      swap(perm[start],perm[i]);
   }
}

int main() {

   // read in the board
   int n;
   int cases=1;
   while(cin >> n && n!=0) {
      // the variable is reset to zero so that each case will have its
      // own sum
      combinations=0;
      // reads in the board
      for(int i=0;i<n;i++) {
	 for(int j=0;j<n;j++) {
	    cin >> board[i][j];
	 }
      }
      // the permutation numbers used in genperm
      int perm[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
      genperm(perm,n,0);
      cout << "Case " << cases++ << ": " << combinations << endl;
   }
   
   return 0;
}

