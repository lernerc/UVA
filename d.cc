#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class boxs
{
public:
   int a[6];
   void output()
   {
      cout << a[0] << " " << a[1] << " " << a[2] << " "
	   << a[3] << " "  << a[4] << " " << a[5] << endl;
      
   }
   bool operator<(const boxs b) const
   {
      if(a[0]<b.a[0])
	 return true;
      else if(a[0]>b.a[0])
	 return false;
      else
      {
	 if(a[1]<b.a[1])
	    return true;
	 else if(a[1]>b.a[1])
	    return false;
	 else
	 {
	    if(a[2]<b.a[2])
	       return true;
	    else if(a[2]>b.a[2])
	       return false;
	    else
	    {
	       if(a[3]<b.a[3])
		  return true;
	       else if(a[3]>b.a[3])
		  return false;
	       else
	       {
		  if(a[4]<b.a[4])
		     return true;
		  else if(a[4]>b.a[4])
		     return false;
		  else
		  {
		     if(a[5]<b.a[5])
			return true;
		     else if(a[5]>b.a[5])
			return false;
		     else
		     {
			return false;
		     }		     
		  }
	       }
	    }
	 }
	 
      }
   }
};

map<boxs, int> possible;
map<int, boxs> possible2;
int main()
{
   // initializing possible with all the possible things in it
   int index=0;
   for(int i=0;i<16;i++)
   {
      for(int j=0;j<16;j++)
      {
	 for(int k=0;k<16;k++)
	 {
	    for(int q=0;q<16;q++)
	    {
	       for(int r=0;r<16;r++)
	       {
		  boxs x;
		  x.a[0]=i;
		  x.a[1]=j;
		  x.a[2]=k;
		  x.a[3]=q;
		  x.a[4]=r;
		  if((i+j+k+q+r)<=15)
		  {
		     x.a[5]=15-i-j-k-q-r;
		     possible[x]=index;
		     possible2[index]=x;
		     index++;
		  }
	       }
	    }
	 }
      }
   }
     char character;
   int cases=1;
   while (cin >> character && character!='e')
   {
      boxs indexing;
      int integer;
      cout << "Case " << cases << ": ";
      cases++;
      
      if(character=='m')
      {
	 cin >> indexing.a[0] >> indexing.a[1] >>  indexing.a[2]
	     >>  indexing.a[3] >>  indexing.a[4] >> indexing.a[5];
	 cout << possible[indexing] << endl;
      }
      else if(character=='u')
      {
	 cin >> integer;
	 possible2[integer].output();
      }
      
      }

   return 0;
}
