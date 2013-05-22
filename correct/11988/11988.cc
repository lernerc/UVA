#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
   string line;
   while(getline(cin, line)) {
      list<char> output;
      list<char>::iterator it = output.begin();
      for(string::size_type i = 0; i < line.size(); ++i) {
	 if(line[i] == '[') {
	    it = output.begin();
	 } else if(line[i] == ']') {
	    it = output.end();
	 } else {
	    it = output.insert(it, line[i]);
	    it++;
	 }
      }
      for(it = output.begin(); it != output.end(); it++) {
	 cout << *it;
      }
      cout << endl;
   }
   return 0;
}
