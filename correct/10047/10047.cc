//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10047
// Description: I use BFS to go forward or turn and find the shortest time 
//*****************************************************************************
#include <iostream>
#include <queue>
using namespace std;

char matrix[28][28];

//          N  E   S   W
int dy[]={  0, 1,  0, -1};
int dx[]={ -1, 0,  1,  0};

class Index {
public:
   Index(const Index& a) {
      x=a.x;
      y=a.y;
   }
   Index(Index& a) {
       x=a.x;
      y=a.y;
   }
   Index(int first = 0, int second = 0) : x(first), y(second) {}
   int x, y;
};

class State {
public:

   State(const Index& a) : index(a) {
      dir = time = color = 0;
   }
   
   State(Index& a) : index(a) {
      dir = time = color = 0;
   }

   State(const State& a) {
      index = a.index;
      dir = a.dir;
      time = a.time;
      color = a.color;
   }

   bool done(const Index &b) const {
      if( sameIndex(b) && color == 0) {
	 return true;
      }
      return false;
   }
   
   bool sameIndex(const Index &b) const  {
      if( index.x == b.x && index.y == b.y ) {
	 return true;
      } else {
	 return false;
      }
   }

   bool move() {
      if(matrix[index.x + dx[dir]][index.y + dy[dir]] != '#') {
	 time += 1;
	 index.x += dx[dir];
	 index.y += dy[dir];
	 color = (color + 1) % 5;
	 return true;
      }
      return false;
   }
   
   void turnleft() {
      dir = (dir -1 + 4) % 4;
      time += 1;
   }
   
   void turnright() {
      dir = (dir + 1) % 4;
      time += 1;
   }   

   int dir, color, time;
   Index index;

};

int BFS(const Index &start, const Index &end, int& seconds) {
   bool visited[27][27][5][4];
   for(int i = 1; i < 27; i++) {
      for(int j = 1; j < 27; j++) {
	 for(int k = 0; k < 5; k++) {
	    for(int l = 0; l < 4; l++) {
	       visited[i][j][k][l] = false;
	    }
	 }
      }
   }
   queue<State> node;
   node.push(State(start));
   visited[start.x][start.y][0][0] = true;
   int on_green = 0;

   while(!node.empty()) {
      State curr = node.front();
      node.pop();
     
      if(curr.done(end)) {
	 on_green = curr.time;
	 break;
      }

      // turn left
      State left = curr;
      left.turnleft();
      if(!visited[left.index.x][left.index.y][left.color][left.dir]) {
	 visited[left.index.x][left.index.y][left.color][left.dir] = true;
	 node.push(left);
      }
          
      // move
      State move = curr;
      if(move.move()) {
	 if(!visited[move.index.x][move.index.y][move.color][move.dir]) {
	    visited[move.index.x][move.index.y][move.color][move.dir] = true;
	    node.push(move);
	 }
      }
      
      // turn right
      State right = curr;
      right.turnright();
      if(!visited[right.index.x][right.index.y][right.color][right.dir]) {
	 visited[right.index.x][right.index.y][right.color][right.dir] = true;
	 node.push(right);
      }

   }

   seconds = on_green;
   
   return on_green != 0;
}


int main() {

   int m, n;
   bool firstcase = true;
   int cases = 1;
   while(cin >> m >> n && (m != 0 || n != 0)) {
      if(!firstcase) {
	 cout << endl;
      }
      firstcase=false;
      cout << "Case #" << cases++ << endl;
      for(int i = 0; i <= m + 1; i++) {
	 matrix[i][0] = matrix[i][n + 1] = '#';
      }
      for(int i = 0; i <= n+1 ; i++) {
	 matrix[0][i] = matrix[m + 1][i] = '#';
      }
      
      Index start, end;
      for(int i = 1; i <= m; i++) {
	 for(int j = 1; j <= n; j++) {
	    cin >> matrix[i][j];
	    if(matrix[i][j] == 'S') {
	       start.x = i;
	       start.y = j;
	    } else if(matrix[i][j] == 'T') {
	       end.x = i;
	       end.y = j;
	    }
	 }
      }

      int seconds;
      bool possible = BFS(start, end, seconds);
      // find path
      if(!possible) {
	 cout << "destination not reachable" << endl;
      } else {
	 cout << "minimum time = " << seconds << " sec" << endl;
      }

   }
   
   return 0;
}
