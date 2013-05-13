#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double PI=acos(-1.0);

int main()
{
   double a,b,s,m,n;
   cin >> a >> b >> s >> m >> n;
   while(a!=0 && b!=0 && s!=0 && m!=0 && n!=0)
   {
      cout << fixed << setprecision(2) << atan2(n*b,m*a)*180/PI << " "
	   << sqrt(n*n*b*b+a*a*m*m)/s << endl;
      cin >> a >> b >> s >> m >> n;
   }
   return 0;
}
