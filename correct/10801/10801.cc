#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

const int MAX_NODES = 500;
const int DISCONNECT = -1;

//int graph[MAX_NODES][MAX_NODES];
//int dist[MAX_NODES][MAX_NODES];

int speed[5];
int stops[5][100];

struct Edge {
  int to;
  int weight;       // can be double or other numeric type
  Edge(int t, int w)
    : to(t), weight(w) { }
};
  
typedef vector<Edge>::iterator EdgeIter;

struct Graph {
  vector<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new vector<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: There is no check on duplicate edge, so it is possible to
  // add multiple edges between two vertices
  //
  // If this is an undirected graph, be sure to add an edge both
  // ways
  void add_edge(int u, int v, int weight)
  {
    nbr[u].push_back(Edge(v, weight));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<int> &D, vector<int> &P)
{
  typedef pair<int,int> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;

  D.resize(n);
  P.resize(n);
  fill(D.begin(), D.end(), -1);
  fill(P.begin(), P.end(), -1);

  D[src] = 0;
  used[src] = true;
  for (EdgeIter it = G.nbr[src].begin(); it != G.nbr[src].end(); ++it) {
    int v = it->to;
    D[v] = it->weight;
    P[v] = src;
    fringe.push(make_pair(D[v], v));
  }

  while (!fringe.empty()) {
    pii next = fringe.top();
    fringe.pop();
    int u = next.second;
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      int weight = it->weight + next.first;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

int get_path(int v, const vector<int> &P, vector<int> &path)
{
  path.clear();
  path.push_back(v);
  while (P[v] != -1) {
    v = P[v];
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  return path.size();
}

/*void floyd(void)
{
  int i, j, k;

  for (i = 0; i < MAX_NODES; i++) {
    for (j = 0; j < MAX_NODES; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (k = 0; k < MAX_NODES; k++) {
    for (i = 0; i < MAX_NODES; i++) {
      for (j = 0; j < MAX_NODES; j++) {
        if (dist[i][k] != DISCONNECT && dist[k][j] != DISCONNECT) {
          int temp = dist[i][k] + dist[k][j];
          if (dist[i][j] == DISCONNECT || dist[i][j] > temp) {
            dist[i][j] = temp;
          }
        }
      }
    }
  }

  for (i = 0; i < MAX_NODES; i++) {
    dist[i][i] = 0;
  }
}
*/

int main() {

   int elv, floor;
   while(cin >> elv >> floor) {
      Graph G(elv*100);
      for(int i = 0; i < elv; i++) {
	 cin >> speed[i];
      }
      string line;
      // blankline
      getline(cin, line);
      int pre = DISCONNECT, next;
      for(int i = 0; i < elv; i++) {
	 fill(stops[i], stops[i] + 100, false);
	 getline(cin, line);
	 pre = DISCONNECT;
	 istringstream iss(line);
	 while(iss >> next) {
	    if(pre == DISCONNECT) {
	       pre = next;
	       stops[i][next] = true;
	       continue;
	    }
	    stops[i][next] = true;
	    G.add_edge(i*100 + pre, i*100 + next, (next - pre)*speed[i]);
	    G.add_edge(i*100 + next, i*100 + pre, (next - pre)*speed[i]);
	    // cerr << "(" << i*100 + pre << ", " <<  i*100 + next << ") " <<
	    //   (next - pre)*speed[i] << endl;
	    pre = next;
	 }
      }
      int i = 0;
      for(int j = 0; j < elv; j++) {
	 for(int k = j + 1; k < elv; k++) {
	    if(stops[j][i] && stops[k][i]) {
	       G.add_edge(j*100 + i, k*100 + i, 0);
	       G.add_edge(k*100 + i, j*100 + i, 0);
	    }
	 }
      }
      for(int i = 1; i < 100; i++) {
	 for(int j = 0; j < elv; j++) {
	    for(int k = j + 1; k < elv; k++) {
	       if(stops[j][i] && stops[k][i]) {
		  G.add_edge(j*100 + i, k*100 + i, 60);
		  G.add_edge(k*100 + i, j*100 + i, 60);
		  //  cerr << "(" << j*100 + i << ", " << k*100 + i << ") " <<
		  // 60 << endl;
	       }
	    }
	 }
      }

      //  floyd();

      int dist = DISCONNECT;
      int tmp;
      for(int i = 0; i < elv; i++) {
	 for(int j = 0; j < elv; j++) {
	    vector<int> D, P;
	    dijkstra(G, i*100,  D, P);
	    tmp = D[j*100 + floor];
	    if(tmp == DISCONNECT) continue;
	    if(dist != DISCONNECT && tmp < dist) {
	       dist = tmp;
	    } else if(dist == DISCONNECT) {
	       dist = tmp;
	    }
	 }
      }
      /*    for(int src = 0; src < elv*100; src++) {
	 for (EdgeIter it = G.nbr[src].begin(); it != G.nbr[src].end(); ++it) {
	    cerr << "(" << src << ", " << it->to << ") " << it->weight << endl; 
	 }
	 }*/
      
      
      if(dist == DISCONNECT) {
	 cout << "IMPOSSIBLE" << endl;
      } else {
	 cout << dist << endl;
      }
      
   }
   return 0;
}
