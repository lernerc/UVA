#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

// idenifiers which are added to as you find more words that are
// found that are 3 to 39 characters long
string identifiers[2000]={"var","end","for","the","else","case",
			  "goto","const","label","while","begin",
			  "until","repeat","downto","function",
			  "procedure"};

int main()
{
   int size=16;
   int cases;
   cin >> cases;
   for(int i=0;i<cases;i++)
   {
      string line;
      do
      {
	 getline(cin,line);
	 string word;
	 word.clear();
	 for(string::size_type w=0;w<line.size();w++)
	 {
	    bool isIdentifier=false;
	    if(isalnum(line[w]))
	    {
	       word+=line[w];
	       for(int ID=0;ID<size;ID++)
	       {
		  if(word==identifiers[ID])
		  {
		     cout << "&" << ID;
		     word.clear();
		  }
	       }
	       
	    }
	    else
	    {
	       if(word.size()>2 && word.size()<40)
	       {
		  identifiers[size]=word;
		  size++;

		  cout << word << line[w];
		  word.clear();
	       }
	       else
	       {
		  cout << word << line[w];
		  word.clear();
	       }
	    }
	 }
      	 cout << endl;
      }
      while(line!="end.");
   }
   return 0;
}
