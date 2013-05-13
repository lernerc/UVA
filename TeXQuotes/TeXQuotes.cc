#include <iostream>
using namespace::std;

int main()
{
   string a;
   string b;
   bool c=false;
   while(getline(cin,a))
   {
      b.clear();
      for(string::size_type i=0;i<a.size();i++)
      {
	 if(a[i]!='"')
	    b+=a[i];
	 else if(c)
	 {
	    b+="''";
	    c=false;
	 }
	 else
	 {
	    b+="``";
	    c=true;
	 }
      }
      cout << b << endl;
   }
   
   return 0;
}
