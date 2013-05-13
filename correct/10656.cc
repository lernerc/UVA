//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10656
// Description: I read the positive numbers into an array and then output the
// array
//*****************************************************************************
#include <iostream>
using namespace std;

int input[10000];

int main() {

   int numbers;
   while(cin >> numbers && numbers!=0) {
      int place=0;
      int i=0;
      while(i<numbers) {
	 cin >> input[place];
	 if(input[place]>0) {
	    place++;
	 }
	 i++;
      }
      if(input[0]<=0) {
	 input[0]=0;
      }
      
      cout << input[0];
      for(int i=1;i<place;i++) {
	 cout << ' ' << input[i];
      }
      cout << endl;
      
   }

   return 0;
}
