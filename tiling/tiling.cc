#include <iostream>
using namespace std;

// WRONG
int main()
{
   int f[31];

   for(int i=1;i<31;i++)
   {
      f[i]=0;
   }
   f[0]=1;
   f[2]=3;   
   for(int i=4;i<31;i+=2)
   {
      int j=i;
      while(j>2)
      {
	 f[i]+=2*f[i-j];
	 j-=2;
      }
      f[i]+=3*f[i-2];
   }
   int n;
   cin >> n;
   while(n!=-1)
   {
      cout << f[n] << endl;
      cin >> n;
   }
   return 0;
}
