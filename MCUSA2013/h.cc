#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string words[20];
int cases = 1;
void doCase(int n, string s) {
   for(int i = 0; i < n; i++)
      cin >> words[i];
   map<char, int> num;
   map<int, char> lett;
   for(int i = 0; i < (int)s.size(); i++) {
      num[s[i]] = i;
      lett[i] = s[i];
   }
   for(int i = 0; i < n; i++) 
      for(int j = 0; j < (int)words[i].size(); j++)
	 words[i][j] = num[words[i][j]];
   sort(words, words + n);
   for(int i = 0; i < n; i++) 
      for(int j = 0; j < (int)words[i].size(); j++)
	 words[i][j] = lett[words[i][j]];
   cout << "year " << cases << endl;
   for(int i = 0; i < n; i++) {
      cout << words[i] << endl;
   }

}

int main() {
   int n;
   string s;
   while(cin >> n && n != 0) {
      cin >> s;
      doCase(n, s);
      cases++;
   }
   
   return 0;
}
