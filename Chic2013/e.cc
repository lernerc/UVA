#include <iostream>
#include <vector>
using namespace std;

int dr[5] = {-1,  0, 0, 1, 0};
int dc[5] = { 0, -1, 1, 0, 0};

struct Edge;

typedef vector<Edge>::iterator EdgeIter;

struct Edge {
   int to, cap, flow;
   bool is_real;
   pair<int, int> part;
   EdgeIter partner;

   int residual() const { return cap - flow; }
};

struct Graph {
   vector<vector<Edge>> nbr;
   int num_nodes;
   Graph(int n) : nbr(n), num_nodes(n) {}
   void add_edge_directed(int u, int v, int capacity, int flow, bool real, pair<int, int> p) {
      Edge e = {v, capacity, flow, real, p}; nbr[u].push_back(e);
   }
};

void add_edge_with_capacity_directed(Graph& G, int u, int v, int cap) {
   int U = G.nbr[u].size(), V = G.nbr[v].size();
   G.add_edge_directed(u, v, cap, 0, true, make_pair(v,V));
   G.add_edge_directed(v, u, 0, 0, false, make_pair(u,U));
}

void push_path(Graph& G, int s, int t, const vector<EdgeIter>& path, int flow) {
   for(int i = 0; s != t; s = path[i++]->to)
      if(path[i]->is_real) {
	 path[i]->flow += flow; path[i]->partner->cap += flow;
      } else {
	 path[i]->cap -= flow; path[i]->partner->flow -= flow;
      }
}

int augmenting_path(Graph& G, int s, int t, vector<EdgeIter>&path,
		    vector<bool>& visited, int step = 0) {
   if(s == t) return -1; visited[s] = true;
   for(EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
      int v = it->to;
      if(it->residual() > 0 && !visited[v]) {
	 path[step] = it;
	 int flow = augmenting_path(G, v, t, path, visited, step+1);
	 if(flow == -1) return it->residual();
	 else if (flow > 0) return min(flow, it->residual());
      }
   }
   return 0;
}

int network_flow(Graph& G, int s, int t) {
   for(int i=0;i<G.num_nodes;i++)
      for(EdgeIter it=G.nbr[i].begin(); it != G.nbr[i].end(); ++it)
	 G.nbr[it->part.first][it->part.second].partner = it;
   vector<EdgeIter> path(G.num_nodes);
   int flow = 0, f;
   do {
      vector<bool> visited(G.num_nodes, false);
      if((f = augmenting_path(G, s, t, path, visited)) > 0) {
	 push_path(G, s, t, path, f); flow += f;
      }
   } while(f > 0);
   return flow;
}

int in_ind(int hour, int r, int c, int h, int n) {
   return r*n + c + 1 + 2*hour*n*n+1;
}

int out_ind(int hour, int r, int c, int h, int n) {
   return r*n + c + 1 + (2*hour+1)*n*n;
}

int main() {
   //source = 0
   // sink = 2*(h+1)*n*n+1
   int height[100][100];
   int n = 100, k = 100, h = 24; // hold their max value
   while (cin >> n >> k >> h && ( n!= 0 || k != 0 || h != 0)) {
      Graph G(2*n*n*(h+1)+2);
      for(int i = 0; i < n; i++)
	 for(int j = 0; j < n; j++)
	    cin >> height[i][j];
      int r, c;
      // from in source to 0 hour in node and out node
      for(int i = 0; i < k; i++) {
	 cin >> r >> c;
	 add_edge_with_capacity_directed(G, 0, in_ind(0, r, c, h, n), 1);
	 add_edge_with_capacity_directed(G, in_ind(0, r, c, h, n),
					 out_ind(0, r, c, h, n), 1);
      }
          
      // from hour 1 in node to out node taking into account water level
      for(int hour = 1; hour <= h; hour++) {
	 int flood;
	 cin >> flood;
	 for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++)
	       if(height[i][j] > flood)
		  add_edge_with_capacity_directed(G, in_ind(hour, r, c, h, n),
						  out_ind(hour, r, c, h, n), 1);
      }
          
      // in grid from out node to in node with possible cow moves
      for(int hour = 0; hour < h; hour++)
	 for(int r = 0; r < n; r++)
	    for(int c = 0; c < n; c++) 
	       for(int i = 0; i < 5; i++)
		  if((r+dr[i] >= 0) && (r+dr[i] < n)
		     && (c+dc[i] >= 0) && (c+dc[i] < n))  
		     add_edge_with_capacity_directed(G,
						     out_ind(hour, r, c, h, n),
						     in_ind(hour + 1, r + dr[i],
							    c + dc[i], h, n),
						     1);
      // from last grid to sink
      for(int r = 0; r < n; r++)
	 for(int c = 0; c < n; c++) 
	    add_edge_with_capacity_directed(G, out_ind(h, r, c, h, n),
					    2*(h+1)*n*n+1, 1);
      
      cout << network_flow(G, 0, 2*(h+1)*n*n+1) << endl;
   }
}
