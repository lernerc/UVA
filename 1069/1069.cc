#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {

   int cases = 1;
   string line;
   while(getline(cin, line) && line != ".") {
      cout << "Case " << cases++ << ": ";
      int sum = 0, tmp = 1;
      int sign = 1;
      int i = 0;
      bool numStarted = false;
      int constant = 0;
      while(i < (int)line.size() && line[i] != ')') {
	 switch(line[i]) {
	    case '-':
	       if(numStarted)
		  constant += tmp;
	       numStarted = false;
	       tmp = -1;
	       sign = -1;
	       i++;
	       break;
	    case '+':
	       if(numStarted)
		  constant += tmp;
	       numStarted = false;
	       tmp = 1;
	       sign = 1;
	       i++;
	       break;
	    case '0': case '1': case '2': case '3': case '4': case '5':
	    case '6': case '7': case '8': case '9':
	       if(numStarted) {
		  tmp *= 10;
		  tmp += sign*(line[i] - '0');
	       } else {
		  tmp *= (line[i] - '0');
	       }
	       numStarted = true;
	       i++;
	       break;
	    case '(':
	       numStarted = false;
	       sign = 1;
	       i++;
	       break;
	    case 'n':	
	       sum += tmp;
	       numStarted = false;
	       while(line[i] != ')'&& (isdigit(line[i]) || line[i] == '^'
				       || line[i] == 'n')) {
		  i++;
	       }
	       break;
	    default:
	       i++;
	 }
      }
      if(numStarted) {
	 constant += tmp;
      }
      int den = 1;
      i++;
      numStarted = false;
      while(i < (int)line.size()) {
	 switch(line[i]) {
	    case '-': case '+':
	       den = 1;
	       i++;
	       break;
	    case '0': case '1': case '2': case '3': case '4': case '5':
	    case '6': case '7': case '8': case '9':
	       if(numStarted) {
		  den *= 10;
		  den += line[i] - '0';
	       } else {
		  den *= line[i] - '0';
	       }
	       numStarted = true;
	       i++;
	       break;
	    default:
	       i++;
	 }  
      }
      sum = abs(sum);
      if(sum % den == 0 && constant % den == 0) {
	 cout << "Always an integer" << endl;
      } else {
	 cout << "Not always an integer" << endl;
      }
   }
   
   return 0;
}
