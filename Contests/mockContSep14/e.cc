#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

string exceptions[] = {"midnight", "noon"};

const int MAX_ZONE = 32;

const string TimeZone[MAX_ZONE] = {"UTC", "GMT", "BST", "IST", "WET", "WEST", "CET",
			 "CEST", "EET", "EEST", "MSK", "MSD", "AST", "ADT",
			 "NST", "NDT", "EST", "EDT", "CST", "CDT", "MST",
			 "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST",
			 "AEDT", "ACST", "ACDT", "AWST"};
const double UTCoff[MAX_ZONE] = {0,     0,     1,     1,     0,      1,     1,
			   2,    2,     3,     3,     4,    -4,     -3,
			   -3.5,  -2.5,    -5,   -4,     -6,     -5,     -7,
			   -6,      -8,    -7,    -10,     -9,     -8,     10,
			   11,    9.5,   10.5,     8};

const string morn[] = {"a.m.", "p.m."};

struct Time {
public:
   Time() {special = false;}
   Time(istringstream& iss);
   string next(const string &zone);
   int hours, mins;
   bool special;
   string name;
   string zone;
};
Time::Time(istringstream& iss) {
   string time;
   iss >> time;
   special = false;
   for(int i = 0; i < 2; i++) {
      if(time == exceptions[i]) {
	 special = true;
	 hours = mins = 0;
	 name = exceptions[i];
	 if(name == "noon")
	    hours += 12;
      }
   }
   if(!special) {
      // fill numbers and put in name
      istringstream num(time);
      char garbage;
      num >>  hours >> garbage >> mins;
      iss >> time;
      if(time == "p.m." && hours != 12)
	 hours += 12;
      if(time == "a.m." && hours == 12)
	 hours = 0;
   }
   iss >> zone;

/*   if(!special) {
      if(hours == 0 || hours == 12) {
	 cerr << 12;
      } else { 
	 cerr << hours%12;
      }
      cerr << ':' << setfill('0') << setw(2) << mins << " " << morn[hours/12];
   } else {
      cerr << name;
   }
   cerr << " (start)" << endl;
*/
}

int find(const string & me) {
   for(int i = 0; i < MAX_ZONE; i++) {
      if(me == TimeZone[i])
	 return i;
   }
   return MAX_ZONE;
}

string Time::next(const string &next) {
   int a = find(zone);
   int b = find(next);
   if(a >= MAX_ZONE || b >= MAX_ZONE) {
      cerr << zone << " or " << next << " did not work" << endl;
      exit(1);
   }
   double diff = UTCoff[b] - UTCoff[a] + 24;
   hours = hours + (int)floor(diff);
   if(abs(diff - floor(diff)) > 0.2) {
        if(diff == abs(diff)) {
	   mins += 30;
	} else {
	   mins -= 30;
	}
   }
   while(mins < 0) {
      hours -= 1;
      mins += 60;
   }
   
  hours += mins/60;
  while(hours < 0) {
     hours += 24;
  }
  
  hours %= 24;
  mins %= 60;
  special = false;
   if((hours%12 == 0 && mins == 0)) {
      special = true;
      if(hours % 24 == 0)
	 name = "midnight";
      else
	 name = "noon";
   }
   ostringstream oss;
   if(!special) {
      if(hours == 0 || hours == 12) {
	 oss << 12;
      } else { 
	 oss << hours%12;
      }
      oss << ':' << setfill('0') << setw(2) << mins << " " << morn[hours/12];
   } else {
      oss << name;
   }
   return oss.str();
}

int main() {
   string next;
   int n;
   cin >> n;
   string blank, line;
   getline(cin, blank);
   for(int i = 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line);
      Time a(iss);
      iss >> next;
      cout << a.next(next) << endl;
   }
   
   return 0;
}
