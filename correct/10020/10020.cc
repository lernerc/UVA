#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> line[100001];

int main() {
   int cases;
   cin >> cases;
   int L, M, maxR, num;
   vector<int> sol;
   while(cases--) {
      sol.clear();
      maxR = num=L=0;
      cin >> M;
      int size = 0;
      while(cin >> line[size].first >> line[size].second &&
	    (line[size].second!=0 || line[size].first!=0)) {
	 size++;
      }
      sort(line, line+size);
      
      int i = 0, goal = -1;
      bool stop = false;
      while(i < size && maxR < M && !stop) {
	 stop = true;
	 while(i < size && line[i].first <= L) {
	    if(line[i].second > maxR) {
	       maxR = line[i].second;
	       goal = i;
	    }
	    i++;
	 }
	 if(maxR > L) {
	    num++;
	    L = maxR;
	    sol.push_back(goal);
	    stop = false;
	 }
      }
/*      if(maxR > L && solline[size-1].second == maxR) {
	 num++;
	 sol.push_back(line[size-1]);
      }
*/
      if(maxR < M) {
	 cout << 0 << endl;
      } else {
	 cout << num << endl;
	 for(int i = 0; i < (int)sol.size(); i++) 
	    cout << line[sol[i]].first << " " << line[sol[i]].second << endl;
      }
      if(cases != 0)
	 cout << endl;
   }
   return 0;
}
