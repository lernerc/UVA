#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_PRBLM = 10;
const int MAX_TEAM = 101;

class team {
public:
   friend ostream& operator<<(ostream& os, const team& a);
   team() {}
   void makeEmpty() {
      num = numsol = time = 0;
      for(int i = 0; i < MAX_PRBLM; ++i) {
	 prblm[i] = 0;
	 solved[i] = false;
	 submit = false;
      }
   }
   int num, numsol, time;
   bool solved[MAX_PRBLM];
   int prblm[MAX_PRBLM];
   bool submit;
   bool operator<(const team& a) const {
      if( numsol != a.numsol) {
	 return numsol > a.numsol;
      } else if(time != a.time) {
	 return time < a.time;
      } else {
	 return num < a.num;
      }
   }
   void doSomething(char L, int numprblm, int subtime) {
      if(L == 'C') {
	 if(solved[numprblm]) return;
	 solved[numprblm] = true;
	 time += subtime + 20*prblm[numprblm];
	 numsol++;
      } else if(L == 'I') {
	 prblm[numprblm]++;
      } else {
      }
      submit = true;
      return;
   }
};

ostream& operator<<(ostream& os, const team& a) {
   os << a.num << " " << a.numsol << " " << a.time;
   return os;
}

int main() {
   team alive[MAX_TEAM];
   int cases;
   cin >> cases;
   string blankline;
   getline(cin, blankline);
   getline(cin, blankline);
   for(int q = 0; q < cases; q++) {
      if(q != 0) {
	 cout << endl;
      }
      string line;
      for(int i = 0; i < MAX_TEAM; ++i) {
	 alive[i].makeEmpty();
	 alive[i].num = i;
      }
      int num, prblm, time;
      char L;
      while(getline(cin, line) && !line.empty()) {
	 istringstream iss(line);
	 iss >> num >> prblm >> time >> L;
	 alive[num].doSomething(L, prblm, time);
      }
      sort(alive, alive + MAX_TEAM);
      for(int i = 0; i < MAX_TEAM; ++i) {
	 if(alive[i].submit) {
	    cout << alive[i] << endl;
	 }
      }
   }
   return 0;
}
