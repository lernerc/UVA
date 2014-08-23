#include <iostream>
#include <algorithm>
using namespace std;

int num[14];
int N;

void doCase() {
   sort(num, num + N);
   for(int i = 0; num[i] == 0 && i < 2; i++) {
      int j;
      for(j = 1; num[j] == 0 && j < N; j++);
      swap(num[i], num[j]);
   }
   int a=0, b=0;
   for(int i = 0; i < N; i++) {
      if(i%2 == 0)
	 a = a*10+num[i];
      else
	 b = b*10+num[i];
   }
     cout << a+b << endl;
}

int main() {
   while(cin >> N && N != 0) {
      for(int i = 0; i < N; i++)
	 cin >> num[i];
      doCase();
   }
   return 0;
}
