#include <iostream>
#include <cassert>
#include <limits.h>
#include <iomanip>

using namespace std;

const int MAX_NODES = 51;
const int OPERAS = 13;
// subset and end point
int data[4096][OPERAS];
int dist[MAX_NODES][MAX_NODES];
pair<int, int> opera[OPERAS];

void floyd(const int& n)
{
   int i, j, k;
   
   for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
	 for (j = 0; j < n; j++) {
	    if (dist[i][k] != INT_MIN && dist[k][j] != INT_MIN) {
	       int temp = dist[i][k] + dist[k][j];
	       if (dist[i][j] == INT_MIN || dist[i][j] > temp) {
		  dist[i][j] = temp;
	       }
	    }
	 }
      }
   }
   
   for (i = 0; i < n; i++) {
      dist[i][i] = 0;
   }
}

int recur(int set, int end, const int& p) {
   
   if(data[set][end] != INT_MIN) {
        return data[set][end];
   } else if(set == (1 << end)) { // you are at the end
      return data[set][end] = opera[end].second
	 - dist[0][opera[end].first];      
   } else {
      int high = INT_MIN;
      for(int v = 0; v < p; v++) {
	 int j = (1 << v);
	 int n_set = set - (1 << end);
	 if((n_set & j) && dist[opera[v].first][opera[end].first] != INT_MIN) {
	    high = opera[end].second
	       - dist[opera[v].first][opera[end].first] + recur(n_set, v, p);
	    if(data[set][end] < high || data[set][end] == INT_MIN) {
	       data[set][end] = high;
	    }
	 }
      }
      return data[set][end];
   }
}

int subsets(const int& n, const int& m, const int& p) {

   for(int i = 0; i < 4096; ++i) {
      fill(data[i], data[i] + OPERAS, INT_MIN);
   }
   int max = INT_MIN;
   for(int i = 1; i < (1 << p); ++i) {
      for(int v = 0; v < p; ++v) { 
	 int j = (1 << v);
	 if((j & i) && opera[v].first != INT_MIN) {
	    int temp = recur(i, v, p) - dist[opera[v].first][0];
	    if(temp > max) {
	       max = temp;
	    }
	    //cerr << "i: " << i << " j: " << j << " cost: " << temp << endl;
	 }
      }
   }
   return max;
   
}

int main(void)
{
   int cases;
   cin >> cases;
   for(int z = 0; z < cases; ++z) {
      int n, m;     
      cin >> n >> m;
      /* clear graph */
      for (int i = 0; i < n + 1; i++) {
	 fill(dist[i], dist[i] + n + 1, INT_MIN);
      }
      
      /* read graph */
      for(int q = 0; q < m; ++q) {
	 int i, j;
	 double w;
	 cin >> i >> j >> w;
//	 assert(0 <= i && i < n && 0 <= j && j < n);
	 if((dist[i][j] == INT_MIN) || (dist[i][j] > (int)(w*100.0 + 0.5))) {
	    dist[i][j] = dist[j][i] = (int)(w*100.0 + 0.5);
	 }
      }
            
      floyd(n + 1);

      int p;
      cin >> p;
      fill(opera, opera + p, make_pair(INT_MIN,INT_MIN));
      double price;
      int place;
      for(int i = 0; i < p; ++i) {
	 cin >> place >> price;
	 opera[i] = make_pair(place, (int)(price*100.0 + 0.5));
      }

      // finds the route that save the most money
      int cents = subsets(n + 1, m, p);

      if(cents <= 0) {
	 cout << "Don't leave the house" << endl;
      } else {
	 cout << "Daniel can save $" << cents/100 << "." << setfill('0')
	      << setw(2) << cents%100 << endl;
      }
      
   }


  return 0;
}
