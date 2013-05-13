#include <iostream>
using namespace std;

int main()
{
   int cases;
   cin >> cases;

   for(int i=0;i<cases;i++)
   {
      int numPeople;
      cin >> numPeople;
      int people[1000];
      int time[1000];
      int chosen[1000];
      // make two arrays of people
      for(int j=0;j<numPeople;j++)
      {
	 cin >> people[j];
      }
      time[0]=people[0];
      time[1]=people[1];
      for(int j=2;j<numPeople;j++)
      {
	 if((time[j-1]+people[j]+people[0])
	    <(time[j-2]+2*people[1]+people[0]+people[j]))
	 {
	    time[j]=time[j-1]+people[j]+people[0];
	    chosen[j]=1;
	 }
	 else
	 {
	    time[j]=time[j-2]+2*people[1]+people[0]+people[j];
	    chosen[j]=2;
	 }
      }
      cout << time[numPeople-1] << endl;
      int j=numPeople-1;
      if(numPeople==1)
	 cout << people[0] << endl;
      else
      {
	 cout << people[0] << " " << people[1] << endl;
	 while(j>1)
	 {
	    if(chosen[j]==1)
	    {
	       cout << people[0] << endl;
	       cout << people[0] << " " << people[j] << endl;
	       j--;
	    }
	    else if(chosen[j]==2)
	    {
	       cout << people[0] << endl;
	       cout << people[j-1] << " " << people[j] << endl;
	       cout << people[1] << endl;
	       cout << people[0] << " " << people[1] << endl;
	       j-=2;
	    }
	 }
      }
   }
   return 0;
}
