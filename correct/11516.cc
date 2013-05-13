//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 11516
// Description: binary search is used for calculating the smallest radius used
// for a certain number of access points
//*****************************************************************************
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

int home[100001];

int access_points(double radius, int houses) {
   int i=0;
   int access=0;
   // the home array is sorted for this
   // the houses within 2*radius of the first home not covered by another
   // access point are incremented through and this is repeated until all the
   // homes are covered and the number of access points are returned
   while(i<houses) {
      double distance=home[i]+2.0*radius;
      while(i<houses && home[i]<distance) {
	 i++;
      }
      access++;
   }
   return access;
}

double my_binary_search(double lo, double hi,int wanted_pts, int houses) {
   if((hi-lo)<0.0001)
      return hi;
   double radius=(hi-lo)/2+lo;
   int access_pts=access_points(radius,houses);
   if(wanted_pts < access_pts) {
      return my_binary_search(radius,hi,wanted_pts,houses);
   } else if(wanted_pts >= access_pts){
      return my_binary_search(lo,radius,wanted_pts,houses);
   }
}

int main() {
   cout << fixed <<  setprecision(1);
   int cases;
   cin >> cases;
   for(int z=0;z<cases;z++) {
      int access_pts, houses;
      cin >> access_pts >> houses;
      for(int i=0;i<houses;i++) {
	 cin >> home[i];
      }
      sort(home,home+houses);
      double number=my_binary_search(0,1.0*(home[houses-1]-home[0])/2.0,
				     access_pts,houses);
      cout << number << endl;
   }
   return 0;
}
