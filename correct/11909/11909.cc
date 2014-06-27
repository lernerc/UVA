#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = acos(-1);
int main() {
   int l, w, h, deg;
   while( cin >> l >> w >> h >> deg) {
      if( tan(deg*PI/180.0)*l < h)
	 cout << fixed << setprecision(3)
	      << ((double)h - tan(deg*PI/180.0)*l/2.0)*w*l << " mL" <<endl;
      else
	 cout << fixed << setprecision(3)
	      << (double)(h*h*tan((90.0-deg)*PI/180.0))*w/2.0 << " mL" << endl;
   }
   return 0;
}
