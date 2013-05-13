#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
   int A[1000001];
   int A2[1000001];
   string binary;
   int casenum=1;
   while(cin >> binary)
   {
      A[0]=0;
      for(string::size_type i=0;i<binary.size();i++)
      {
	 A[i+1]=binary[i]-'0';
      }
      partial_sum(A,A+binary.size()+1,A2);
      int queries;
      cin >> queries;
      cout << "Case " << casenum << ":" << endl; 
      for(int i=0;i<queries;i++)
      {
	 int i,j;
	 cin >> i >> j;
	 i++;
	 j++;
	 int small=min(i,j);
	 if(small!=i)
	 {
	    j=i;   
	 }
	 int a,b;
	 a=A2[small-1];
	 b=A2[j];
	 if(b-a==j-small+1)
	 {
	    cout << "Yes" << endl;
	 }
	 else if(a==b)
	 {
	    cout << "Yes" << endl;
	 }
	 else
	 {
	    cout << "No" << endl;
	 }
	 
      }
      casenum++;
   }
   return 0;
}
