#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;


void language(vector<string> &name, vector<vector<string> > &lang, string line) {
   istringstream iss(line);
   string tmp;
   iss >> tmp;
   name.push_back(tmp);
   vector<string> l;
   while(iss >> tmp) {
      for(int i = 0; i < (int)tmp.size(); i++) {
	 tmp[i] = tolower(tmp[i]);
      }
      l.push_back(tmp);
      
   }
   lang.push_back(l);
}

string wordInLang(vector<string>& name, vector<vector<string> > &lang,
		  string word) {
   for(int i = 0; i < (int)lang.size(); i++) {
      for(int j = 0; j < (int)lang[i].size(); j++) {
	 if(lang[i][j] == word)
	    return name[i];
      }
   }
   return "";
}

string determineLang(vector<string> &name, vector<vector<string> > &lang,
		   string line) {
   string word;
   for(int i = 0; i < (int)line.size(); i++) {
      if(isalpha(line[i]) || line[i] == '\'' || line[i] == '-') {
	 word += tolower(line[i]);
      } else {
	 string ans = wordInLang(name, lang, word);
	 if(ans != "")
	    return ans;
	 word.clear();
      }
      
   }
   string ans = wordInLang(name, lang, word);
   if(ans != "")
      return ans;
   // because of guarentees in problem do not need to worry about this
   return "";
}

int main() {

   vector<string> name;
   vector<vector<string> > lang; 
   int num;
   cin >> num;
   string line;
   // blankline
   getline(cin, line);
   for(int i = 0; i < num; i++) {
      getline(cin, line);
      language(name, lang, line);
   }
   getline(cin, line);
   while(getline(cin, line)) {
      string ans = determineLang(name, lang, line);
      cout << ans << endl;
   }

   
   return 0;
}
