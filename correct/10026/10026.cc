//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10026
// Description: Each job is stored as pair, a double and a string. The double
// has the time divided by the fine for each job and the string holds the job
// number, so that the jobs can be sorted first by the ratio of time over fine
// and then lexicographically by the job number. 
//*****************************************************************************
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
using namespace std;

string convert(int i) {
   string a;
   ostringstream b;
   b << i;
   a=b.str();
   return a;
}

int main() {
   int num;
   cin >> num;
   for(int w=0;w<num;w++) {
      if(w!=0) {
	 cout << endl;
	       }
      vector<pair<double, string> > job;
      int caseload;
      cin >> caseload;
      for(int i=1;i<=caseload;i++) {
	 double time,fine;
	 cin >> time >> fine;
	 // since all values are gauranteed to be greater than zero, division
	 // can be used
	 job.push_back(make_pair(time/fine,convert(i)));
      }
      sort(job.begin(),job.end());
      cout << job[0].second;
      for(vector<pair<double, string> >::size_type i=1;i<job.size();i++) {
	 cout << " " << job[i].second;
      }
      cout << endl;

   }
   return 0;
      
}
 
