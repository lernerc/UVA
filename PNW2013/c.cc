#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

map<vector<int>, double > car, mon;

void carlosNumbers(vector<int> &a, int &good, int &bad) {
   good = bad = 0;
   for(int i = 0; i < (int)a.size() - 1; i++) {
      int j= i+1;
      if(a[i] > a[j])
	 bad++;
      else
	 good++;
   }
}

void montyNumbers(vector<int> &a, int &good, int &bad) {
   good = bad = 0;
   for(int i = 0; i < (int)a.size(); i++) {
      for(int j = 0; j < (int)a.size(); j++) {
	 int u = min(i, j);
	 int v = max(i, j);
	 if(a[u] > a[v])
	    bad++;
	 else
	    good++;
	 
      }
   }
}

double Monty(vector<int> &a) {
   if(mon.find(a) != mon.end()) return mon[a];

   int good, bad;
   montyNumbers(a, good, bad);
   // cout << "M, good: " << good << " bad " << bad << endl;
   if(bad == 0) {
      return mon[a] = 0;
   }
   double answer = 0;
   for(int i = 0; i < (int)a.size(); i++) {
      for(int j = 0; j < (int)a.size(); j++) {
	 int u = min(i, j);
	 int v = max(i, j);
	 if(a[u] > a[v]) {
	    swap(a[u], a[v]);
	    answer += 1 + Monty(a);
	    swap(a[u], a[v]);
	 }
      }
   }

   answer += good;
   answer /= (double)bad;
   return mon[a] = answer;
   
}

double Carlos(vector<int> &a) {
   if(car.find(a) != car.end()) return car[a];
   
   int good, bad;
   carlosNumbers(a, good, bad);
   //  cout << "C, good: " << good << " bad " << bad << endl;
   if(bad == 0) {
      return mon[a] = 0;
   }
   double answer = 0;
   for(int i = 0; i < (int)a.size()-1; i++) {
      int j = i+1;
      if(a[i] > a[j]) {
	 swap(a[i], a[j]);
	 answer += 1 + Carlos(a);
	 swap(a[i], a[j]);
      }
   }

   answer += good;
   answer /= (double)bad;

   return car[a] = answer;
   
}


void doCases() {
   int N;
   cin >> N;
   vector<int> array(N);
   for(int i = 0; i < N; i++) {
      cin >> array[i];
   }
   mon.clear();
   double monty = Monty(array);
   car.clear();
   double carlos = Carlos(array);

   cout << fixed << setprecision(6) << "Monty " << monty << " Carlos " << carlos
	<< endl;
}

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      doCases();
   }
   
   return 0;
}
