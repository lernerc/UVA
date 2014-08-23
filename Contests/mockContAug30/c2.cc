#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string letters[114] = {"ac", "ag", "al", "am", "ar", "as", "at", "au", "b",
		       "ba", "be", "bh", "bi", "bk", "br", "c", "ca", "cd",
		       "ce", "cf", "cl", "cm", "cn", "co", "cr", "cs", "cu",
		       "db", "ds", "dy", "er", "es", "eu", "f", "fe", "fl",
		       "fm", "fr", "ga", "gd", "ge", "h", "he", "hf", "hg",
		       "ho", "hs", "i", "in", "ir", "k", "kr", "la", "li",
		       "lr", "lu", "lv", "md", "mg", "mn", "mo", "mt", "n",
		       "na", "nb", "nd", "ne", "ni", "no", "np", "o", "os",
		       "p", "pa", "pb", "pd", "pm", "po", "pr", "pt", "pu",
		       "ra", "rb", "re", "rf", "rg", "rh", "rn", "ru", "s",
		       "sb", "sc", "se", "sg", "si", "sm", "sn", "sr", "ta",
		       "tb", "tc", "te", "th", "ti", "tl", "tm", "u", "v", "w",
		       "xe", "y", "yb", "zn", "zr"};

int index[26] = {0, 8, 15, 27, 30, 33, 38, 41, 47, 50, 50, 52, 57, 62, 70, 72,
		 81, 81, 89, 98, 106, 107, 108, 109, 110, 112};



bool work;
int works[50002];
bool test(const string& a, int w) {
   if(works[w] != -1)
      return works[w];
   if(w >= (int)a.size()) {
      return works[w] = true;
   }
   bool something = false;
   int start = index[a[w] - 'a'];
   int end = 114;
   if(a[w] - 'a' < 25) {
      end = index[a[w] - 'a' + 1];
   }
   for(int i = start; i < end; i++) {
      work = true;
      if(something)
	 break;
      if(w + letters[i].size() <= (int)a.size()) {
	 for(int j = 0; j < (int)letters[i].size(); j++) {
	    if(a[w + j] != letters[i][j])
	       work = false;
	 }
	 if(work) {
	    if(test(a, w + letters[i].size()))
	       something = works[w] = true;
	 }
      }
   }
   return works[w] = something;
}

int main() {
   int cases;
   cin >> cases;
   for(int i = 0; i < cases; i++) {
      string word;
      fill(works, works + 50002, -1);
      cin >> word;
      for(int i = 0; i < (int)word.size(); i++) {
	 word[i] = (char)tolower(word[i]);
      }
      bool can = test(word, 0);
      if(can) {
	 cout << "YES" << endl;
      } else {
	 cout << "NO" << endl;
      }
   }
   
   return 0;
}
