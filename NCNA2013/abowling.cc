#include <iostream>
using namespace std;

int game[10][3];
int countmul[10][3];

// when counting a score each round has a max of 30

void calcmul(int i) {
   int sum = 0;
   sum += game[i][0];
   // strike
   if(sum == 10) {
      if(i == 9) {
	 countmul[i][1]++;
	 countmul[i][2]++;
	 if(game[i][1] == 10) {
	    countmul[i][2]++;
	 }
      } else {
	 countmul[i+1][0]++;
	 if(game[i+1][0] == 10) {
	    if(i+1 == 9) {
	       countmul[i+1][1]++;
	    } else {
	       countmul[i+2][0]++;
	    }
	 } else {
	    countmul[i+1][1]++;//continue here
	 }
      }
   } else {
      sum += game[i][1];   
      // spare
      if(sum == 10) {
	
	 sum += game[i+1][0];
      }
   }
   return sum;
}
      
int main() {

   int opsc, sum;
   while(cin >> opsc && opsc >= 0) {
      for(int i = 0; i < 8; i++) {
	 fill(game[i], game[i] + 3, 0);
	 fill(countmul[i], countmul[i] + 2, 1);
	 countmul[i][2] = 0;
	 cin >> game[i][0];
	 if(game[i][0] == 10) {
	    countmul[i][1] = 0;  
	 } else {
	    cin >> game[i][1];
	 }
      }
      int sum = 0;
      for(int i = 0; i < 8; i++) {
	 calcmul(i);
      }
      
   }

   return 0;
}
