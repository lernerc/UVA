#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

const int MAX = 101;
int polynomial[MAX];

int parseNum(const string &line, int &i) {
   int num = 0;
   int sign = 1;
   bool isNum = false;
   switch(line[i]) {
      case '-':
	 sign = -1;
      case '+':
	 i++;
      break;
   }
   for(; i < (int)line.size() && (isdigit(line[i])); i++) {
      num *= 10;
      num += line[i] - '0';
      isNum = true;
   }
   if(!isNum)
      num = 1;
   return sign*num;
}

int parsing(const string &line, int &degree) {
   int i = 0;
   degree = 0;
   int constant = 0;
   bool isNum = false;
   while(i < (int)line.size() && line[i] != ')' ) {
      int deg = 1;
      switch(line[i]) {
	 case '+': case '-': case '0': case '1': case '2': case '3': case '4':
	 case '5': case '6': case '7': case '8': case '9':
	    if(isNum) {
	       //cerr << "const: " << constant << " deg: 0" << endl;
	       polynomial[0] += constant;
	    }
	    constant = parseNum(line, i);
	    isNum = true;
	    break;
	 case 'n':
	    // figure out power then put it in 
	    i++;
	    if(line[i] == '^') {
	       i++;
	       deg = parseNum(line, i);
	    }
	    if(deg > degree) {
	       degree = deg;
	    }
	    if(!isNum) {
	       constant = 1;
	    }
	    //cerr << "const: " << constant << " deg: " << deg << endl;
	    polynomial[deg] += constant;
	    deg = 0;
	    constant = 0;
	    isNum = false;
	    break;
	 default:
	    i++;
	    break;
      }
   }
   if(isNum) {
      //cerr << "const: " << constant << " deg: 0" << endl;
      polynomial[0] += constant;
   }
   constant = 0;
   i += 2; // ")/"
   return abs(parseNum(line, i));
}

int main() {
   int cases = 1;
   string line;
   // (n+7n^16-7-10n)/5
   while(getline(cin, line) && line[0] != '.') {
      fill(polynomial, polynomial + MAX, 0);
      int degree = 0;
     
      // parse the string putting all the coefficents to the powers in the array
      // and putting the denometer in the variable den 
      int den = parsing(line, degree);
      //cerr << "den: " << den << endl;
      //cerr << "degree: " << degree << endl;
      bool alwaysInt = true;
      /*
      for(int n = 0; n <= degree; n++) {
	 cout << "polynomial[" << n << "]: " << polynomial[n] << endl;
      }
      */
      for(int n = 0; n <= degree; n++) {
	 long long sum = 0;
	 long long multiple = 1;
	 for(int i = 0; i <= degree; i++) {
	    //  cerr << "multiple: " << multiple << " poly: " << polynomial[i]
	    //	 << endl;
	    sum += multiple * (long long)polynomial[i];
	    sum %= den;
	    multiple *= (n % den);
	    multiple %= den;
	 }
//	 cerr << "sum: " << sum << " n: " << n << endl;
	 sum = abs(sum);
	 alwaysInt = alwaysInt && ((sum % den) == 0);
	 if(!alwaysInt) break;
      }
      cout << "Case " << cases++ << ": ";
      if(alwaysInt) {
	 cout << "Always an integer" << endl;
      } else {
	 cout << "Not always an integer" << endl;
      }
   }
   
   return 0;
}