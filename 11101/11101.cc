#include <iostream>
using namespace std;

class Point {
public:
   int a, s;
   
   friend istream& operator>>(istream &in, Point &a);
};

istream& operator>>(istream &in, Point &a) {
   in >> a.a >> a.s;
   return in;
}

// make a source node that points to all the locations of the first mall
// do BFS and store the second malls locations on a grid of some sort
// do all the points simutaniously and you can ignore any repeat points because they have already been reached in less time
// remember that it is a queue
int main() {

   int points;
   while(cin >> points) {
      vector<Point> m1;
      Point tmp;
      for(int i = 0; i < points; i++) {
	 cin >> tmp;
	 m1.push_back(tmp);
      }
      int small = 4444;
      cin >> points;
      for(int i = 0; i < points; i++) {
	 cin >> tmp;
	 
      }
   }
   return 0;
}
