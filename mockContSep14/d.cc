#include <iostream>
#include <iomanip>
using namespace std;

int student[1000];
int main() {

   int c, n;
   double avg, num;
   cin >> c;
   for(int i = 0; i < c; i++) {
      avg = 0;
      cin >> n;
      for(int w = 0; w < n; w++) {
	 cin >> student[w];
	 avg += student[w];
      }
      avg /= (double)n;
      num = 0;
      for(int w = 0; w < n; w++) {
	 if((double)student[w] > avg)
	    num += 1;
      }
      num /= (double)n;
      cout << fixed << setprecision(3) << num*100 << "%" << endl;
   }
   
   return 0;
}
