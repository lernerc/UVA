#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#define SQR(X) ((X) * (X))

const double EPS = 1e-8;
bool dEqual(double x,double y) { return fabs(x-y) < EPS; }

struct Point {
  double x, y;
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(double r,Point p){ p.x *= r; p.y *= r; return p; }
double operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
double len(Point p){ return sqrt(p*p); }
double cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

double dist_line(Point a, Point b, Point c) { return fabs(cross(b-a,a-c)/len(b-a)); }

const double PI=acos(-1.0);

int main() {
   
   int n;
   double t, x;
   cin >> n;
   while(n--) {
      cin >> t >> x;
      double q;
      double f = t*100.0*tan(x*PI/180.0);
      q = f;
      bool bounce = false;
      double z = 0;
       Point a, b, c;
      double w;
      a.x = z*tan(x*PI/180.0)+a.x; a.y = 0;
      b.x = z*tan(x*PI/180.0)+a.x; + q/tan(x*PI/180.0); b.y = q;
      c.x = q/tan(x*PI/180.0); c.y = 0;
      double solved = false;
      
      if(fabs(dist_line(a, b, c)) < 16 + EPS) {
	 solved = true;
	 cout << "yes" << endl;
      }
      if(q > 47.5 && !solved) {
	 z = 47.5;
	 q -= 47.5;
	 bounce = true;
	 a.x = z*tan(x*PI/180.0)+a.x; a.y = 0;
	 b.x = z*tan(x*PI/180.0)+a.x; + q/tan(x*PI/180.0); b.y = q;
	 c.x = q/tan(x*PI/180.0); c.y = 0;
	 if(fabs(dist_line(a, b, c)) < 16 + EPS) {
	    solved = true;
	    cout << "yes" << endl;
	 }
      }
      while(a.x > 16+t*100 && !solved) {
	 z= 85;
	 q-=85.0;	
	 a.x = z*tan(x*PI/180.0)+a.x; a.y = 0;
	 b.x = z*tan(x*PI/180.0)+a.x; + q/tan(x*PI/180.0); b.y = q;
	 c.x = q/tan(x*PI/180.0); c.y = 0;
	 if(fabs(dist_line(a,b,c))<16+EPS) {
	    solved = true;
	    cout << "yes" << endl;
	 }
      }
      if(!solved)
	 cout << "no" << endl;
   }
   return 0;
}
