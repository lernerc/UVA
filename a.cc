#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PC (__builtin_popcount)
const int MAX = 20;

void call(int A[MAX][MAX], int n,int sum[MAX],int subset,
	  bool tried[],vector<int>& ans){
   if(tried[subset])
      return;
   if(PC(subset)==1) {
      tried[subset]=true;
      for(int i=0;i<n;i++) {
	 if((1<<i) & subset) {
	    ans.push_back(i+1);
	    i=n;
	 }
      }
      return;
   }
   
   for(int i=0;i<n;i++) {
      if((1<<i) & subset) {
	 if(sum[i]>0) {
	    
	    for(int j=0;j<n;j++) {
	       sum[j]-=A[j][i];
	    }
	    subset-=(1<<i);
	    call(A,n,sum,subset,tried,ans);
	    tried[subset]=true;
	    subset+=(1<<i);
	    for(int j=0;j<n;j++) {
	       sum[j]+=A[j][i];
	    }
	 }
      }
   }

}

int main(){
   int T; cin >> T;
   while(T--){
      int n; cin >> n;
      int A[MAX][MAX];
      for(int i = 0; i < n; i++){
	 for(int j = 0; j < n; j++){
	    cin >> A[i][j];
	 }
      }
      bool tried[1 << 20]={false};
/*      for(int i=0;i<(1<<20);i++) {
	 tried[i]=0;
	 } */
      /* int perm[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};*/
      int sum[MAX];
      for(int i=0;i<n;i++) {
	 sum[i]=0;
	 for(int j=0;j<n;j++) {
	    sum[i]+=A[i][j];
	 }
      }
      vector<int> ans;
      call(A,n,sum,(1 << n)-1,tried,ans);

      sort(ans.begin(),ans.end());
      if(ans.size()==0) {
	 cout << "0" << endl;	 
      }
      else {
	 for(vector<int>::size_type i=0;i<ans.size();i++) {
	    if(i!=0) {
	       cout << " ";
	    }
	    cout << ans[i];
	 }
	 cout << endl;
      }
      
   }   
   return 0;
}

