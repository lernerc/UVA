#include <iostream>
using namespace std;

int main()
{
   string number;
   cin >> number;
   while(number!="0")
   {
      int smaller=0;
      for(string::size_type i=0;i<number.size();i++)
      {
	 smaller=(smaller*10+(number[i]-'0'))%11;
      }
      if( smaller==0)
      {
	 cout << number << " is a multiple of 11." << endl;
      }
      else
      {
	 cout << number << " is not a multiple of 11." << endl;
      }
      cin >> number;
   }
   return 0;
}
