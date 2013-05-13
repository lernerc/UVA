#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
string  genesABO[]={"AB","BA","AA","AO","OA","BB","BO","OB","OO"};
string typeABO[]={  "AB","AB","A"," A", "A", "B", "B", "B", "O"};
string genespos[]={"++","+-","-+","--"};
string typepos[]={ "+", "+", "+", "-"};

/*
bool possibleABO(int p1, int p2, int c) {
   if(c=="OO")
      return (p1=="AO"||p1=="BO"||p1=="OO")&&(p2=="AO"||p2=="BO"||p2=="OO");
   else if(c=="AA")
      return (p1=="AB"&&(p2=="AA"||p2=="AO"))||
	 (p2=="AB"&&(p1=="AA"||p1=="AO"))||
	 (p1=="AA"&&(p2=="AA"||p2=="AO"))||
	 (p2=="AA"&&(p1=="AA"||p1=="AO"))||
	 (p1=="AO"&&p2=="AO");
   else if(c=="AO")
      return (p1=="AB"&&(p2=="OO"||p2=="AO"||p2=="BO"))||
	 (p1=="AA"&&(p2=="OO"||p2=="AO"||p2=="BO"||p2=="AA"))||
	 (p1=="AO"&&(p2=="AO"||p2=="BO"||p2=="OO"))||
	 (p2=="AB"&&(p1=="OO"||p1=="AO"||p1=="BO"))||
	 (p2=="AA"&&(p1=="OO"||p1=="AO"||p1=="BO"||p1=="AA"))||
	 (p2=="AO"&&(p1=="AO"||p1=="BO"||p1=="OO"));
   case 
   
}
*/

int main() {

   map<string,string> bloodtype;
   for(int i=0;i<9;i++) {
      for(int j=0;j<4;j++) {
	 bloodtype[genesABO[i]+genespos[j]]=typeABO[i]+typepos[j];
	 cout << genesABO[i]+genespos[j] << " "
	      <<  bloodtype[genesABO[i]+genespos[j]] << endl;
      }
   }

   map<string,string> par;
   map<string,string> parch;
   for(int i=0;i<9;i++) {
      for(int j=0;j<4;j++) {
	 for(int w=0;w<9;w++) {
	    for(int q=0;q<4;q++) {
	       par[genesABO[i]+genespos[j]+genesABO[w]+genespos[q]]=
		  bloodtype[string(1,genesABO[i][0])+string(1,genesABO[w][0])+
			    string(1,genespos[j][0])+string(1,genespos[q][0])];
	       cout <<genesABO[i]+genespos[j]+genesABO[w]+genespos[q] << " "
		    << flush;
	       cout << par[genesABO[i]+genespos[j]+genesABO[w]+genespos[q]]
		    << endl;
	       parch[genesABO[i]+genespos[j]+string(1,genesABO[i][0])+
		     string(1,genesABO[w][0])+string(1,genespos[j][0])+
		     string(1,genespos[q][0])]=
		  bloodtype[genesABO[w]+genespos[q]];
//	       cout << genesABO[i]+genespos[j]+string(1,genesABO[i][0])+
//		  string(1,genesABO[w][0])+string(1,genespos[j][0])+
//		  genespos[q][0] << " " << parch[genesABO[i]+genespos[j]+
//						 string(1,genesABO[i][0])+
//						 string(1,genesABO[w][0])+
//						 string(1,genespos[j][0])+
//						 genespos[q][0]]  << endl;
	       
	    }
	 }
      }
   }
   int cases=1;
   string p1,p2,c;
   while(cin >> p1 >> p2 >> c && p1!="E" && p2!="N" && c!="D") {
      set<string> possible;
      cout << "Cases " << cases << ": ";
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
	 cout << p1 << " " << p2 << " "<< flush;
	 if(possible.size()>1) {
	    set<string>::iterator i=possible.begin();
	    cout << "{" << *i << flush;
	    i++;
	    for(;i!=possible.end();i++) {
	       cout << ", " << *i << flush; 
	    }
	    cout << "}" << flush;
	 } else if(possible.size()==1){
	    cout << *possible.begin();
	 } else {
	    cout << "IMPOSSIBLE" << flush;
	 }
	 cout << endl;
      } else if(p2=="?") {
	 for(int i=0;i<9;i++) {
	    for(int j=0;j<4;j++) {
	       for(int k=0;k<9;k++) {
		  for(int l=0;l<4;l++) {
		     if(bloodtype[genesABO[i]+genespos[j]]==p1
			//&& bloodtype[genesABO[k]+genespos[l]]==c
			) {
			if(par.find(genesABO[i]+genespos[j]+genesABO[k]+
				    genespos[l])!=par.end() &&
			   parch[genesABO[i]+genespos[j]+genesABO[k]+
				 genespos[l]]==c) {
			   possible.insert(bloodtype[genesABO[k]+
						     genespos[l]]);
			}
		     }
		  }
	       }
	    }
	 }
	 cout << p1 << " " << flush;
	 if(possible.size()>1) {
	    set<string>::iterator i=possible.begin();
	    cout << "{" << *i << flush;
	    i++;
	    for(;i!=possible.end();i++) {
	       cout << ", " << *i << flush; 
	    }
	    cout << "}" << flush;
	 } else if(possible.size()==1) {
	    cout << *possible.begin();
	 }
	 else {
	    cout << " IMPOSSIBLE" << flush;
	 }
	 cout << " " << c << endl;
      }
      
   }
   return 0;
}
