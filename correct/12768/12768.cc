/*
 * Bellman-Ford Shortest Path Algorithm
 *
 * Author: Howard Cheng
 *
 * Given a weight matrix representing a graph and a source vertex, this
 * algorithm computes the shortest distance, as well as path, to each
 * of the other vertices.  The paths are represented by an inverted list,
 * such that if v preceeds immediately before w in a path from the
 * source to vertex w, then the path P[w] is v.  The distances from
 * the source to v is given in D[v] (DISCONNECT if not connected).
 *
 * Call get_path to recover the path.
 *
 * Note: the Bellman-Ford algorithm has complexity O(n^3), but it works even
 *       when edges have negative weights.  As long as there are no negative
 *       cycles the computed results are correct.
 *
 *       We can make this O(n*m) if we use an adjacency list representation.
 *
 *       This works for directed graphs too.
 *
 *       You can use this to detect negative cycles too.  See code.
 *
 */

#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

const int MAX_NODES = 100;
const int DISCONNECT = INT_MAX;

/* assume that D and P have been allocated */
bool bellmanford(int graph[MAX_NODES][MAX_NODES], int n, int src,
		 int D[], int P[])
{
  int v, w, k;
  bool infinite_loop = false;
  for (v = 0; v < n; v++) {
    D[v] = INT_MAX;
    P[v] = -1;
  }
  D[src] = 0;

  for (k = 0; k < n-1; k++) {
    for (v = 0; v < n; v++) {
      for (w = 0; w < n; w++) {
	if (graph[v][w] != DISCONNECT && D[v] != INT_MAX) {
	  if (D[w] == INT_MAX || D[w] > D[v] + graph[v][w]) {
	    D[w] = D[v] + graph[v][w];
	    P[w] = v;
	  } else if (D[w] == D[v] + graph[v][w]) {
	    /* do some tie-breaking here */
	  }
	}
      }
    }
  }

  /* the following loop is used only to detect negative cycles, not */
  /* needed if you don't care about this                            */
  for (v = 0; v < n; v++) {
    for (w = 0; w < n; w++) {
      if (graph[v][w] != DISCONNECT && D[v] != INT_MAX) {
        if (D[w] == INT_MAX || D[w] > D[v] + graph[v][w]) {
	   infinite_loop = true;
/* if we get here then there is a negative cycle somewhere */
	  /* on the path from src to                                 */
	}
      }
    }
  }
  return infinite_loop;
}

int get_path(int v, int P[], int path[])
{
  int A[MAX_NODES];
  int i, k;

  k = 0;
  A[k++] = v;
  while (P[v] != -1) {
    v = P[v];
    A[k++] = v;
  }
  for (i = k-1; i >= 0; i--) {
    path[k-1-i] = A[i];
  }
  return k;
}

int main(void)
{
  int m, w, num;
  int i, j;
  int graph[MAX_NODES][MAX_NODES];
  int P[MAX_NODES][MAX_NODES], D[MAX_NODES][MAX_NODES];
  int path[MAX_NODES];
  int N, M;
  while( cin >> N >> M and (N != 0 or M != 0)) {
     bool infinite_loop = false;
     /* clear graph */
     for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	   graph[i][j] = DISCONNECT;
	}
     }

     /* read graph */
     for(int q = 0; q < M; q++){
	cin >> i >> j >> w;
	--i; --j;
     	assert(0 <= i && i < MAX_NODES && 0 <= j && j < MAX_NODES);
	graph[i][j] = -w;
     }

     for (i = 0; i < N; i++) {
	if(bellmanford(graph, N, i, D[i], P[i]) and i == 0)
	   infinite_loop = true;
     }
     int minim = 0;
     for(int i = 0; i < N; i++ ) {
	if(D[0][i] < minim) {
	   minim = D[0][i];
	}
     }
     if(infinite_loop)
	cout << "Unlimited!" << endl;
     else
	cout << -minim << endl;
  }
  /* do queries */
  /* cin >> i >> j;
  while (!(i == -1 && j == -1)) {
    assert(0 <= i && i < MAX_NODES && 0 <= j && j < MAX_NODES);
    cout << i << " " << j << ": " << D[i][j] << endl;
    for (m = j; m != -1; m = P[i][m]) {
      cout << " " << m;
    }
    cout << endl;
    num = get_path(j, P[i], path);
    for (m = 0; m < num; m++) {
      cout << " " << path[m];
    }
    cout << endl;
    cin >> i >> j;
  }
  */
  return 0;
}
