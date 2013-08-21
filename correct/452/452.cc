#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;

const int MAX_NODES = 27;

class Graph{
public:
   Graph() {
      max_nodes = MAX_NODES;
   }
   int max_nodes;
   int adjm[MAX_NODES][MAX_NODES];
   void clear() {
      for(int i = 0; i < max_nodes; i++) {
	 fill(adjm[i], adjm[i] + max_nodes, -1);
      }
   }
   // v is where the edge ends
   void add_edge(char u, char v, int w) {
      adjm[u - 'A'][v - 'A'] = w;
   }
};

// make each dependency an edge with the weight being the # of days to complete
// traverse graph so that each edge is gone through and keep track of the maximum at each edge, and when they have all been traversed the max is the answer.
// The graph starts from the edge 'Z' + 1, which connects to all the edges without dependencies
Graph G;

int traverse() {
   queue<int> q;
   q.push(26);
   int num[MAX_NODES];
   fill(num, num + MAX_NODES, 0);
   
   while(!q.empty()) {
      for(int i = 0; i < MAX_NODES; i++) {
	 if(G.adjm[q.front()][i] >= 0) {
	    q.push(i);
	    num[i] = max(num[i], num[q.front()] + G.adjm[q.front()][i]);
	 }
      }
      q.pop();
   }
   int ans = 0;
   for(int i = 0; i < G.max_nodes; i++) {
      if(num[i] > ans)
	 ans = num[i];
      // cerr << "num[" << (char)(i+'A') << "]: " << num[i] << endl;
   }
   return ans;
}

int main() {

   int cases;
   cin >> cases;
   string blankline, line;
   getline(cin, blankline);
   getline(cin, blankline);
   char end;
   char start;
   int w;
    bool dependent;
   for(int i = 0; i < cases; i++) {
      if(i != 0) {
	 cout << endl;
      }
      G.clear();
      while(getline(cin, line) && line != blankline) {
	 istringstream iss(line);
	 iss >> end >> w;
	 dependent = false;
	 while(iss >> start) { 
	    G.add_edge(start, end, w);
	    dependent = true;
	 }
	 if(!dependent) {
	    G.add_edge('Z'+ 1, end, w);
	 }
      }
      cout << traverse() << endl;
   }
   
   return 0;
}
