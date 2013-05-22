//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10420
// Description: Counting the beauties in a country
//*****************************************************************************
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

// using a map to store the country names and number of beauties, because a
// map sorts the entries by their keys and uses binary search to find if a
// key has been used
map<string,int> list;

int main() {
   int lines;
   cin >> lines;
   {
      string blankline;
      getline(cin,blankline);
   }
   string country;
   for(int i=0;i<lines;i++) {
      getline(cin,country);
      // get name of country
      stringstream beauty(country);
      beauty >> country;
      // search for name in list do binary search
      map<string,int>::iterator iter=list.find(country);
      if(iter==list.end())
	 list[country]=1;
      else
	 list[country]=list[country]+1;
            
   }
   // outputing results
   for(map<string,int>::iterator i=list.begin();i!=list.end();i++) {
      cout << i->first << " " << i->second << endl;
   }
   
   return 0;
}
