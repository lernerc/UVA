#include <iostream>
#include <stack>
#include <queue>
#include <stack>
using namespace std;

Data data[1000];

Class Data{
  public:
   Data() {}
   friend istream& operator>>(istream& in, Data& a);
   char type;
   int num;
};

bool isStack(const int size) {
   stack<int> st;
   switch(mv) {
      case 1:
	 st.push_back(num);
	 break;
      case 2:
	 if(st.back() != num) {
	    isst = false;
	 }
	 st.pop_back();
	 break;
      default:
	 cerr << "problem with the way information is being read" << endl;
	 break;
   };
   
}

int main() {

   int lines, mv, num;
   while(cin >> lines) {
      bool isst = true, isque = true, ispque = true;
         queue<int> que;
      priority_queue<int> pque;
      for(int i = 0; i < lines; i++) {
	 cin >> 
      }
   }
   return 0;
}
