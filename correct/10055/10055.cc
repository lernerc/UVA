//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10055
// Description: Finding the absolute value of the difference between two input
// numbers
//*****************************************************************************
#include <iostream>
using namespace std;

// calculating the difference between hashmat's army and anther when the other
// army always is greater than or equal to hashmat's army. When the armies are
// given in a random order.

int main()
{
   long long a, b;
   while(cin >> a >> b)
   {
      long long c;
      if(a>b) 
	 c=a-b;
      else
	 c=b-a;
      cout << c << endl;
   }
   
   return 0;
}
