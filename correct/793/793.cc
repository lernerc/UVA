//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 793
// Description: Reads in the computers and if they are connected uses union
// find to connect them and checks at whether two computers are connected and
// keeps track of how many of the attempts are successful or unsuccessful.
//*****************************************************************************

#include <iostream>
#include <sstream>
using namespace std;

//*****************************************************************************
// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind
//*****************************************************************************

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

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

//*****************************************************************************
// START OF MY CODE
//*****************************************************************************

int main() {
   int cases;
   cin >> cases;
   for(int z=0;z<cases;z++) {
      int computers;
      cin >> computers;
      if(z!=0)
	 cout << endl;
      UnionFind network(computers+1);
      
      int successful=0, unsuccessful=0;
      
      string blankline;
      getline(cin,blankline);
      string pair;
      while(getline(cin,pair) && pair.size()!=0) {
	 istringstream line(pair);
	 char type;
	 int c1,c2;
	 line >> type >> c1 >> c2;
	 switch(type) {
	    case 'c':
	       network.merge(c1,c2);// connect c1 and c2
	       break;
	    case 'q':
	       if(network.find(c1)==network.find(c2)) {
		  successful++;
	       } else {
		  unsuccessful++;
	       }
	       break;
	 };
	 
      }
      cout << successful << "," << unsuccessful << endl;
   }
   return 0;
}
