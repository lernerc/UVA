#include <iostream>
using namespace std;

char board[14][12];

int dr[] = { 0, 0, -1, 1};
int dc[] = {-1, 1,  0, 0};

bool visited[14][12];

void mark(int r, int c, char colour) {
   visited[r][c] = true;
   board[r][c] = '*';
   for(int i = 0; i < 4; i++)
      if(!visited[r+dr[i]][c+dc[i]] && (colour == board[r+dr[i]][c+dc[i]]))
	 mark(r+dr[i], c+dc[i], colour);
}
  

void takeAway(int r, int c) {
   for(int i = 0; i < 14; i++)
      fill(visited[i], visited[i]+12, false);
   mark(r, c, board[r][c]);
   
   // move everything around
  for(int i = 1; i <= 12; i++) {
      for(int j = 1; j <= 10; j++) {
	 cout << board[i][j];
      }
      cout << endl;
   }
   cout << endl;
   // shifting everything down
   for(int j = 1; j <= 10; j++) {
      int count = 12;
      cout << "col: " << j <<" " ;
      for(int i = 12; i >= 1; --i) {
	 if(board[i][j] != '*') {
	    if(count != i) {
	       board[i][count] = board[i][j];
	       board[i][j] = '*';
	    }
	    count--;
	    cout << board[i][count];
	 }
      }
      cout << endl;
   }
   cout << endl;

   for(int i = 1; i <= 12; i++) {
      for(int j = 1; j <= 10; j++) {
	 cout << board[i][j];
      }
      cout << endl;
   }
   cout << endl;
						\
   //shifting everything left
   int count = 1;
   for(int i = 1; i <= 12; i++) {
      if(board[12][i] != '*')
	 if(count != i) {
	    for(int j = 10; j >= 0; --j) {
	       board[count][j] = board[i][j];
	    }
	 }
      count++;
   }

}

int main() {
   int T;
   while(cin >> T) {
      fill(board[0], board[0]+12, '*');
      fill(board[13], board[13] + 12, '*');
      for(int i = 0; i < 12; i++) {
	 board[0][i] = board[11][i] = '*';
      }
      for(int i = 1; i < 13; i++) {
	 for(int j = 1; j < 11; j++) {
	    cin >> board[i][j];
	 }
      }
      char a;
      int j;
      for(int i = 0; i < T; i++) {
	 cin >> a >> j;
	 takeAway(j, a-'a' + 1); 

      }
      int count = 0; 
      for(int i = 0; i < 12; i++) 
	 for(int j = 0; j < 10; j++)
	    if(board[i][j] != '*')
	       count++;
      cout << count << endl;
   }

   return 0;
}
