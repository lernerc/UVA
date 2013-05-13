//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10511
// Description: The council has very strict rules about how many people each
// group can have go through to the council. So it can be similated as a
// network flow problem, with the clubs putting forward one person, and then
// one person can only go to the parties once, and then the parties can only
// sent less than half the size of the council.
//*****************************************************************************
/*
 * Network Flow
 *
 * Author: Howard Cheng
 *
 * The routine network_flow() finds the maximum flow that can be
 * pushed from the source (s) to the sink (t) in a flow network
 * (i.e. directed graph with capacities on the edges).  The maximum
 * flow is returned.  Note that the graph is modified.  If you wish to
 * recover the flow on an edge, it is in the "flow" field, as long as
 * is_real is set to true.
 *
 * Note: if you have an undirected network. simply call add_edge twice
 * with an edge in both directions (same capacity).  Note that 4 edges
 * will be added (2 real edges and 2 residual edges).  To discover the
 * actual flow between two vertices u and v, add up the flow of all
 * real edges from u to v and subtract all the flow of real edges from
 * v to u.  (In fact, for a residual edge the flow is always 0 in this
 * implementation.)
 *
 * This code can also be used for bipartite matching by setting up an
 * appropriate flow network.
 *
 * The code here assumes an adjacency list representation since most
 * problems requiring network flow have sparse graphs.
 *
 * This is the basic augmenting path algorithm and it is not the most
 * efficient.  But it should be good enough for most programming contest
 * problems.  The complexity is O(f m) where f is the size of the flow
 * and m is the number of edges.  This is good if you know that f
 * is small, but can be exponential if f is large.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>

#include <string>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;


struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  int cap;
  int flow;
  bool is_real;
  EdgeIter partner;
  
  Edge(int t, int c, bool real = true)
    : to(t), cap(c), flow(0), is_real(real)
  {};

  int residual() const
  {
    return cap - flow;
  }
};

struct Graph {
  list<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new list<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, int cap)
  {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      int flow = augmenting_path(G, v, t, path, visited, step+1);
      if (flow == -1) {
	return it->residual();
      } else if (flow > 0) {
	return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
   vector<EdgeIter> path(G.num_nodes);
   vector<bool> visited(G.num_nodes);
   int flow = 0, f;
   
   do {
      fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);
  
  return flow;
}

int main(void)
{
   int cases;
   cin >> cases;
   string lines[1000];
   string blankline;
   getline(cin, blankline);
   string blankline2;
   getline(cin, blankline2);
   for(int f = 0; f < cases; ++f) {
      if(f != 0) {
	 cout << endl;
      }
      // reading in the lines
      int numLine = 0;
      while(getline(cin, lines[numLine]) && (lines[numLine] != blankline) &&
	    (lines[numLine] != blankline2) ) {
	 numLine++;
      }
      string names[1000];
      string clubNames[1000];
      int c = 0;
      // names are from 1 until numLine;
      // clubs are from numLine + 1 till numLine + club.size()
      // party are from numLine + club.size() +1 till
      // numLine + club.size() + party.size()
      map<string, int> club;
      int indexC = numLine + 1;
      map<string, int> party;
      int indexP = numLine + 1;
      // finds the names of the parties and clubs in the input data and
      // initializes the maps with their values and the number that will
      // represent them
      for(int i = 0; i < numLine; ++i ) {
	 string resident, tempParty, tempClub;
	 istringstream iss(lines[i]);
	 iss >> resident >> tempParty;
	 names[i] = resident;
	 map<string, int>::iterator it = party.find(tempParty);
	 if(it == party.end()) {
	    party[tempParty] = indexP++;
	 }
	 while(iss >> tempClub) {
	    map<string, int>::iterator it = club.find(tempClub);
	    if(it == club.end()) {
	       club[tempClub] = indexC++;
	       clubNames[c++] = tempClub;
	    }
	 }
      }
      // The start of the network flow is a node that goes to all the clubs
      Graph G(party.size() + club.size() + numLine + 2);
      for(map<string, int>::iterator it = club.begin(); it != club.end();
	  ++it) {
	 int value = it->second;
	 G.add_edge(0, value, 1);
      }
      // The end of the network flow is a node that all the parties go to
      int end =  club.size() + party.size() + numLine + 1;
      int capacity = (int) ceil(club.size() / 2.0) - 1;
      for(map<string, int>::iterator it = party.begin(); it != party.end();
	  ++it) {
	 int value = it->second += club.size();
	 G.add_edge(value, end, capacity);
      }

      // create the graph
      for(int i = 1; i <= numLine; ++i) {
	 string resident, tempParty, tempClub;
	 istringstream iss(lines[i - 1]);
	 iss >> resident >> tempParty;
	 G.add_edge(i, party[tempParty], 1);
	 while(iss >> tempClub) {
	    G.add_edge(club[tempClub], i, 1);
	 }	 
      }

      int flow = network_flow(G, 0, end);
      
      if(flow < (int)club.size()) {
	 cout << "Impossible." << endl;
      } else {
	 // outputs the people representing the club
	 for(int i = 1 + numLine; i < numLine + (int)club.size() + 1; ++i) {
	    for(EdgeIter it = G.nbr[i].begin(); it != G.nbr[i].end(); ++it) {
	       if(it->is_real && it->flow > 0) {
		  cout << names[it->to - 1] << " "
		       << clubNames[i - numLine - 1] << endl;
	       }
	    }
	 }
      }
   }

  return 0;
}


