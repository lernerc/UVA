#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int coins[12]={0,5,10,20,50,100,200,500,1000,2000,500,10000};
   long long amountAndCoins[12][6001]; 
   double amount;
   cin >> amount;

 
   for(int i=0;i<6001;i++)
   {
      amountAndCoins[0][i]=1;
   }
   for(int i=0;i<12;i++)
   {
      amountAndCoins[i][0]=1;
   }
   cout << "working" << endl;  
   for(int i=2;i<12;i++) {
      for(int j=2;j<6001;j++) {
	 if(5*j-coins[i]>0)
	 {
	    amountAndCoins[i][j]=amountAndCoins[i][j*5-coins[i]]+
	       amountAndCoins[i-1][j];
	 }
	 else
	 {
	    amountAndCoins[i][j]=amountAndCoins[i-1][j];
	 }
	 cout << i << "," << j << " " << amountAndCoins[i][j] << endl;
      }
   }


   cout << "working" << endl;
   
   while(amount!=0)
   {
      int cents=static_cast<int>(amount*100+0.5);
      int numberOfWays=amountAndCoins[12][cents/5];

      cout << fixed << setprecision(2) << setw(6) << right << amount
	   << setw(17) << numberOfWays << endl; 
      cin >> amount;
   }
   return 0;
}
