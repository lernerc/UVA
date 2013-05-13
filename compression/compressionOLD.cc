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
   int datasets;
   cin >> datasets;
   for(int i=0;i<datasets;i++)
   {
      string line;
      getline(cin,line);
      while(line!="end.")
      {
	 istringstream isStr;
	 isStr.str(line);
	 string word;
	 while(isStr >> word)
	 {
	    bool isIdentifier=true;
	    for(string::size_type w=0;w<word.size();w++)
	    {
	       if(!isalnum(word[w]))
	       {
		  isIdentifier=false;
	       }
	    }
	    if(isIdentifier)
	    {
	       int k=0;
	       for(;k<size && k<2000;k++)
	       {
		  if(word==identifiers[k])
		  {
		     cout << "&" << k << " ";
		     break;
		  }
	       }
	       if(k==size)
	       {
		  if(word.size()>3 && word.size()<39)
		  {
		     identifiers[size]=word;
		     cout << "&" << size << " ";
		     size++;
		  }
		  else
		  {
		     cout << word << " ";
		  }
	       }
	    }
	    else
	    {
	       cout << word << " ";
	    }
	 }
	 cout << endl;
	 getline(cin,line);
      }
   }
   return 0;
}
