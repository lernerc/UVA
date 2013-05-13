//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number:501
// Description: Reads in all the elements in the black box and put them into an
// array. Then two priority queues are used, where one holds all the elements
// after the element accessed by get and the other holds the element accessed
// by get at the top and the elements below it underneath.
//*****************************************************************************
// You Said this is okay Howard.
#include<iostream>
#include<queue>
using namespace std;

int added[30000];

int main() {

  int M,N, cases;

  cin >> cases;
  for(int i=0;i<cases;i++) {
     if(i!=0)
	cout << endl;
     
     cin >> M >> N;
     for(int w=0;w<M;w++) {
	cin >> added[w];
     }
     priority_queue<int, vector<int>, less<int> > place;
     priority_queue<int, vector<int>, greater<int> > rest;
     
     int p;
     int get=1;
     int array_place=0;
     for(int w=0;w<N;w++) {
	cin >> p;
	for(;array_place<p;array_place++) {
	   if(!place.empty() && place.size()<get) {
	      if(!rest.empty()) {
		 if(rest.top()<added[array_place]) {
		    place.push(rest.top());
		    rest.pop();
		    rest.push(added[array_place]);
		 } else { // rest.top()>=added[array_place]
		    place.push(added[array_place]);
		 }
	      } else { // rest is empty
		 place.push(added[array_place]);
	      }
	   } else if(!place.empty() && place.size()>=get) {
	      if(place.top()<added[array_place]) {
		 rest.push(added[array_place]);
	      } else {
		 rest.push(place.top());
		 place.pop();
	       place.push(added[array_place]);
	      }
	   } else if(place.empty()) { // place is empty
	      place.push(added[array_place]);
	   }
	}
     
	if(place.size()<p) {
	   while(place.size()<get) {
	      if(!rest.empty()) {
		 place.push(rest.top());
		 rest.pop();
	      }
	   }
	} else if(place.size()>p) {
	   while(place.size()>get) {
	      if(!place.empty()) {
		 rest.push(place.top());
	      place.pop();
	      }
	   }
	}
	cout << place.top() << endl;
	get++;
     }
     
  }
  
  return 0;
}
