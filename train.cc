#include <iostream>
using namespace std;

int main()
{
   int train[50];
   int cases;
   cin >>cases;
   for(int i=0;i<cases;i++)
   {
      int trains;
      cin >> trains;
      for(int j=0;j<trains;j++)
      {
	 cin >> train[j];
      }
      // optimal train swapping takes ? swaps
      int swaps=0;
      for(int k=0;k<trains-1;k++)
      {
	 for(int w=k+1;w<trains;w++)
	 {
	    if(train[k]>train[w])
	    {
	       swaps++;
	    }
	 }
      }
      cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
   }
   return 0;
}
