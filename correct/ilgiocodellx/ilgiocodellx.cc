#include <iostream>
using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


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
const int MAX=202;

int main()
{
   int N;
   int cases=1;
   int di[6]={-1,-1,0,0,1,1};
   int dj[6]={-1,0,-1,1,0,1};
   while(cin >> N && N!=0)
   {
      UnionFind uf(N*N+2);
      char A[MAX][MAX];
      for(int i=0;i<=N+1;i++)
	 for(int j=0;j<=N+1;j++)
	    A[i][j]='x';
      
      for(int i=1;i<=N;i++)
      {
	 for(int j=1;j<=N;j++)
	 {
	    cin >> A[i][j];
	 }
      }

      // connecting first line to 0
      for(int i=1;i<=N;i++)
      {
	 if(A[1][i]=='b')
	    uf.merge(i,0);
      }

      // connecting last line to N*N+1
      for(int i=1;i<=N;i++)
      {
	 if(A[N][i]=='b')
	    uf.merge((N-1)*N+i,N*N+1);
      }
      
      // connecting middle
      for(int i=1;i<=N;i++)
      {
	 for(int j=1;j<=N;j++)
	 {
	    if(A[i][j]!='b')
	       continue;
	    for(int k=0;k<6;k++)
	    {
	       int i2=i+di[k],j2=j+dj[k];
	       if(A[i2][j2]!='b')
		  continue;
	       uf.merge((i-1)*N+j,(i2-1)*N+j2);
	    }
	 }
      }
      cout << cases << " ";
      int begin=uf.find(0),end=uf.find(N*N+1);
      if(begin==end)
	 cout << "B" << endl;
      else
	 cout << "W" << endl;
      cases++;
   }
   return 0;
}
