#include <iostream>
using namespace std;

int nextPowerOf2(const int i);
int main()
{
   int i;
   int num=1;
   cin >> i;
   while(i>=0)
   {
      cout << "Case " << num++ << ": " << nextPowerOf2(i) << endl;
      cin >> i;
   }
   return 0;
}

int nextPowerOf2(const int i)
{
   int number=1;
   int power=0;
   while(number<i)
   {
      number*=2;
      power++;
   }
   return power;
}
