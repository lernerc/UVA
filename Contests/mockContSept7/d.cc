#include <iostream>
using namespace std;

int table[102][102];
// first 101 are rows and then columns
int str[2][204];
int n;
const char person[2] = {'X', 'O'};

const char moves[] = {'L', 'R', 'T', 'B'};

void doLeft(const int person, const int place) {
   int tile = person;
      for(int i = 1; i <= n; i++) {
      if(tile == -1) continue;
      if(table[place][i] == -1) {
	 table[place][i] = tile;
	 str[tile][n + i]++;
	 tile = -1;
      } else {
	 str[table[place][i]][n + i]--;
	 str[tile][n + i]++;
	 swap(table[place][i], tile);
      }
      
   }
}
void doRight(const int person, const int place) {
   int tile = person;
   for(int i = n; i >= 1; i--) {
      if(tile == -1) continue;
      if(table[place][i] == -1) {
	 table[place][i] = tile;
	 tile = -1;
      } else {
	 swap(table[place][i], tile);
      }
      
   }
}
void doTop(const int person, const int place) {
   int tile = person;
   for(int i = 1; i <= n; i++) {
      if(tile == -1) continue;
      if(table[i][place] == -1) {
	 table[i][place] = tile;
	 tile = -1;
      } else {
	 swap(table[i][place], tile);
      }
      
   }
}
void doBottom(const int person, const int place) {
   int tile = person;
   for(int i = n; i > 0; i--) {
      if(tile == -1) continue;
      if(table[i][place] == -1) {
	 table[i][place] = tile;
	 tile = -1;
      } else {
	 swap(table[i][place], tile);
      }
      
   }
}

int doSomething(const int person, const char m, const int place) {
   switch(m) {
      case 'L':
	 doLeft(person, place);
	 break;
      case 'R':
	 doRight(person, place);
	 break;
      case 'T':
	 doTop(person, place);
	 break;
      case 'B':
	 doBottom(person, place);
	 break;
      default:
	 break;
   };

/*   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
	 cerr << table[i][j] << " ";
      }
      cerr << endl;
   }
*/ 
   // cerr << endl;
   int sum[2] = {0, 0};

   for(int i = 0; i < 2; i++) {
      fill(str[i], str[i] + 204, 0);
   }
   
   for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
	 if(table[i][j] == -1) continue;
	 str[table[i][j]][i]++;
	 str[table[i][j]][j + n]++;
      }
   }
   for(int k = 0; k < 2; k++) {
      for(int i = 1; i <= 2*n; i++) {
//	 cerr << ":" << str[k][i];
	 if(str[k][i] == n)
	    sum[k]++;
      }
      //    cerr << endl;
   }

   
   if(sum[0] == sum[1]) {
      return -1;
   } else if(sum[0] > sum[1]) {
      return 0;
   } else {
      return 1;
   }
}

// X starts
int main() {

   cin >> n;
   char mov;
   for(int i = 0; i < 102; i++)
      fill(table[i], table[i] + 102, -1);
   int winner = -1;
   int move = 0;
   while(cin >> mov && mov != 'Q' ) {
      int place;
      cin >> place;
      winner = doSomething(move, mov, place);
      if(winner > -1)
	 break;
      move = (move + 1) % 2;
   }
   if(winner == -1)
      cout << "TIE GAME" << endl;
   else {
      cout << person[winner] << " WINS" << endl;
   }

   
   return 0;
}
