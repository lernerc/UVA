#include <iostream>
#include <cmath>
using namespace std;

int main()
{

   int fileSize;
   cin >> fileSize;
   int dataSet=1;
   while(fileSize!=0)
   {
      cout << "Output for data set " << dataSet <<", " << fileSize
	   << " bytes:" << endl;   
      int sum=0;
      int sec=0;
      int sum5=0;
      while(sum<fileSize)
      {
	 int bytesPerSecond;
	 cin >> bytesPerSecond;
	 sum+=bytesPerSecond;
	 sum5+=bytesPerSecond;
	 sec++;
	 if(sec%5==0)
	 {
	    cout << "   Time remaining: ";
	    if(sum5!=0)
	    {
	       double temp=fileSize-sum;
	       temp*=5.0;
	       int timeRem=static_cast<int>(ceil(temp/sum5));
	       
	       //timeRem=temp/sum5;
	       cout  << timeRem << " seconds" << endl;
	    }
	    else
	    {
	       cout << "stalled" << endl;
	    }
	    sum5=0;
	 }
      }
      cout << "Total time: " << sec << " seconds" << endl;
      cout << endl;
      dataSet++;
      cin >> fileSize;
   }
   
   return 0;
}
