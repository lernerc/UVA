#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      priority_queue<int, vector<int>, greater<int> > list;
      int q, k;
      cin >> q >> k;
      string blankline;
      int total = 0;
      for(int j = 0; j < q; j++) {
	 string line;
	 cin >> line;
	 if(line == "insert") {
	    int number;
	    cin >> number;
	    if(list.size() == 0) {
	       total = number;
	       list.push(number);
	    } else if(list.size() < k) {
	       total = total ^ number;
	       list.push(number);
	    } else {
	       total = total ^ number;
	       list.push(number);
	       total = total ^ list.top();
	       list.pop();
	    }
	    
	 } else { // line == print
	    cout << total << endl;
	 }
      }
   }
   return 0;   
}
