#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct agency{
   string name;
   int a, b, cost;
   bool operator<(const agency& c) const {
      if(cost != c.cost)
	 return cost < c.cost;
      else
	 return name < c.name;
   }
   void calculate(int n, int m) {
      cost = 0;
      while(n > m) {
	 if(n/2 >= m)
	    if(b < (n-n/2)*a) {
	       cost +=b;
	       n=n/2;
	    } else {
	       cost +=(n-n/2)*a;
	       n=n/2;
	    }
	 else {
	    cost += (n-m)*a;
	    n=m;
	 }
      }
   }
};
const int AG_MAX=100;

agency ag[AG_MAX];

int main() {
   int cases;
   int n, m , l;
   cin >> cases;
   for(int w = 1; w <=cases; w++) {
      cin >> n >> m >> l;
      for(int i = 0; i < l; i++) {
	 getline(cin, ag[i].name);
	 getline(cin, ag[i].name, ':');
	 char comma;
	 cin >> ag[i].a >> comma >> ag[i].b;
	 //cout << ag[i].name << " " << ag[i].a << " " << ag[i].b << endl;
	 ag[i].calculate(n, m);
      }
      sort(ag, ag+l);
      cout << "Case " << w << endl;
      for(int i = 0; i < l; i++)
	 cout << ag[i].name << " " << ag[i].cost << endl;
   }
   return 0;
}
