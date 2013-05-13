//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 
// Description: I use union find to connect all the cities in the same country,
// while creating the complete graph and then I use the minimum spanning tree
// algorithm to find the roads and railways that are needed. Then I traverse
// through the edges used in the minimum spanning tree and check whether the
// two nodes are in the same country and if they are add the length to roads
// otherwise I add the length to the railroads and add another country to the
// list. 
//*****************************************************************************
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


/*
 * Implementation of Kruskal's Minimum Spanning Tree Algorithm
 *
 * Author: Howard Cheng
 *
 * This is a routine to find the minimum spanning tree.  It takes as
 * input:
 *
 *      n: number of vertices
 *      m: number of edges
 *  elist: an array of edges (if (u,v) is in the list, there is no need
 *         for (v,u) to be in, but it wouldn't hurt, as long as the weights
 *         are the same).
 *
 * The following are returned:
 *
 *  index: an array of indices that shows which edges from elist are in
 *         the minimum spanning tree.  It is assumed that its size is at
 *         least n-1.
 *   size: the number of edges selected in "index".  If this is not
 *         n-1, the graph is not connected and we have a "minimum
 *         spanning forest."
 *
 * The weight of the MST is returned as the function return value.
 * 
 * The run time of the algorithm is O(m log m).
 *
 * Note: the elements of elist may be reordered.
 *
 * Modified by Rex Forsyth using C++  Aug 28, 2003
 * This version defines the unionfind and edge as classes and  provides
 * constructors. The edge class overloads the < operator. So the sort does
 * not use a  * cmp function. It uses dynamic arrays.
 */

class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {             // for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

class Edge {

   public:
      Edge(int i=-1, int j=-1, double weight=0) {
	 v1 = i;
	 v2 = j;
	 w = weight;
      }
      bool operator<(const Edge& e) const { return w < e.w; }

      int v1, v2;          /* two endpoints of edge                */
      double w;            /* weight, can be double instead of int */
};


double mst(int n, int m, Edge elist[], int index[], int& size)
{
  UnionFind uf(n);

  sort(elist, elist+m);

  double w = 0.0;
  size = 0;
  for (int i = 0; i < m && size < n-1; i++) {
    int c1 = uf.find(elist[i].v1);
    int c2 = uf.find(elist[i].v2);
    if (c1 != c2) {
      index[size++] = i;
      w += elist[i].w;
      uf.merge(c1, c2);
    }
  }

  return w;
}

//*****************************************************************************
// Where my code starts
//*****************************************************************************

class City{
public:
   City() {}
   City(int first, int second) : x(first), y(second) {}
   double distance(const City& b) {
      return sqrt((double)(b.x - x) * (b.x - x)
		  + (double)(b.y - y) * (b.y - y));
   }
   bool sameCountry(const City& b, const int& threshold) {
      return ((long long)(b.x - x) * (b.x - x)
	      + (long  long)(b.y - y) * (b.y - y))
	 <= threshold * threshold;
   }
   int x, y;
};


int main() {

   int cases;
   cin >> cases;
   for(int w = 0; w < cases; w++) {
      City *cities;
      int n, r;
      cin >> n >> r;
      cities = new City[n];
      for(int j = 0; j < n; j++) {
	 int x, y;
	 cin >> x >> y;
	 cities[j].x = x;
	 cities[j].y = y;
      }
      UnionFind countries(n);
      Edge* elist = new Edge[n*n];
      int k=0;
      // creating the complete graph and finding out which cities are in the
      // same country
      for(int i = 0; i < n; i++) {
	 for(int j = i + 1; j < n; j++) {
	    elist[k++] = Edge(i, j, cities[i].distance(cities[j]));
	    if(cities[i].sameCountry(cities[j], r)) {
	       countries.merge(countries.find(i), countries.find(j));
	    }
	 }
      }

      int *index = new int[n];
      int edges;
      mst(n, k, elist, index, edges);
      double road = 0, railroad = 0;
      int numCountries = 1;
      //int c1 = countries[index[0]];

      // finding the length of the roads and railroads needed to be built and
      // finding the number of countries
      for(int i = 0; i < edges; i++) {
	 if(countries.find(elist[index[i]].v1) ==
	    countries.find(elist[index[i]].v2)) {
	    road += elist[index[i]].w;
	 } else {
	    numCountries++;
	    railroad += elist[index[i]].w;
	 }
      }

      cout << "Case #" << w + 1 << ": " << numCountries
	   << " " << static_cast<int>(road + 0.5)
	   << " " << static_cast<int>(railroad + 0.5) << endl;
   }

   return 0;
}
