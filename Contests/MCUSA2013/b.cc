#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

   int N, T;
   while(cin >> N >> T) {
      vector<int> p(N, 0);
      bool notequal = true;
      int start = 0;
      while(notequal) {
	 int end = (T%p.size()+start)%p.size();
	 // adding a round
	 for(int i = start; i != end; i = (i+1)%p.size()) 
	    p[i] += T/p.size() + 1;
	 for(int i = end; i != start; i = (i + 1) % p.size())
	    p[i] += T/p.size();
	 if(end == start)
	    for(int i = 0; i < p.size(); i++)
	       p[i] += T/p.size();

	 p.erase(p.begin() + (end-1+p.size())%p.size());
	 int min = INT_MAX;
	 int max = 0;
	 for(int i = 0; i < p.size(); i++) {
	    if(min > p[i])
	       min = p[i];
	    if(max < p[i])
	       max = p[i];
	 }
	 if(min == max) notequal = false;
	 start = (end- 1 + p.size()) % p.size();
      }
      cout << p.size() << " " << p[0] << endl;
   }
   
   return 0;
}
