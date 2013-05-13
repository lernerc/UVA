//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 11367
// Description: I use dikstra's algorithm repeatedly on a graph which includes
// the edges for capacity of 100, and with dikstra's algorithm the capacity of
// the tank is passed in aswell and that is used to limit some of the edges
// that cannot be traversed with that certain size tank
//*****************************************************************************

/*
 * Dijkstra's Algorithm for sparse graphs
 *
 * Author: Howard Cheng
 *
 * Given a weight matrix representing a graph and a source vertex, this
 * algorithm computes the shortest distance, as well as path, to each
 * of the other vertices.  The paths are represented by an inverted list,
 * such that if v preceeds immediately before w in a path from the
 * source to vertex w, then the path P[w] is v.  The distances from
 * the source to v is given in D[v] (-1 if not connected).
 *
 * Call get_path to recover the path.
 *
 * Note: Dijkstra's algorithm only works if all weight edges are
 *       non-negative.
 *
 * This version works well if the graph is not dense.  The complexity
 * is O((n + m) log (n + m)) where n is the number of vertices and
 * m is the number of edges.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

// MY CODE
// each node used in the graph is 101 * the city number plus the fuel level
int node(int station, int liters) {
   return station * 101 + liters;
}

int station(int node) {
   return node / 101;
}

int liters(int node) {
   return node % 101;
}

// Howard's Code
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
void dijkstra(const Graph &G, int src, vector<int> &D, vector<int> &P,
	      const int &cost)
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
       if(liters(v) > cost) continue; // added a check for the capacity
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

// My Code

int main(void)
{
   int cost[1000];
   int n, m;
   cin >> n >> m;
   Graph G(n * 101 + 1);
   // reads in the cost of gas at each city and adds the edges for filling up
   // the tank at each city
   for(int i = 0; i < n; ++i) {
      cin >> cost[i];
      for(int j = 1; j < 101; ++j) {
	 G.add_edge(node(i, j - 1), node(i, j), cost[i]);
      }
   }
   int u, v, d;
   // read in the edges and add an edge between each fuel that is possible to
   // go to the next city
   for(int i = 0; i < m; ++i) {
      cin >> u >> v >> d;
      for(int j = d; j < 101; ++j) {
	 G.add_edge(node(u, j), node(v, j - d), 0);
	 G.add_edge(node(v, j), node(u, j - d), 0);	        
      }
   }
   int q;
   cin >> q;
   for(int i = 0; i < q; ++i) {
      int c, s, e;
      cin >> c >> s >> e;
      vector<int> D, P;
      dijkstra(G, node(s, 0), D, P, c);
      if(D[node(e, 0)] >= 0) {
	 cout << D[node(e, 0)] << endl;
      } else {
	 cout << "impossible" << endl;
      }
   }
  return 0;
}

