#include <iostream>
using namespace std;

int nextNumber(int);

int main()
{
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      string Bnumber;
      cin >> Bnumber;
      int number=0;
      for(string::size_type w=0;w<Bnumber.size();w++)
      {
	 number+=(Bnumber[w]-'0')*(Bnumber[w]-'0');
      }
      bool seen[730]={false};
      while(!seen[number] && number!=1)
      {
	 seen[number]=true;
	 number=nextNumber(number);
      }
      if(number==1)
      {
	 cout << "Case #" << i+1 << ": " << Bnumber << " is a Happy number."
	      << endl;
      }
      else
      {
	 cout << "Case #" << i+1 << ": " << Bnumber << " is an Unhappy number."
	      << endl;
      }
   }
   
   return 0;
}

int nextNumber(int a)
{
   int b,c,d;
   b=a%10;
   a/=10;
   c=a%10;
   a/=10;
   d=a%10;
   return b*b+c*c+d*d;
}
