#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distance(int meetx, int meety, vector<int> x, vector<int> y);
   
int main()
{
   int cases=1;
   int n;
   while (cin >> n && n!=0)
   {
      vector<int> x, y;
      for(int i=0;i<n;i++)
      {
	 int q,r;
	 cin >> q >> r;
	 x.push_back(q);
	 y.push_back(r);
      }
      sort(x.begin(),x.end());
      sort(y.begin(),y.end());
      int meetx, meety;
      int sum=0;
      if(n%2)
      {
	 // even
	 int tempx=meetx=x[n/2];
	 int tempy=meety=y[n/2];
	 sum=distance(tempx,tempy,x,y);
	 /*if(distance(tempx+1,tempy,x,y)<sum)
	 {
	    sum=distance(tempx+1,tempy,x,y);
	    meetx=tempx+1;
	    meety=tempy;

	 }
	 else if(distance(tempx+1,tempy+1,x,y)<sum)
	 {
	    sum=distance(tempx+1,tempy+1,x,y);
	    meetx=tempx+1;
	    meety=tempy+1;

	 }
	 if(distance(tempx,tempy+1,x,y)<sum)
	 {
	    sum=distance(tempx,tempy+1,x,y);
	    meetx=tempx;
	    meety=tempy+1;

	    }
	 */
      }
      else
      {
	 // odd
	 meetx=x[(n-1)/2];
	 meety=y[(n-1)/2];
	 sum=distance(meetx, meety, x, y);
      }
      cout << "Case " << cases << ": (" << meetx << "," << meety << ") " << sum
	   << endl;
      cases++;
   }
   return 0;
}

int distance(int meetx, int meety, vector<int> x, vector<int> y)
{
   int sum=0;
   for(int i=0;i<x.size();i++)
   {
      sum+=abs(x[i]-meetx)+abs(y[i]-meety);
   }
   return sum;
}
