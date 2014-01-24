#include <iostream>
#include <string>
using namespace std;

const string orig = "the quick brown fox jumps over the lazy dog";
const string alph = "abcdefghijklmnopqrstuvwxyz";


char test[27];
char replace[27];
string input[101];

bool check(const int line) {
   if(input[line].size() != orig.size())
      return false;
   //cerr << "found that line: " << line << " matches" << endl;
   fill(test, test + 26, '.');
   for(int i = 0; i < (int)orig.size(); i++) {
      int idx = orig[i] - 'a';
      if(orig[i] == ' ' && input[line][i] == ' ')
	 continue;
      else if(orig[i] == ' ' || input[line][i] == ' ')
	 return false;
      if(test[idx] == '.') {
	 test[idx] = input[line][i];
	 replace[input[line][i] - 'a'] = orig[i];
      } else {
	 if(test[idx] != input[line][i])
	    return false;
      }
   }
   for(int i = 0; i < 26; i++) {
      bool happen = false;
      for(int j = 0; j < 26; j++) {
	 if(!happen && alph[i] == replace[j])
	    happen = true;
	 if(!happen && alph[i] == replace[j])
	    happen = false;
      }
      if(!happen)
	 return false;
   }
   return true;
}

void decode(const int lines) {
   for(int i = 0; i < lines; i++) {
      for(int j = 0; j < (int)input[i].size(); j++) {
	 if(input[i][j] != ' ')
	    cout << replace[(int)(input[i][j] - 'a')];
	 else
	    cout << ' ';
      }
      cout << endl;
   }
   
}

int main() {
   int lines = 0;
   while(getline(cin,input[lines])) {
      lines++;
   }
   //cerr << lines << endl;
   for(int i = 0; i < lines; i++) {
      if(check(i)) {
	 decode(lines);
	 goto end;
      }
   }
   cout << "No solution." << endl;
   
  end:
   return 0;
}
