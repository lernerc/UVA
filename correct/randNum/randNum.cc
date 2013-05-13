#include <iostream>
using namespace std;

const int top=10000;

int main()
{
   int x;
   cin >> x;
   while(x!=0)
   {
      bool array[top];
      for(int i=0;i<top;i++)
	 array[i]=false;
      array[x]=true;
      x*=x;
      x/=100;
      x%=10000;
      int count=1;
      while(!array[x])
      {
	 array[x]=true;
	 x*=x;
	 x/=100;
	 x%=10000;
	 count++;
      }
      cout << count << endl;
      cin >> x;
   }
   
   return 0;
}
