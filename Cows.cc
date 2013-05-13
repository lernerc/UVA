#include <iostream>
#include <iomanip>
using namespace::std;

int main()
{
   double cows,cars,shows;
   while(cin >> cows >> cars >> shows)
   {
      cout << fixed << setprecision(5) <<
	 cows/(cows+cars)*cars/(cows-shows+cars-1)+
	 cars/(cows+cars)*(cars-1)/(cows-shows+cars-1) << endl;
   }
   
   return 0;
}
