//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 674
// Description: for each value I precalculated the result by looping through
// all the possible coins for each cent and added the new combinations to the
// array
//*****************************************************************************

#include <iostream>
using namespace std;

int d[]={1, 5, 10, 25, 50};
int result[7500];

int main() {
   result[0] = 1;
   
   for(int i = 0; i < 5; i++) {
      for(int j = d[i]; j < 7500; j++) {
	 result[j] += result[j - d[i]];
      }
   }
   

   int cents;
   while(cin >> cents) {
      cout << result[cents] << endl;
   }

   return 0;
}
