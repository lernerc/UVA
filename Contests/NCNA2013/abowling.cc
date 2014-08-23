#include <iostream>
#include <vector>
using namespace std;

int game[10][3];
int countmul[10][3];
int tmp[2][3];
// when counting a score each round has a max of 30

int calcsum() {
   int sum = 0;
   for(int i = 0; i < 10; i++) {
      int round = 0;
      for(int j = 0; j < 3; j++) {
	 if(countmul[i][j] > 0) {
	    round += game[i][j]*countmul[i][j];
	 }
      }
      /* if(round > 30) {
	 sum += 30;
      } else {
      */ sum += round;
      //}
   }
   return sum;
}

void calcmul(int i) {
   int sum = 0;
   sum += game[i][0];
   // strike
   if(sum == 10) {
      if(i == 9) {
	 // countmul[i][1]++;
	 countmul[i][2]++;
	 /* if(game[i][1] == 10) {
	    countmul[i][2]=1;
	    }*/
      } else {
	 countmul[i][1] = 0;
	 countmul[i+1][0]++;
	 if(game[i+1][0] == 10) {
	    if(i+1 == 9) {
	       countmul[i+1][1]++;
	    } else {
	       countmul[i+2][0]++;
	    }
	 } else {
	    countmul[i+1][1]++;    
	 }
      }
   } else {
      sum += game[i][1];   
      // spare
      if(sum == 10) {
	 if(i == 9) {
	    countmul[i][2] = 1;   
	 } else {
	    countmul[i+1][0]++;
	 }
      }
   }
}

bool validGame() {
   
   if(game[8][0] == 10) {
      if(game[8][1] != 0)
	 return false;
      countmul[8][1] = 0;
   } else if(game[9][0] == 10){
      // countmul[9][2]++;
   } else if(game[9][0] + game[9][1] == 10) {
      // countmul[9][2] = 1;
   } else if(game[9][0] + game[9][1] < 10) {
      if(game[9][2] > 0)
	 return false;
   } else {
      return false;
   }
   if(game[8][0] + game[8][1] > 10) {
      return false;
   }
   return true;
}

int main() {

   int opsc;
   int cases = 1;
   while(cin >> opsc && opsc >= 0) {
      vector<vector<int> > win;
      //cout << opsc << endl;
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
      for(int i = 8; i < 10; i++) {
	 fill(game[i], game[i] + 3, 0);
      }
  
      for(int i = 0; i < 2; i++) {
	 for(int j = 0; j < 3; j++) {
	    tmp[i][j] = countmul[i+8][j];
	 }
      }

      int array[5];
      for(int i = 0; i < 11; i++) {
	 for(int j = 0; j < 11; j++) {
	    for(int k = 0; k < 11; k++) {
	       for(int l = 0; l < 11; l++) {
		  for(int m = 0; m < 11; m++) {
		     game[8][0] = array[0] = i;
		     game[8][1] = array[1] = j;
		     game[9][0] = array[2] = k;
		     game[9][1] = array[3] = l;
		     game[9][2] = array[4] = m;
		     for(int w = 0; w < 10; w++) {
			fill(countmul[w], countmul[w] + 2, 1);
			countmul[w][2] = 0;
		     }
		     validGame();
		     for(int i = 0; i < 10; i++) {
			calcmul(i);
		     }
/*		    for(int q = 0; q < 2; q++) {
			for(int r = 0; r < 3; r++) {
			   countmul[q+8][r] = tmp[q][r];
			}
			}
*/
		     if(validGame()) {
			/*for(int i = 0; i < 10; i++) {
			   for(int j = 0; j < 3; j++) {
			      cout << " " <<countmul[i][j];
			   }
			   cout << endl;
			}
			cout << endl;
			calcmul(8);
			for(int i = 0; i < 10; i++) {
			   for(int j = 0; j < 3; j++) {
			      cout << " " <<countmul[i][j];
			   }
			   cout << endl;
			}
			cout << endl;
			calcmul(9);
*/		/*	for(int i = 0; i < 10; i++) {
			   for(int j = 0; j < 3; j++) {
			      cout << " " <<countmul[i][j];
			   }
			   cout << endl;
			}
			cout << "opsc: " << opsc << endl;
			cout << "calcsum(): " << calcsum() << endl;
		*/	if(calcsum() > opsc) {
			   //cout << calcsum() << endl;
			   win.push_back(vector<int>(array, array + 5));
			   //	   cout << "win" << endl;
			}
		     }
/*		     cout << "Valid: " << validGame() << endl;
		     cout << "Score: " << calcsum() << endl;
		     		     return 0;
*/
		  }
	       }
	    }
	 }
      }
      
      cout << "Case " << cases++ << ":";
      if(!win.empty()) {
	 game[8][0] = win[0][0];
	 game[8][1] = win[0][1];
	 game[9][0] = win[0][2];
	 game[9][1] = win[0][3];
	 game[9][2] = win[0][4];
	 
	 for(int w = 0; w < 10; w++) {
	    fill(countmul[w], countmul[w] + 2, 1);
	    countmul[w][2] = 0;
	 }
	 for(int i = 0; i < 10; i++) {
	    calcmul(i);
	 }
	 for(int i = 8; i < 10; i++) {
	    for(int j = 0; j < 3; j++) {
	       if(countmul[i][j] > 0)
		  cout << " " << game[i][j];
	    }
	 }
	 cout << endl;
      } else {
	 cout << " impossible" << endl;
      }
   }

   return 0;
}
