//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10189
// Description: Determining if you are a mine or the numbers of mines in your 
// neighbourhood
//*****************************************************************************

#include <iostream>
using namespace std;

/* The stragety used is that where a matrix with extra space all around the 
field, so that the neighbours can all be checked without having to do boundry 
checks. The directions checked are listed in two corresponding arrays dx, and 
dy, where dx is the change in x and dy is the change in y. */

char field[102][102];
char number[]={'0','1','2','3','4','5','6','7','8','9'};

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

int ismine(char c) {
   if(c=='*')
      return 1;
   else
      return 0;
}

int main() {
   int m, n;
   int x=1;

   for(int i=0;i<102;i++) {
      field[i][0]='.';
      field[0][i]='.';
   }

   while((cin >> n >> m) && (n!=0 && m!=0)) {
      //read in stuff
      for(int i=1;i<=n;i++) {
	 for(int j=1;j<=m;j++) {
	    cin >> field[i][j];
	 }
      }

      // filling the boarder with not mines
      for(int i=0;i<max(m,n)+2;i++) {
	 field[i][m+1]='.';
	 field[n+1][i]='.';
      }

      // first two for the field and last one is for the direction moves 
      for(int i=1;i<=n;i++) {
	 for(int j=1;j<=m;j++) {
	    int mines=0;
	    if(field[i][j]!='*')
	      {
		for(int k=0;k<8;k++) {
		  mines+=ismine(field[i+dx[k]][j+dy[k]]);
		}
		field[i][j]=number[mines];
	      }
	 }
      }
      
      if(x>1)
	 cout << endl;
      x++;
      cout << "Field #" << x << ':' << endl;
            
      for(int i=1;i<=n;i++) {
	 for(int j=1;j<=m;j++) {
	    cout << field[i][j];
	 }
	 cout << endl;
      }
   }
   
   return 0;
}
