#include <iostream>
using namespace std;

int main()
{

   
   return 0;
};

int lowestBase(char a)
{
   if(a>='0' && a<='9')
   {
      return a-'0'+1;
   }
   else if(a>='a' && a<='f')
   {
      return a-'a'+11;
   }
   return -1;
}
