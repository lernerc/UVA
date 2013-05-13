#include <iostream>
#include <vector>
using namespace std;

int letterNum(char c) {
   return c - 'A';
}

int main() {

   int cases;
   cin >> cases;
   char image[20][20];
   int regions[26];
   for(int x = 0; x < cases; ++x) {
      fill(regions, regions + 26, 0);
      int rows, cols, max, rest;
      cin >> rows >> cols >> max >> rest;
      for(int r = 0; r < rows; ++r) {
	 for(int c = 0; c < cols; ++c) {
	    cin >> image[r][c];
	    regions[letterNum(image[r][c])]++;
	 }
      }
      vector<char> index;
      index.push_back('A');
      for(int i = 1; i < 26; ++i) {
	 if(regions[i] > regions[letterNum(index[0])]) {
	    index.clear();
	    index.push_back(i + 'A');
	 } else if(regions[i] == regions[letterNum(index[0])]) {
	    index.push_back(i + 'A');
	 }
      }

      int bytes = 0;
      for(int r = 0; r < rows; ++r) {
	 for(int c = 0; c < cols; ++c) {
	    bool maxHappen = false;
	    for(int i = 0; i < index.size(); ++i) {
	       if(image[r][c] == index[i]) {
		  bytes += max;
		  maxHappen = true;
	       }
	    }
	    if(!maxHappen) {
	       bytes += rest;
	    }
	 }
      }
      cout << "Case " << x + 1 << ": " << bytes << endl;
   }
   
   return 0;
}
