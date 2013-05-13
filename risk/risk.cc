#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAX=21;
int main()
{
   int caseNum=1;
   int A[MAX][MAX];
   while(true)
   {
      for(int i=1;i<MAX;i++)
      {
	 for(int j=1;j<MAX;j++)
	 {
	    A[i][j]=100;
	 }
      }
      
      for(int k=1;k<=19;k++)
      {
	 int num;
	 cin >> num;
	 if(cin.eof())
	    return 0;
	 for(int w=0;w<num;w++)
	 {
	    int y;
	    cin >> y;
	    A[k][y]=1;
	    A[y][k]=1;
	 }
      }
      
      for(int k=1;k<MAX;k++) 
      {
	 for(int i=1;i<MAX;i++)
	 {
	    for(int j=1;j<MAX;j++)
	    {
	       
	       A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	    }
	 }
      }
      int pairs;
      cin >> pairs;
      cout << left << "Test Set #" << caseNum << endl;
      for(int i=0;i<pairs;i++)
      {
	 int x,y;
	 cin >> x >> y;
	 cout << right << setw(2) << x << " to " << setw(2) << y << ": "
	      << left << A[x][y] << endl;
      }
      caseNum++;
      cout << endl;
   }
   return 0;
}
