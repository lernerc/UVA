#include <iostream>
#include <queue>
using namespace std;

class Point {
public:
   Point() {}
   Point( const int i, const int j) : a(i), s(j) {}
   int a, s;
   
   friend istream& operator>>(istream &in, Point &a);
};

istream& operator>>(istream &in, Point &a) {
   in >> a.a >> a.s;
   return in;
}
const int MAX = 2001;
bool secondMall[MAX][MAX];
int been[MAX][MAX];
// make a source node that points to all the locations of the first mall
// do BFS and store the second malls locations on a grid of some sort
// do all the points simutaniously and you can ignore any repeat points because they have already been reached in less time
// remember that it is a queue
const int MOVES = 4;
//           N   E   S   W
int di[MOVES] = {  0,  1,  0, -1};
int dj[MOVES] = { -1,  0,  1,  0};

int BFS(queue<Point>& explore) {

   while(!explore.empty()) {
      if(secondMall[explore.front().a][explore.front().s]) {
	 return been[explore.front().a][explore.front().s];
      }
      for(int i = 0; i < MOVES; i++) {
	 Point tmp = Point(explore.front().a+di[i], explore.front().s+dj[i]);
	 if(tmp.a < 0 || tmp.a >= MAX || tmp.s < 0 || tmp.s >= MAX ||
	    been[tmp.a][tmp.s] > 0) {
	    continue;
	 }
	 been[tmp.a][tmp.s] = been[explore.front().a][explore.front().s] + 1;
	 explore.push(tmp);
      }
      explore.pop();
   }
   return 4000;
}

int main() {

   int points;
   while(cin >> points && points != 0) {
      for(int i =0; i < MAX; i++) {
	 fill(secondMall[i], secondMall[i] + MAX, false);
	 fill(been[i], been[i] + MAX, 0);
      }
      queue<Point> m1;
      Point tmp;
      for(int i = 0; i < points; i++) {
	 cin >> tmp;
	 m1.push(tmp);
	 been[tmp.a][tmp.s] = 1;
      }
     
      cin >> points;
      for(int i = 0; i < points; i++) {
	 cin >> tmp;
	 secondMall[tmp.a][tmp.s] = true;
      }

      cout << BFS(m1) - 1 << endl;
   }
   return 0;
}
