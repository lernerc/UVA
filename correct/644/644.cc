#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string codes[9];
int cases = 0;

void checkCode(const int &size) {

   /*
     cerr << "size: " << size << endl;
   for(int i = 0; i < size; i++) {
      cerr << codes[i] << endl;
   }
   */
   bool dec = true;
   for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
	 if(i == j) continue;
	 int w = codes[j].find(codes[i]);
	 if(w == 0) {
	    dec = false;
	 }
      }
   }
   if(dec) {
      cout << "Set " << cases << " is immediately decodable" << endl;
   } else {
      cout << "Set " << cases << " is not immediately decodable" << endl;
   }
}

int main() {

   string line;
   int w = 0;
   while(getline(cin, line)) {
      istringstream iss(line);
      while(iss >> codes[w]) {
	 if(codes[w] == "9") {
	    cases++;
	    checkCode(w);
	    w = 0;
	 } else {
	    w++;
	 }
      }
   }
   
   return 0;
}
