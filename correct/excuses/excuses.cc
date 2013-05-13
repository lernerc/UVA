//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 409
// Description: Counting occurance of keys in lines of text and outputing the
// line with the most occurances of the keys 
//*****************************************************************************

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//lowercase letters only and maxlength 20
string keywords[20];
//will contain at least one non-space character, and maxlength 70
string excuses[20];
string excusesl[20];
int count[20];

int main()
{
   int k,e;
   int set=1;
   while(cin >> k >> e)
   {
      // read in keywords
      for(int i=0;i<k;i++) {
	 keywords[i].clear();
	 cin >> keywords[i];
      }
      string blankline;
      getline(cin,blankline);
      // read in excuses
      for(int i=0;i<e;i++) {
	 excuses[i].clear();
	 count[i]=0;
	 getline(cin,excuses[i]);
	 excusesl[i]=excuses[i];
	 for(int w=0;w<excuses[i].size();w++) {
	    excusesl[i][w]=tolower(excuses[i][w]);
	 }
      }
      
      //process data
      for(int j=0;j<e;j++) {
	 for(int i=0;i<k;i++) {
	    for(int w=0;w<=excusesl[j].size()-keywords[i].size();w++) {
	       if(excusesl[j].substr(w,keywords[i].size())==keywords[i]) {
		  // boundry cases for when a word is inside another word
		  if(w>0
		     && w<(excusesl[j].size()-keywords[i].size())) {
		     if((!isalpha(excusesl[j][w-1]))
			&& (!isalpha(excusesl[j][w+keywords[i].size()]))) {
			count[j]++;
		     }
		  }
		  else if(w==0
			  && w<(excusesl[j].size()-keywords[i].size())) {
		     if(!isalpha(excusesl[j][w+keywords[i].size()])) {
			count[j]++;
		     }
		  }
		  else if(w>0
			  && w>=(excusesl[j].size()-keywords[i].size())) {
		     if(!isalpha(excusesl[j][w-1])) {
			count[j]++;
		     }
		  }
		  else if(w==0
			  && w>=(excusesl[j].size()-keywords[i].size())) {
		     count[j]++;
		  }
	       }
	    }
	 }
      }

      int max=count[0];
      for(int i=1;i<e;i++) {
	 if(count[i]>max)
	    max=count[i];
      }
      cout << "Excuse Set #" << set++ << endl;
      for(int i=0;i<e;i++) {
	 if(count[i]==max)
	    cout << excuses[i] << endl;
      }
      cout << endl;
   }
   return 0;
}
