/*
 * Convex hull
 *
 * Author: Howard Cheng
 * Reference:
 *   http://wilma.cs.brown.edu/courses/cs016/packet/node25.html
 *
 * Given a list of n (n >= 1) points in an array, it returns the vertices of
 * the convex hull in counterclockwise order.  Also returns the number of
 * vertices in the convex hull.  Assumes that the hull array has been
 * allocated to store the right number of elements (n elements is safe).
 * The points in the original polygon will be re-ordered.
 *
 * Note: The hull contains a maximum number of points.  ie. all colinear
 *       points and non-distinct points are included in the hull.
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

const double PI = acos(-1.0);

/* how close to call equal */
const double EPSILON = 1E-8;

struct Point {
   double x, y;
  
   bool operator<(const Point &p) const {
      return y < p.y || (y == p.y && x < p.x);
   }
   const Point& operator=(const Point& p) {
      x = p.x;
      y = p.y;
      return p;
   }
};

struct Rectangle {
   Point corners[4];
   double area;
   friend istream& operator>>(istream &in, Rectangle& a);
   const Point& at(const int a) const {
      if(a < 4 && a >= 0)
	 return corners[a];
      return corners[0];
   }
};

istream& operator>>(istream &in, Rectangle& a) {
   double w, h, j, q;
   in >> a.corners[0].x >> a.corners[0].y >> w >> h >> j;
   j *= PI/180.0;
   q = PI/2.0 - j;
   a.area = w * h;
   double cosj = cos(-j), sinj = sin(-j);
   double cosq = cos(q), sinq = sin(q);

   // calculate a.corners[1], a.corners[2], a.corners[3]
   a.corners[1].x = a.corners[0].x + h*cosq;
   a.corners[1].y = a.corners[0].y + h*sinq;

   a.corners[2].x = a.corners[0].x + w*cosj;
   a.corners[2].y = a.corners[0].y + w*sinj;

   a.corners[3].x = a.corners[1].x + w*cosj;
   a.corners[3].y = a.corners[1].y + w*sinj;
   return in;
}

/* counterclockwise,clockwise, or undefined */
enum Orientation {CCW, CW, CNEITHER};

/* Global point for computing convex hull */
Point start_p, max_p; 

bool colinear(Point a, Point b, Point c)
{
   double dx1 = b.x - a.x;
   double dx2 = c.x - b.x;
   double dy1 = b.y - a.y;
   double dy2 = c.y - b.y;
   double t1 = dy2 * dx1;
   double t2 = dy1 * dx2;
   return fabs(t1 - t2) < EPSILON;
}

Orientation ccw(Point a, Point b, Point c)
{
   double dx1 = b.x - a.x;
   double dx2 = c.x - b.x;
   double dy1 = b.y - a.y;
   double dy2 = c.y - b.y;
   double t1 = dy2 * dx1;
   double t2 = dy1 * dx2;

   if (fabs(t1 - t2) < EPSILON) {
      if (dx1 * dx2 < 0 || dy1 * dy2 < 0) {
	 if (dx1*dx1 + dy1*dy1 >= dx2*dx2 + dy2*dy2 - EPSILON) {
	    return CNEITHER;
	 } else {
	    return CW;
	 }
      } else {
	 return CCW;
      }
   } else if (t1 > t2) {
      return CCW;
   } else {
      return CW;
   }
}

bool ccw_cmp(const Point &a, const Point &b)
{
   return ccw(start_p, a, b) == CCW;
}

bool sort_cmp(const Point &a, const Point &b)
{
   if (colinear(start_p, a, max_p) && colinear(start_p, b, max_p)) {
      double dx1 = abs(start_p.x - a.x);
      double dx2 = abs(start_p.x - b.x);
      double dy1 = abs(start_p.y - a.y);
      double dy2 = abs(start_p.y - b.y);
      return dx1 > dx2 || (dx1 == dx2 && dy1 > dy2);
   } else {
      return ccw(start_p, a, b) == CCW;
   }
}

int convex_hull(Point polygon[], int n, Point hull[]) {
   int count, best_i, i;

   sort(polygon, polygon+n);
   for (int i = n-1; i >= 1; i--) {
      if (fabs(polygon[i].x - polygon[i-1].x) < EPSILON &&
	  fabs(polygon[i].y - polygon[i-1].y) < EPSILON) {
	 for (int j = i; j < n-1; j++) {
	    polygon[j] = polygon[j+1];
	 }
	 n--;
      }
   }

   assert(n > 0);

   if (n == 1) {
      hull[0] = polygon[0];
      return 1;
   }

   /* find the first point: min y, and then min x */
   best_i = min_element(polygon, polygon+n) - polygon;
   swap(polygon[0], polygon[best_i]);
   start_p = polygon[0];

   /* find the maximum angle wrt start_p and positive x-axis */
   best_i = 1;
   for (i = 2; i < n; i++) {
      if (ccw_cmp(polygon[best_i], polygon[i])) {
	 best_i = i;
      }
   }
   max_p = polygon[best_i];

   /* get simple closed polygon */
   sort(polygon+1, polygon+n, sort_cmp);

   /* do convex hull */
   count = 0;
   hull[count] = polygon[count]; count++;
   hull[count] = polygon[count]; count++;
   for (i = 2; i < n; i++) {
      while (count > 1 &&
	     ccw(hull[count-2], hull[count-1], polygon[i]) == CW) {
	 /* pop point */
	 count--;
      }
      hull[count++] = polygon[i];
   }
   return count;
}

/*
 * Area of a polygon
 *
 * Author: Howard Cheng
 * Reference:
 *   http://www.exaflop.org/docs/cgafaq/cga2.html
 *
 * This routine returns the SIGNED area of a polygon represented as an
 * array of n points (n >= 1).  The result is positive if the orientation is
 * counterclockwise, and negative otherwise.
 *
 */

double area_polygon(Point polygon[], int n)
{
  double sum = 0.0;

  for (int i = 0; i < n-1; i++) {
    sum += polygon[i].x * polygon[i+1].y - polygon[i].y * polygon[i+1].x;
  }
  sum += polygon[n-1].x * polygon[0].y - polygon[n-1].y * polygon[0].x;
  return sum/2.0;
}


int main(void)
{
   Point *hull, *polygon;
   int n, hull_size;
   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      cin >> n;
      vector<Rectangle> poly(n);
      hull = new Point[4*n];
      polygon = new Point[4*n];
      assert(polygon && hull);
      double board_area = 0.0;
      for (i = 0; i < n; i++) {
	 cin >> poly[i];
	 for(int j = 0; j < 4; j++) {
	    polygon[i*4 + j] = poly[i].at(j);
	 }
	 board_area += poly[i].area;
      }
      hull_size = convex_hull(polygon, 4*n, hull);
      double total = area_polygon(hull, hull_size);

      cerr << board_area << " " << total << endl;
      cout << fixed << setprecision(1) << board_area/total*100.0 << " %"
	   << endl;
      delete[] polygon;
      delete[] hull;
   }

   return 0;
}
