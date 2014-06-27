#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

long long inv=0;

int num[100000];
int B[100000];

void mergesort(int A[], int s, int e) {
   if(e-s<=1) return;
   int m=(s+e)/2;
   mergesort(A,s,m);
   mergesort(A,m,e);
   int k=0,i=s,j=m; 
   while(i<m&& j<e) {
      if(A[i]<=A[j]) {
	 B[k++]=A[i++];
      } else {
	 inv+=(m-i);
	 B[k++]=A[j++];
      }
   }
   while(i<m) B[k++]=A[i++];
   while(j<e) B[k++]=A[j++];
   copy(B,B+k,A+s);
}

int main() {
   int hobbits;
   while(cin >> hobbits && hobbits!=0) {
      // reading in the hobbits and turning them into numbers
      map<string,int> numbers;
      for(int i=0;i<hobbits;i++) {
	 string key;
	 cin >> key;
	 numbers[key]=i;
      }
      for(int i=0;i<hobbits;i++) {
	 string key;
	 cin >> key;
	 num[i]=numbers[key];	 
      }

      inv=0;
      mergesort(num,0,hobbits);
      cout << inv << endl;
   }
  
   return 0;
}

