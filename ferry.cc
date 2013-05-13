#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int n,t,m;
   int time,trips;
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      cin >> n >> t >> m;
      vector<int> cars;
      for(int q=0;q<m;q++)
      {
	 int time;
	 cin >> time;
	 cars.push_back(time);
      }
      // stuff
   }
   
   return 0;
}
