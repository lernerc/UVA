#include <iostream>
using namespace std;

int pages[4];
int output[3];
int main() {
   int N, P;
   while(cin >> N >> P) {
      if(P > N/2) {
	 if(P % 2 == 0) {
	    pages[2] = P - 1;
	    pages[3] = P;
	 } else {
	    pages[2] = P;
	    pages[3] = P + 1;
	 }
	 pages[0] = N - pages[2];
	 pages[1] = N - pages[2] + 1;
      } else {
	 if(P % 2 == 0) {
	    pages[0] = P - 1;
	    pages[1] = P;
	 } else {
	    pages[0] = P;
	    pages[1] = P + 1;
	 }
	 pages[2] = N - pages[0];
	 pages[3] = N - pages[0] + 1;

      }
      int w = 0;
      for(int i = 0; i < 4; i++) {
	 if(pages[i] != P) {
	    output[w] = pages[i];
	    w++;
	 }
      }
      for(int i = 0; i < 3; i++) {
	 if(i != 0)
	    cout << " ";
	 cout << output[i];
      }
      cout << endl;
   }
   return 0;
}
