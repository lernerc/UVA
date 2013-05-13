#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int student[1000];
   int studentNum;
   cin >> studentNum;
   while(studentNum!=0)
   {
      int money=0;
      for(int i=0;i<studentNum;i++)
      {
	 double a;
	 cin >> a;
	 student[i]=a*100+.5;
	 money+=student[i];
      }
      int extracents=money%studentNum;
      money/=studentNum;
  
      sort(student,student+studentNum);
      int total=0;
      int i=0;
      while(student[i]<money)
      {
	 total+=money-student[i];
	 i++;
      }
      while(student[i]==money)
      {
	 i++;
      }
      if(studentNum-i<extracents)
      {
	 total+=extracents-(studentNum-i);
      }
      cout << "$" << total/100 << ".";
      int cents=total%100;
      if(cents<10)
      {
	 cout << "0" << cents << endl;
      }
      else
      {
	 cout << cents << endl;
      }
      cin >> studentNum;
   }
   return 0;
}
