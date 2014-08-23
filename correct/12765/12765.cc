#include <iostream>
using namespace std;

int number[10][4] = {{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,0,0},{3,1,0,0},
		     {3,1,1,0},{4,2,1,0},{4,2,1,1},{7,2,1,1},{7,4,1,1}};

int sum[4], sum2[4];
int main() {
   int N, M;
   while(cin >> N >> M && N != 0 && M != 0) {
      sum[0] = sum[1] = sum[2] = sum[3] = 0;
      sum2[0] = sum2[1] = sum2[2] = sum2[3] = 0;
      int tmp;
      while(N--) {
	 cin >> tmp;
	 for(int i = 0; i < 4; i++) {
	    sum[i]+=number[tmp][i];
	 }
      }
      while(M--) {
	 cin >> tmp;
	 for(int i = 0; i < 4; i++) {
	    sum2[i]+=number[tmp][i];
	 }
      }
      if(sum[0] == sum2[0] && sum[1] == sum2[1] && sum[2] == sum2[2] && sum[3] == sum2[3]) {
	 cout << "YES" << endl;
      } else {
	 cout << "NO" << endl;
      }
   }
   
   return 0;
}
