//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10415
// Description: figuring out how many times you press down the keys of an
// instrument during a song
//*****************************************************************************

#include <iostream>
using namespace std;

// strings for the 10 fingers 0 means the finger off the key and 1 means the finger is holding it down
string finger[256];

int main() {
   unsigned char key='c';
   finger[key]="0111001111";
   key='d';
   finger[key]="0111001110";
   key='e';
   finger[key]="0111001100";
   key='f';
   finger[key]="0111001000";
   key='g';
   finger[key]="0111000000";
   key='a';
   finger[key]="0110000000";
   key='b';
   finger[key]="0100000000";
   key='C';
   finger[key]="0010000000";
   key='D';
   finger[key]="1111001110";
   key='E';
   finger[key]="1111001100";
   key='F';
   finger[key]="1111001000";
   key='G';
   finger[key]="1111000000";
   key='A';
   finger[key]="1110000000";
   key='B';
   finger[key]="1100000000";

   int t;
   cin >> t;
   {
      string blankline;
      getline(cin,blankline);
   }
   for(int i=0;i<t;i++) {
      string song;
      getline(cin,song);
      string last=string(10,'0');
      // counts how many times the keys are pressed
      int keys[10]={0,0,0,0,0,0,0,0,0,0};
      for(string::size_type k=0;k<song.size();k++) {
	 unsigned char key=song[k];
	 string next=finger[key];
	 for(int j=0;j<10;j++) {
	    if(last[j]=='0' && next[j]=='1')
	       keys[j]+=1;
	 }
	 last=next;     
      }
      for(int j=0;j<9;j++) {
	 cout << keys[j] << ' ';	 
      }
      cout << keys[9] << endl;
   }
   return 0;
}

