#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      int rel;
      cin >> rel;
      vector<int> d;
      for(int j=0;j<rel;j++)
      {
	 int e;
	 cin >> e;
	 d.push_back(e);
      }
      sort(d.begin(),d.end());
      int median=d.size()/2;
      int position=d[median];
      int dis=0;
      for(int j=0;j<rel;j++)
      {
	 dis+=abs(d[j]-position);
      }
      
      cout << dis << endl;
   }
   
   return 0;
}
