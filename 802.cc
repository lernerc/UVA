// all with no solution mean no
// all with positive solutions are true
// for case with one basis it has to be a multiple
// for case with two bases it has to be + + on the alphas, it will not work with + - and - - is not possible
// for case with three bases it can be + + +,
// alloys
//  A   B   C
// a11 a12 a13
// a21 a22 a23
// . . .
// am1 am2 am3

// linear program
// g1*a11 + g2*a21 + g3*a31 + . . . + gm*am1 = A
// g1*a12 + g2*a22 + g3*a32 + . . . + gm*am2 = B
// g1*a13 + g2*a23 + g3*a33 + . . . + gm*am3 = C


// scale A B C so that A + B + C = 1
// then g1 + g2 + g3 + . . . + gm = 1

// everything in the convex hull of the alloys can be a positive linear combination
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
int weight[100][3];

int gcd(int a, int b)
{
  int r;

  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  assert(a >= 0);
  return a;
}

int lcm(int a, int b) {
   return a*b/gcd(a,b);
}

void reduce(int i) {
   int temp = 0;
   if(weight[i][0] != 0) {
      if(weight[i][1] != 0) {
	 if(weight[i][2] != 0) {
	    temp = lcm(weight[i][0], lcm(weight[i][1], weight[i][2]));
	 } else {
	    temp = lcm(weight[i][0], weight[i][1]);
	 }
      } else if(weight[i][2] != 0) {
	 temp = lcm(weight[i][0], weight[i][2]);
      } else {
	 temp = weight[i][0];
      }
   } else if (weight[i][1] != 0) {
      if(weight[i][2] != 0) {
	 temp = lcm(weight[i][1], weight[i][2]);
      } else {
	 temp = weight[i][1];
      }
   } else {
      temp = weight[i][2];
   }
   weight[i][0]/=temp;
   weight[i][1]/=temp;
   weight[i][2]/=temp;
}

int main() {
   int n;
   while(cin >> n && n != 0) {
      int f= 0, g= -1, h=-1;
      for(int i = 0; i < n; ++i) {
	 cin >> weight[i][0] >> weight[i][1] >> weight[i][2];
	 reduce(i);
	 if(weight[f][0] == weight[i][0] &&
	    weight[f][1] == weight[i][1] &&
	    weight[f][2] == weight[i][2]) {
	 } else {
	    if(g != -1) {
	       if(h != -1) {
                  // do determinant
		  int temp =
		     determanent(weight[f][0], weight[f][1], weight[f][2],
				 weight[g][0], weight[g][1], weight[g][2],
				 weight[i][0], weight[i][1], weight[i][2]);
		  if(determanent != 0)
		     h = i;
	       }
	    } else {
	       g = i;
	    }
	 }
      }
      
   }

   
   
   return 0;
}
*/
