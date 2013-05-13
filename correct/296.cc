//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 296
// Description: I test all the combinations of codes for each case 
//*****************************************************************************
#include <iostream>
#include <string>
using namespace std;

string test[10];
int corr[10];
int off[10];

bool correct(string code, int guesses) {
   for(int w=0;w<guesses;w++) {
      // check if only # of correct is the same
      int offa=0;
      int corra=0;
      string tmp_code=code;
      string tmp_guess=test[w];

      for(int i=0;i<4;i++) {
	 if(tmp_code[i]==tmp_guess[i]) {
	    corra++;
	    // the exact matching are overwritten, so that they are not counted
	    // again when the mismatched are counted
	    tmp_code[i]='x';
	    tmp_guess[i]='c';
	    
	 }
      }

      for(int i=0;i<4;i++) {
	 for(int j=0;j<4;j++) {
	    if(i!=j && tmp_code[i]==tmp_guess[j]) {
	       // overwrites the mismatched, so that they are not overcounted
	       // if multiples of each number are in the type
	       tmp_guess[j]='z';
	       offa++;
	       break;
	    }
	 }
      }

      if(corra!=corr[w] || offa!=off[w])
	 return false;
   }
   return true;   
}

int main() {
   int cases;
   cin >> cases;
   for(int w=0;w<cases;w++) {
      int guesses;
      cin >> guesses;

      for(int q=0;q<guesses;q++) {
	 char backslash;
	 cin >> test[q] >> corr[q] >> backslash >> off[q];// read in guesses
	 
      }
      int corcases=0;
      string cor;
      // generates all combinations of the codes
      for(int i=0;i<10;i++) {
	 for(int j=0;j<10;j++) {
	    for(int k=0;k<10;k++) {
	       for(int l=0;l<10;l++) {
		  string a=string(1,char('0'+i))+string(1,char('0'+j))+
		     string(1,char('0'+k))+string(1,char('0'+l));
		  if(correct(a,guesses)) {
		     corcases++;
		     cor=a;
		  }
	       }
	    }
	 }
      }
      if(corcases==0) {
	 cout << "impossible" << endl;
      } else if(corcases==1) {
	 cout << cor << endl;
      } else {
	 cout << "indeterminate" << endl;
      }
   }
   return 0;
}
