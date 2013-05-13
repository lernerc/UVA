#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;

const int MAX = 256;

int main() {
   long long money[MAX];
   int cases;
   cin >> cases;
   for(int i = 0 ; i < cases; ++i) {
      fill(money, money + MAX, 0);
      int keys;
      cin >> keys;
      string charLine;
      //blank line
      getline(cin, charLine);
      for(int j= 0 ; j < keys; j++) {
	 getline(cin,charLine);
	 int cents;
	 istringstream iss(charLine.substr(1,charLine.size() - 1));
	 iss >> cents;
	 money[(unsigned char)charLine[0]] = cents;
	 //cout << charLine[0] << " " << cents << endl;
      }
      int M;
      cin >> M;
      string line;
      // blankline
      getline(cin, line);
      long long amount = 0; 
      for(int j = 0; j < M; ++j) {
	 getline(cin, line);
	 for(string::size_type w=0; w < line.size(); w++) {
	    amount += money[(unsigned char)line[w]];
	 }
	 //cout << line << endl;
      }
      long long dollars = amount/(long long)100;
      int cent = amount % (long long)100;
      cout << dollars << '.' << setfill('0') << setw(2) << cent
	   << '$' << endl;
   }
   
   return 0;
}
