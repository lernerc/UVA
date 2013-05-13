//*****************************************************************************
// CPSC 3200          Professor: Howard Cheng
//                    Teaching Assistant: Darcy Best
// Written By: Camara Lerner
// Problem number: 10004 
// Description: I used DFS to traverse through the graph and apply alternating
// colours as it went through the graph, and it returned whether adjacent nodes
// had different colours
//*****************************************************************************
#include <iostream>
using namespace std;

int colours[200];
bool adjmatrix[200][200];

bool bicoloured(int v, int next_colour, bool visited[], int n) {
   if(visited[v]) {
      return colours[v] == next_colour;
   }
   visited[v] = true;
   colours[v] = next_colour;
   bool works = true;
   for(int i = 0; i < n; i++) {
      if(adjmatrix[i][v]) {
	 works = works && bicoloured(i, (next_colour + 1) % 2, visited, n);
      }
   }
   return works;
}

int main() {
   int n = 0;
   while(cin >> n && n != 0) {
      bool visited[200]={false};
      for(int i = 0; i < n; i++) {
	 for(int j = 0; j < n; j++) {
	    adjmatrix[i][j] = false;
	 }
	 colours[i] = 0;
      }
      int l;
      cin >> l;
      int x, y;
      for(int i = 0; i < l; i++) {
	 cin >> x >> y;
	 adjmatrix[x][y] = adjmatrix[y][x] = true;
      }
      
      if( bicoloured(x, 0, visited, n)) {
	 cout << "BICOLORABLE." << endl;
      } else {
	 cout << "NOT BICOLORABLE." << endl;
      }

      
   }						\

   return 0;
}
