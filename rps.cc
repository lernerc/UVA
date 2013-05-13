#include <iostream>
using namespace std;

char winner(int i,int j,int r, int c,char grid[100][100]);
char win(char, char);

int main()
{
   char grid[100][100];
   char nextday[100][100];
   int cases;
   cin >> cases;
   for(int in=0;in<cases;in++)
   {
      if(in!=0)
	 cout << endl;
      int r,c,days;
      cin >> r >> c >> days;
      for(int i=0;i<r;i++)
      {
	 for(int j=0;j<c;j++)
	 {
	    cin >> grid[i][j];
	 }
      }
            
      for(int w=0;w<days;w++)
      {
	 for(int i=0;i<r;i++)
	 {
	    for(int j=0;j<c;j++)
	    {
	       nextday[i][j]=winner(i,j,r,c,grid);
	    }
	 }
	 for(int i=0;i<r;i++)
	 {
	    for(int j=0;j<c;j++)
	    {
	       grid[i][j]=nextday[i][j];
	    }
	 }
      }
      for(int i=0;i<r;i++)
      {
	 for(int j=0;j<c;j++)
	 {
	    cout << grid[i][j];
	 }
	 cout << endl;
      }
   }
   return 0;
}

char winner(int i,int j,int r,int c,char grid[100][100])
{
   char a=grid[i][j];
   char temp;
   char winning=a;
   if(i==0)
   {
      // check right
      temp=win(a,grid[i+1][j]);
      if(a!=temp)
	 winning=temp;
   }
   else if(i==r-1)
   {
      // check left
      temp=win(a,grid[i-1][j]);
	 if(a!=temp)
	    winning=temp;
   }
   else
   {
      // check right and left
      temp=win(a,grid[i+1][j]);
      if(a!=temp)
	 winning=temp;
      temp=win(a,grid[i-1][j]);
      if(a!=temp)
	 winning=temp;
   }
   
   if(j==0)
   {
      // check down
      temp=win(a,grid[i][j+1]);
      if(a!=temp)
	 winning=temp;
   }
   else if(j==c-1)
   {
       // check up
      temp=win(a,grid[i][j-1]);
      if(a!=temp)
	 winning=temp;
   }
   else
   {
      // check up and down
      temp=win(a,grid[i][j+1]);
      if(a!=temp)
	 winning=temp;
      temp=win(a,grid[i][j-1]);
      if(a!=temp)
	 winning=temp;
   }
   return winning;
}

char win(char a, char b)
{
   if(a=='R' || b=='R')
   {
      if(b=='P' || a=='P')
      {
	 return 'P';
      }
      return 'R';
   }
   if(a=='P'||b=='P')
   {
      if(a=='S' || b=='S')
	 return 'S';
      return 'P';
   }
   if(a=='S'||b=='S')
   {
      if(a=='R' || b=='R')
	 return 'R';
      return 'S';
   }
}
