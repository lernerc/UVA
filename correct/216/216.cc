#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int ans[8] = {0, 1, 2, 3, 4, 5, 6, 7};
double com_dist[7];
double totDist = 0;

double dist_sqr(const pair<int, int>& a, const pair<int, int>& b) {
   double first =  a.first - b.first;
   double second = a.second - b.second;
   return first*first + second*second;      
}

double dist(const pair<int, int>& a, const pair<int, int>& b) {
   return sqrt(dist_sqr(a, b)) + 16.0;
}

void evaluate(const int perm[8], const pair<int, int> coordinates[8],
	      const int& n) {
   double t_dist[7];
   double t_totDist = 0;
   for(int i = 1; i < n; i++) {
      t_totDist += (t_dist[i - 1] =
		    dist(coordinates[perm[i]], coordinates[perm[i - 1]]));
   }
   if((t_totDist < totDist) || (totDist == 0)) {
      copy(perm, perm + n, ans);
      copy(t_dist, t_dist + n - 1, com_dist);
      totDist = t_totDist;
   }
}

void permutations(const pair<int, int> coordinates[8], const int& n,
		  int perm[8], int k = 0) {
   if(k == n) {
      evaluate(perm, coordinates, n);
      return;
   }
   
   for(int i = k; i < n; ++i) {
      swap(perm[i], perm[k]);
      permutations(coordinates, n, perm, k + 1);
      swap(perm[i], perm[k]);
   }
   
}

int main() {

   int cases = 1;
   int n;
   while(cin >> n && n != 0) {
      totDist = 0;
      pair<int, int> coordinates[8];
      int perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};
      for(int i = 0; i < n; ++i) {
	 cin >> coordinates[i].first >> coordinates[i].second;
      }

      permutations(coordinates, n, perm);
      
      cout << "**********************************************************"
	   << endl;
      cout << "Network #" << cases++ << endl;
      cout << fixed << setprecision(2);
      for(int i = 1; i < n; ++i) {
	 cout << "Cable requirement to connect ("
	      << coordinates[ans[i - 1]].first << ","
	      << coordinates[ans[i - 1]].second << ") to ("
	      << coordinates[ans[i]].first <<","
	      << coordinates[ans[i]].second << ") is "
	      << com_dist[i - 1] << " feet." << endl;
	    }
      cout << "Number of feet of cable required is " << totDist << "." << endl;
   }
   
   return 0;
}
