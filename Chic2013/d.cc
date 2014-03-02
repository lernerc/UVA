#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double EPS = 1e-8;
struct Vector {
   double x, y, z;
   Vector(double xx = 0, double yy = 0, double zz = 0) :x(xx), y(yy), z(zz) {}
   Vector(const Vector &p1, const Vector &p2)
      : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) {}
   Vector(const Vector &p1, const Vector &p2, double t)
      : x(p1.x + t*p2.x), y(p1.y + t*p2.y), z(p1.z + t*p2.z) {}
   double norm() const { return sqrt(x*x + y*y + z*z);}
   bool operator==(const Vector& p)const{
      return abs(x-p.x) < EPS && abs(y-p.y) < EPS && abs(z-p.z) < EPS;
   }
};

double dot(Vector p1, Vector p2) { return p1.x*p2.x + p1.y*p2.y + p1.z*p2.z; }
Vector cross(Vector p1, Vector p2) {
   return Vector(p1.y*p2.z-p2.y*p1.z, p2.x*p1.z-p1.x*p2.z, p1.x*p2.y-p2.x*p1.y);
}

Vector operator+(Vector p1, Vector p2) {
   return Vector(p1.x+p2.x,p1.y+p2.y,p1.z+p2.z);}
Vector operator-(Vector p1, Vector p2) {
   return Vector(p1.x-p2.x, p1.y-p2.y, p1.z-p2.z);}
Vector operator*(double c, Vector v) {
   return Vector(c*v.x, c*v.y, c*v.z);}

typedef tuple<Vector, Vector, Vector> tvvv;
double volume_polyhedron(vector<tvvv>& p) {
   Vector c,p0,p1,p2; double v, volume = 0;
   for(int i=0;i<(int)p.size();i++)
      c = c + get<0>(p[i]) + get<1>(p[i]) + get<2>(p[i]);
   c = 1/ (3.0*p.size())*c;
   for(int i=0;i<(int)p.size();i++){
      tie(p0,p1,p2) = p[i], v = dot(p0,cross(p1,p2))/6;
      if(dot(cross(p2-p1,p0-p1),c-p0)>0) volume -= v;
      else volume += v;
   }
   return volume;
}

void readInFace(vector<tvvv> &a) {
   int v;
   cin >> v;
   vector<Vector> poly(v);
   for(int i = 0; i < v; i++) {
      cin >> poly[i].x >> poly[i].y >> poly[i].z;
   }
   for(int i = 2; i < v; i++) {
      a.push_back(tvvv(poly[0],poly[i-1], poly[i]));
   }
}

double doCase() {
   int f;
   cin >> f;
   vector<tvvv> a;
   for(int i = 0; i < f; i++) {
      readInFace(a);
   }
   return volume_polyhedron(a);   
}

int main() {

   int n;
   while(cin >> n && n!= 0) {
      double sum = 0;
      for(int i = 0; i < n; i++) {
	 sum += doCase();
      }
      cout << fixed << setprecision(2) << sum << endl;
   }
   
   return 0;
}
