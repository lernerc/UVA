//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 384
// Description: I parce each different type of string seperatly and then check
// if it is a slurpy
//*****************************************************************************
#include <iostream>
#include <string>
using namespace std;

bool Slump(const string& a) {
   if(a.empty()) return false;
   if(a[a.length() - 1] != 'G') return false;
   if(!(a[0] == 'D' || a[0] == 'E')) return false;
   if(a.length() < 3) return false;
   // look for a string of one or 'F's after the beginning letter
   string::size_type i;
   for(i = 1; i < a.length() && a[i] == 'F'; i++) {
   }
   if(i == a.length() - 1) {
      return true;
   } else if( i == a.length() || i == 1 )
      return false;
   // look for another Slump or 'G' after the 'F's
   string b = a.substr(i);
   return Slump(b);
   // ends with the Slump or 'G'
     
}

bool Slimp(const string& a) {
   if(a.size() < 2) return false;
   if(a[0] != 'A') return false;
   if(a.length() == 2) return a[1] == 'H';
   // if second letter is a B,
   if(a[1] == 'B') {
      if(a[a.length() - 1] != 'C') return false;
      return Slimp(a.substr(2, a.length() - 3));
   } else {
      // else then look for the 'G' and call slump(a.substr(1,indexFor'G' + 1) & make sure that next letter is 'C'
      if(a[a.length() - 1] != 'C') return false;
      string::size_type i;
      for(i = 1; i < a.length() && a[i] != 'G'; ++i) {
      }
      if(i == a.length() || i == a.length() - 1) return false;
      string b = a.substr(1, a.length() - 2);
      return Slump(b);
   }
   
}

bool Slurpy(const string& a) {
   bool works = false;
   for(string::size_type i = 1; i < a.length() - 1; ++i) {
      works = works || (Slimp(a.substr(0,i)) && Slump(a.substr(i)));
   }
   return works;
}

int main() {

   int cases;
   cin >> cases;
   cout << "SLURPYS OUTPUT" << endl;
   for(int i = 0; i < cases; ++i) {
      string line;
      cin >> line;
      if(Slurpy(line))
	 cout << "YES" << endl;
      else
	 cout << "NO" << endl;
   }
   cout << "END OF OUTPUT" << endl;

   return 0;
}

