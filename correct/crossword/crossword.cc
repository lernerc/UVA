#include <iostream>
#include <iomanip>
using namespace std;

bool start(int x,int y,char cross[10][10],int dr,int dc,int r, int c);

int main()
{
   char crossword[10][10];
   int r,c;
   cin >> r;
   int num=1;
   while(r!=0)
   {
      if(num>1)
	 cout << endl;
      cin >> c;
      //read in crossword
      for(int i=0;i<r;i++)
      {
	 for(int j=0;j<c;j++)
	 {
	    cin >> crossword[i][j];
	 }
      }
      int word[10][10];
      int words=1;
      //figure out numbers for words
      for(int i=0;i<r;i++)
      {
	 for(int j=0;j<c;j++)
	 {
	    if(start(i,j,crossword,-1,0,r,c) || start(i,j,crossword,0,-1,r,c))
	    {
	       word[i][j]=words++;
	    }
	    else
	    {
	       word[i][j]=0;
	    }
	 }
      }
        // navigate in rows
      cout << "puzzle #" << num << ":" << endl;
      cout << "Across" << endl;
      int i=0;
      while(i<r)
      {
	 int j=0;
	 while(j<c)
	 {
	    if(start(i,j,crossword,0,-1,r,c))
	       {
		  cout << setw(3) << right << word[i][j] << '.';
		  while(!start(i,j,crossword,0,1,r,c))
		  {
		     cout << crossword[i][j];
		     j++;
		  }
		  cout << crossword[i][j] << endl;
	       }
	    j++;
	 }
	 i++;
      }
      cout << "Down" << endl;
      // navigate in columns
      i=0;
      while(i<r)
      {
	 int j=0;
	 while(j<c)
	 {
	    if(start(i,j,crossword,-1,0,r,c))
	    {
	       cout << setw(3) << right << word[i][j] << '.';
	       int k=i;
	       while(!start(k,j,crossword,1,0,r,c))
	       {
		  cout << crossword[k][j];
		  k++;
	       }
	       cout << crossword[k][j] << endl;
	    }
	    j++;
	 }
	 i++;
      }
      
      cin >> r;
      num++;
   }
  
   return 0;
}

bool start(int x,int y,char cross[10][10],int dr,int dc,int r,int c)
{
   if( cross[x][y]!='*')
   {
      if (x+dr<0 || y+dc<0 || x+dr>=r || y+dc>=c)
      {
	 return true;
      }
      if(cross[x+dr][y+dc]=='*')
      {
	 return true;
      }
      return false;
   }
   return false;
}
