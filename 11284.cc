#include <iostream>
#include <cassert>
#include <limits.h>

using namespace std;

const int MAX_NODES = 50;

// subset and end point
int data[4096][12];
int dist[MAX_NODES][MAX_NODES];
pair<int, int> opera[12];

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

int recur(int set, int v, const int& n) {
   
   if(data[set][v] != INT_MIN) {
      return data[set][v];
   } else if() { // 

   }
   

   
}

int subsets(const int& n, const int& m, const int& p) {

   for(int i = 0; i < 4096; ++i){
      fill(data[i], data[i] + 12, INT_MIN);
   }
   int max = INT_MIN;
   for(int i = 0; i < (1 << p); ++i) {
      for(int v = 0; v < 12; ++v) {
	 int j = 1 << v;
	 if(j ( i)) {
	    int temp = recur(i, v, n);
	    if(temp > max) {
	       max = temp;
	    }
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
      for (int i = 0; i < n; i++) {
	 for (int j = 0; j < n; j++) {
	    dist[i][j] = INT_MIN;
	 }
      }
      

      /* read graph */
      
      for(int q = 0; q < m; ++q) {
	 int i, j;
	 double w;
	 cin >> i >> j >> w;
//	 assert(0 <= i && i < n && 0 <= j && j < n);
	 dist[i][j] = dist[j][i] = (int)(w*100 + 0.5);
      }
      
      
      floyd(n);

      int p;
      double price;
      for(int i = 0; i < p; ++i) {
	 cin >> opera[i].first >> price;
	 opera[i].second = (int)(price*100 + 0.5);
      }
      
      int cents = subsets(n, m, p);
      
   }


  return 0;
}
