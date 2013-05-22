#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SET = 21;


// A^2  = A * A s.t. A * A (i,j) = max(k = 1, ..., n) A(i,k) * A(k,j)
// store the k
// then look along diangonal with a value greater than 1.01
// A^l(i,j) = max(k = 1, ..., n)A(i,k) * A^(l-1)(k, j)

void multiply(const double A[MAX_SET][MAX_SET],
	      const double B[MAX_SET][MAX_SET],
	      const int& n,
	      int trace[MAX_SET][MAX_SET],
	      double ans[MAX_SET][MAX_SET]) {
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
	 double max = 0;
	 for(int k = 0; k < n; ++k) {
	    if(max < A[i][k] * B[k][j]) {
	       max = ans[i][j] = A[i][k] * B[k][j];
	       trace[i][j] = k;
	    }
	 }
      }
   }
}

bool check(double matrix[MAX_SET][MAX_SET], const int& n, int& i, int& j) {
   for(int w = 0; w < n; ++w) {
      // cout << "matrix[ " << w << " ][ " << w << " ] = " << matrix[w][w] << endl;
      if(matrix[w][w] >= 1.01) {
	 j = w;
	 i = w;
	 return true;
      }
      
   }
   return false;
}

int main() {

   double Apow[MAX_SET][MAX_SET][MAX_SET];
   int trace[MAX_SET][MAX_SET][MAX_SET];
   int n;
   while(cin >> n) {
      for(int i = 0; i < n; ++i) {
	 for(int j = 0; j < n; ++j) {
	    if(i == j) {
	       Apow[0][i][j] = 1.0;
	    } else {
	       cin >> Apow[0][i][j];
	    }
	    trace[0][i][j] = i;
	 }
      }

      int pow = 1;
      int i, j;
      for( ; pow < n; ) {
	 //cout << "power = " << pow << endl;
	 multiply(Apow[0], Apow[pow - 1], n, trace[pow], Apow[pow]);
	 pow++;
	 if(check(Apow[pow - 1], n, i ,j)) {
	    break;
	 }
	 
      }
      // cout << pow << endl;

      if(check(Apow[pow-1], n, i, j)) {
	 //cerr << "i = " << i <<", j = " << j << endl;
	 //cerr << "max: " <<  Apow[pow-1][i][j] << endl;
	 vector<int> path(pow);
	 path[0] = i;
	 for(int w = pow - 1; w > 0; --w) {
	    /*cerr << "pow: " << w << " i = " << i << " j = " << j << endl;
	    for(int q = 0; q < n; ++q) {
	       for(int k = 0; k < n; ++k) {
		  cerr << trace[w][q][k] << " ";
	       }
	       cerr << endl;
	    }
	    cerr << endl;
	    */
	    path[w] = trace[w][i][j];
	    i = path[w];
	 }
	 cout << path[0] + 1;
	 for(int i = pow - 1 ; i >= 0; --i) {
	    cout << " " << path[i] + 1;
	 }
	 cout << endl;
	 
      } else {
	 cout << "no arbitrage sequence exists" << endl;
      }
    
   }
   return 0;
}

