#include <iostream>
#include <string>
using namespace std;

string post(const string &pre,const string &in);

int main()
{
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      int length;
      cin >> length;
      string pre,in;
      cin >> pre >> in;
      // recursive call to function on left and right then add
      // root
      cout << post(pre,in) << endl;
         }
   return 0;
}

string post(const string &pre,const string &in)
{
   string postS="";
   if(pre.length()==0 || in.length()==0)
   {
      return postS;
   }
   
   char root=pre[0];
   int index=in.find(root);

   // left
   postS+=post(pre.substr(1,index),in.substr(0,index));

   // right
   postS+=post(pre.substr(index+1,pre.size()),
	       in.substr(index+1,in.size()));
   postS+=root;

   return postS;
}
