#include <iostream>
using namespace::std;

int main()
{
   int n,k;
   int newcig,butts;
   while(cin >> n >> k)
   {
      butts=n;
      while(butts>=k)
      {
 	 newcig=butts/k; // how many made
	 butts=newcig+butts%k; // butts from smoked and left over that were not
	 // made into smokes
	 n+=newcig;
      }
      cout << n << endl;
   }

   return 0;
}
