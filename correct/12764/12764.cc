#include <iostream>
#include <string>
using namespace std;

string emotion[3][10] = {
   {"\\ / ", " o  ", "    ", "    ", "_o_ ", "\\o/ ", "\\o_ ", "\\o/ ", "    ", " o  "},
   {" |  ", "/|\\ ", "    ", "    ", " |  ", " |  ", "\\|  ", "\\|/ ", " __o", "( ) "},
   {"/o\\ ", "/ \\ ", "__\\o", "\\_\\o", "/ \\ ", "/ \\ ", " |  ", "    ", "/  |", "/ \\ "}
};

int main() {
   int M;
   cin >> M;
   string mv;
   while(M--) {
      cin >> mv;
      for(int j = 0; j < 3; j++) {
	 for(int i = 0; i < (int)mv.size(); i++) {
	    if(i!=0) {
	       cout << " ";
	    }
	    cout << emotion[j][mv[i]-'0'];
	 }
	 cout << endl;
      }
      cout << endl;
   }
   return 0;
}
