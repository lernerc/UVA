#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
string  genesABO[]={"AB","BA","AA","AO","OA","BB","BO","OB","OO"};
string typeABO[]={  "AB","AB","A", "A", "A", "B", "B", "B", "O"};
string genespos[]={"++","+-","-+","--"};
string typepos[]={ "+", "+", "+", "-"};

int main() {

   map<string,string> bloodtype;
   for(int i=0;i<9;i++) {
      for(int j=0;j<4;j++) {
	 bloodtype[genesABO[i]+genespos[j]]=typeABO[i]+typepos[j];
      }
   }

   map<string,string> par;
   map<string,vector<string> > parch;
   for(int i=0;i<9;i++) {
      for(int j=0;j<4;j++) {
	 for(int w=0;w<9;w++) {
	    for(int q=0;q<4;q++) {
	       par[genesABO[i]+genespos[j]+genesABO[w]+genespos[q]]=
		  bloodtype[string(1,genesABO[i][0])+string(1,genesABO[w][0])+
			    string(1,genespos[j][0])+string(1,genespos[q][0])];
	       parch[genesABO[i]+genespos[j]+string(1,genesABO[i][0])+
		     string(1,genesABO[w][0])+string(1,genespos[j][0])+
		     string(1,genespos[q][0])].push_back(
			bloodtype[genesABO[w]+genespos[q]]);
	    }
	 }
      }
   }
   int cases=1;
   string p1,p2,c;
   while(cin >> p1 >> p2 >> c && p1!="E" && p2!="N" && c!="D") {
      set<string> possible;
      cout << "Case " << cases << ": ";
      cases++;
      if(c=="?") {
	 for(int i=0;i<9;i++) {
	    for(int j=0;j<4;j++) {
	       for(int k=0;k<9;k++) {
		  for(int l=0;l<4;l++) {
		     if(bloodtype[genesABO[i]+genespos[j]]==p1 &&
			bloodtype[genesABO[k]+genespos[l]]==p2) {
			possible.insert(par[genesABO[i]+genespos[j]+
					 genesABO[k]+genespos[l]]);
		     }
		  }
	       }
	    }
	 }
	 cout << p1 << " " << p2 << " ";
	 if(possible.size()>1) {
	    set<string>::iterator i=possible.begin();
	    cout << "{" << *i;
	    i++;
	    for(;i!=possible.end();i++) {
	       cout << ", " << *i; 
	    }
	    cout << "}";
	 } else if(possible.size()==1){
	    cout << *possible.begin();
	 } else {
	    cout << "IMPOSSIBLE";
	 }
	 cout << endl;
      } else if(p2=="?") {
	 for(int i=0;i<9;i++) {
	    for(int j=0;j<4;j++) {
	       for(int k=0;k<9;k++) {
		  for(int l=0;l<4;l++) {
		     if(bloodtype[genesABO[i]+genespos[j]] == p1
			&& bloodtype[genesABO[k]+genespos[l]] == c) {
			vector<string> tmp = parch[genesABO[i]+genespos[j]
						   +genesABO[k]+genespos[l]];
			for(int i = 0; i < (int)tmp.size(); i++) {
			   if(tmp[i].size() > 0)
			      possible.insert(tmp[i]);
			   
			}
		     }
		  }
	       }
	    }
	 }
	 cout << p1 << " ";
	 if(possible.size()>1) {
	    set<string>::iterator i=possible.begin();
	    cout << "{" << *i;
	    i++;
	    for(;i!=possible.end();i++) {
	       cout << ", " << *i; 
	    }
	    cout << "}";
	 } else if(possible.size()==1) {
	    cout << *possible.begin();
	 }
	 else {
	    cout << "IMPOSSIBLE";
	 }
	 cout << " " << c << endl;
      }
      
   }
   return 0;
}
