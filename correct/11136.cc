//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 11136
// Description: Reads in the bills and put them as keys to a map where the
// value of each bill is the number of times that bill is present. Then the
// first and last element are subtracted and kept track of after each day and
// the total is output 
//*****************************************************************************
#include <map>
#include <iostream>
using namespace std;


int main() {

   // store the sum in a long long
   int days;
   while(cin >> days && days!=0) {
      long long cost=0;
      map<int,int> bills;
      for(int z=0;z<days;z++) {
	 int num_bills;
	 cin >> num_bills;
	 for(int q=0;q<num_bills;q++) {
	    int  bill;
	    cin >> bill;
	    if(bills.find(bill)!=bills.end())
	       bills[bill]++;
	    else
	       bills[bill]=1;
	 }
	 map<int,int>::iterator beg=bills.begin();
	 map<int,int>::reverse_iterator end=bills.rbegin();
	 cost+=end->first-beg->first;
	 if(beg->second<=1) {
	    bills.erase(beg);
	 } else {
	    beg->second--;
	 }
	 if(end->second<=1) {
	    int key=end->first;
	    bills.erase(key);
	 } else {
	    end->second--;
	 }
      }
      cout << cost << endl;
   }
   
   return 0;
}
