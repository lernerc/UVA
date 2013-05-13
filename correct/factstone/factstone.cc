
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int year;
   cin >> year;
   while(year!=0)
   {
      int m=(year-1960)/10+2;
      double m2=pow(2,m);
      int numberLog=1;
      double logsum=0;
      double log2=log(2);
      while(logsum<m2)
      {
	 logsum+=log(numberLog++)/log2;
      }
      cout << numberLog-2 << endl;
      cin >> year;
   }

   return 0;
}
