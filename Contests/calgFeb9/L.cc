#include <iostream>
#include <string>
using namespace std;

const string vowels="aiyeou";
const string VOWELS="AIYEOU";
const string constan="bkxznhdcwgpvjqtsrlmf";
const string CONSTAN="BKXZNHDCWGPVJQTSRLMF";

char vo(int vow,string vowels) {
   if(vow>=3) {
      return vowels[(vow+3)%6];
   }
   else
   {
      return vowels[vow+3];
   }
}

char co(int vow,string constan) {
   if(vow>=9) {
      return constan[(vow+10)%20];
   }
   else
   {
      return constan[vow+10];
   }
}

int main() {
   string line;
   while(getline(cin,line)) {
      string output=line;
      for(string::size_type i=0;i<line.size();i++) {
	 string::size_type vow=vowels.find(line[i]);
	 string::size_type VOW=VOWELS.find(line[i]);
	 string::size_type cons=constan.find(line[i]);
	 string::size_type CONS=CONSTAN.find(line[i]);
	 if(vow!=string::npos) {
	    output[i]=vo(vow,vowels);
	 } else if(VOW!=string::npos) {
	    output[i]=vo(VOW,VOWELS);
	 } else if(cons!=string::npos) {
	    output[i]=co(cons,constan);
	 } else if(CONS!=string::npos) {
	    output[i]=co(CONS,CONSTAN);
	 }
	      
      }
      cout << output << endl;
      
   }
   
   return 0;
}
