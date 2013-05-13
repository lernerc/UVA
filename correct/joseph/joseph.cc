//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 305
// Description: trying to kill all the bad people before the first good person
//*****************************************************************************
#include <iostream>
using namespace std;

const int MAX=14;

// In my circle of people they are numbered from 1 to 2*k-1 then 0

int main() {
   int k, m, killed, left;
   // keeps track of whether all the good people are alive
   bool alive;
   int answer[MAX];
   for(int i=1;i<MAX;i++) {
      alive=false;
      for(m=i+1;!alive;m++) {
	 killed=0; // is the person killed off
	 left=0; // is the number of people left after the person killed
	 for(int j=0;j<i;j++) {
	    killed=(m-left)%(2*i-j);
	    left=(2*i-j-killed)%(2*i-j);
	    // test if the people killed are bad
	    if(killed==0 || killed>i) {
	       alive=true;
	    } else {
	       alive=false;
	       break;
	    }
	 }
	 if(alive)
	    break;
      }
      answer[i]=m;
   }

   while(cin >> k && k!=0) {
      cout << answer[k] << endl;
   }
   
   return 0;
}
