#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      vector <vector<int> > streets;
      int east,south;
      cin >> east >> south;
      for(int q=0;q<east;q++)
      {
	 vector <int> block;
	 for(int j=0;j<south;j++)
	 {
	    block.push_back(-1);
	 }
	 streets.push_back(block);
      }
      int row=0;
      while(row<=east)
      {
	 string line;
	 getline(cin,line);
	 istringstream iss;
	 iss.str(line);
	 int col;
	 iss >> row; 
	 while(iss >> col)
	 {
	    streets[row-1][col-1]=0;
	 }
	 row++;
      }
      for(int w=0;w<east;w++)
      {
	 if(streets[w][0]==-1)
	    streets[w][0]=1;
      }
      for(int j=0;j<south;j++)
      {
	 if(streets[0][j]==-1)
	 streets[0][j]=1;
      }
      for(int w=1;w<east;w++)
      {
	 for(int j=1;j<south;j++)
	 {
	    if(streets[w][j]==-1)
	    {
	       streets[w][j]=streets[w-1][j]+streets[w][j-1];
	    }
	 }
      }
      
/*      for(vector<vector<int> >::size_type q=0;q<streets.size();q++)
      {
	 for(vector<int>::size_type r=0;r<streets[q].size();r++)
	 {
	    cout << streets[q][r] << " ";
	 }
	 cout << endl;
      }
*/
      cout << streets[east-1][south-1] << endl;
      cout << endl;
   }
   return 0;
}
