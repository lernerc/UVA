#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

   int ant[1000000];
   int cases;					
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      int length,ants;
      cin >> length >> ants;
      for(int b=0;b<ants;b++)
      {
	 cin >> ant[b];
      }
      int end=0;
      int middle=0;
      for(int b=0;b<ants;b++)
      {
         // find ant closest to the middle for short
	 if(middle<min(length-ant[b],ant[b]))
	 {
	    middle=min(length-ant[b],ant[b]);   
	 }
	 // find ant closest to the end for long
	 if(end<max(length-ant[b],ant[b]))
	 {
	    end=max(length-ant[b],ant[b]);
	 }
      }
      cout << middle <<" "<< end << endl;
      
   }
   return 0;
}
