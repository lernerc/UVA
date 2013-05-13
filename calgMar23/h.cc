#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

class nota {
public:
   nota() {

   }
   nota(const string& q) {
      istringstream iss(q);
      string e, f, g, h;
      for(int i = 0; i < 4; i++) {
	 string e;
	 getline(iss, e, '.');
	 a[i] = atoi(e.c_str());
      }
   }

   void next() {
      int carry = 1;
      for(int i = 3; i >= 0; --i) {
	 a[i] = a[i] + carry;
	 
	 if(a[i] > 255) {
	    a[i] = 0;
	    carry = 1;
	 } else {
	    carry = 0;
	 }
      }
   }

   bool operator<(const nota& b) const {
      for(int i = 0; i < 4; ++i) {
	 if( a[i] != b.a[i])
	    return a[i] < b.a[i];
      }
      return false;
   }

   bool operator==(const nota& b) const {
      for(int i = 0; i < 4; ++i) {
	 if( a[i] != b.a[i])
	    return false;
      }
      return true;
   }

   bool operator<=(const nota& b) const {
      return ((*this) < b) || ((*this) == b);
   }
   void output() {
      bool isBegin = true;
      for(int i = 0; i < 4; i++) {
	 if(!isBegin) {
	    cout << '.';
	 }
	 isBegin = false;
	 cout << a[i];
      }
   }
   int a[4];
};

bool isNota(string a) {
   istringstream iss(a);
   for(int i = 0; i < 3; i++) {
      string next;
      if(!getline(iss,next, '.')) {
	 return false;
      }
   }
   return true;
}

//*****************************************************************************

int main() {

/*
  nota a("127.0.0.1");
  a.output();
  cout << endl;
  a.next();
  a.output();
  cout << endl;
//*/
   
//  /*
   int cases;
   cin >> cases;
   for(int q = 0; q < cases; q++) {
      pair< pair<nota, nota>, string> myMaps[1000];
      //map<nota, string> myMap;
      int m;
      cin >> m;
      string blankline;
      getline(cin, blankline);
      for(int s = 0; s < m; s++) {
	 string line;
	 getline(cin, line);
	 istringstream iss(line);
	 string word, ip;
	 iss >> word >> ip;
	 nota beg(ip);
	 nota end(ip);
	 if(iss >> ip)
	 end = nota(ip);
	 myMaps[s].first.first = beg;
	 myMaps[s].first.second = end;
	 myMaps[s].second = word;
	 /* for(; beg <= end; beg.next()) {
	    myMap[beg] = word;
            if(beg == nota("255.255.255.255")) {
	       break;
	    }
	    }
	 */
      }
      int t;
      cin >> t;
      getline(cin, blankline);	      
      for(int s = 0; s < t; s++) {
	 string line;
	 getline(cin, line);
	 istringstream iss(line);
	 string next;
	 bool isBegin = true;
	 while(iss >> next) {
	    if(!isBegin) {
	       cout << ' ';
	    }
	    isBegin = false;
	    if(isNota(next)) {
	       nota a(next);
	       bool inRange = false;
	       int index;
	       for(int i = 0; i < m; i++) {
		  if( (!(a < myMaps[i].first.first))
		      && (a <= myMaps[i].first.second)) {
		     index = i;
		     inRange = true;
		  }
	       }//    map<nota, string>::iterator i = myMap.find(a);
	       if(inRange) {
		  cout << myMaps[index].second;
	       } else {
		  a.output(); 
	       }
	    } else {
	       cout << next;
	    }
	 }
	 cout << endl;
      }
      
   }
   //*/
   return 0;
}
