#include <iostream>
using namespace std;

const int MAX = 20001;
const int NOT = 3000;
// is it possible to make this amount in change
int amount[MAX][101];

int bills[100];

int cost;
int num_bills;


void fillArray() {
   fill(amount[0], amount[0] + 100, 0);
   amount[0][0] = 0;
   for(int i = 1; i < MAX; i++) {
      amount[i][0] = NOT;
      for(int j = 1; j < num_bills + 1; j++) {
	 amount[i][j] = NOT;
	 if( j > 0 && amount[i][j - 1] < NOT) {
	    amount[i][j] = amount[i][j - 1];
	 }
	 if(i - bills[j - 1] < 0) {continue;}
	 if(amount[i - bills[j - 1]][j - 1] < NOT) {
	    amount[i][j] = min(amount[i][j],
			       1 + amount[i - bills[j - 1]][j - 1]);
	 }
//	 cout << amount[i][j] << " ";
      }
      //    cout << endl;
      if(i >= cost && amount[i][num_bills] < NOT) {
	 break;
      }
   }
}

int main() {

   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      cin >> cost;
      cin >> num_bills;
      for(int j = 0; j < num_bills; j++) {
	 cin >> bills[j];
      }
      if(cost == 0) {
	 cout << "0 0" << endl;
	 continue;
      }
      // do something
      fillArray();
      
      for(int i = cost; i < MAX; i++) {
	 if(amount[i][num_bills] < NOT) {
	    cout << i << " " << amount[i][num_bills] << endl;
	    break;
	 }
      }
      
   }
   
   
   return 0;
}
