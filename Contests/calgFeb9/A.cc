#include <iostream>
#include <iomanip>
using namespace std;

int go[6]={1,2,3,3,4,10};
int ev[7]={1,2,2,2,3,5,11};
int main() {
   int battles;
   cin >> battles;
   for(int i=1;i<=battles;i++) {
      cout << "Battle " << i << ": "<< flush;
      int good=0;
      for(int j=0;j<6;j++) {
	 int temp;
	 cin >> temp;
	 good+=temp*go[j];
      }
      int evil=0;
      for(int j=0;j<7;j++) {
	 int temp;
	 cin >> temp;
	 evil+=temp*ev[j];
      }
      if(good>evil) {
	 cout << "Good triumphs over Evil" << endl;
      } else if(good<evil) {
	 cout << "Evil eradicates all trace of Good" << endl;
      } else {
	 cout << "No victor on this battle field" << endl;
      }
   }
   return 0;
}
