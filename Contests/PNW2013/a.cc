#include <iostream>
using namespace std;

int main() {

   int cases;
   cin >> cases;
   for(int w = 0; w < cases; w++) {
      int N, D;
      cin >> N >> D;
      int v, f, c;
      int count = 0;
      for(int i = 0; i < N; i++) {
	 cin >> v >> f >> c;
	 if(f*v>=D*c) {
	    count++;
	 }
      }
      cout << count << endl;
   }

   return 0;
}
