#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dr[4] = { 0, 1, -1,  0};
int dc[4] = { 1, 0,  0, -1};

int k, w, h;
int kling[26];
int Ei, Ej;

char grid[1000][1000];
bool visited[1000][1000];
long long D[1000][1000];

bool valid(int i, int j) {
   return (i >= 0) && (i < h) && (j >= 0) && (j < w); 
}
      
void dijkstra() {
   
   typedef pair<int, int> pii;
   typedef pair<long long, pii> plii;
   priority_queue<plii, vector<plii>, greater<plii> > fringe;
      
   for(int i = 0; i < h; i++) {
      fill(D[i], D[i] + w, -1);
      fill(visited[i], visited[i] + w, false);
   }
   
   D[Ei][Ej] = 0;
   fringe.push(make_pair(0,make_pair(Ei, Ej)));

   while(!fringe.empty()) {
      plii next = fringe.top();
      fringe.pop();
      pii u = next.second;
      if(visited[u.first][u.second]) continue;
      visited[u.first][u.second] = true;
      
      for(int i = 0; i < 4; i++) {
	 if(!valid(u.first + dr[i], u.second + dc[i])) continue;
	 pii v = make_pair(u.first + dr[i], u.second + dc[i]);
	 long long weight = kling[grid[v.first][v.second] - 'A'] + next.first;
	 if(visited[v.first][v.second]) continue;
	 if(D[v.first][v.second] == -1 || weight < D[v.first][v.second]) {
	    D[v.first][v.second] = weight;
	    fringe.push(make_pair(weight, v));
	 }
      }
   }
}

void doCase() {

   cin >> k >> w >> h;
   for(int i = 0; i < k; i++) {
      char W;
      cin >> W;
      cin >> kling[W-'A'];
   }
   for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	 cin >> grid[i][j];
	 if(grid[i][j] == 'E') {
	    Ei = i;
	    Ej = j;
	 }
      }
   }

   dijkstra();
/*   for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	 cout << D[i][j] << " ";
      }
      cout << endl;
   }

   cout << "Ei: " << Ei << " Ej: " << Ej << endl;
   */

   // traverse the perimeter and smallest number is answer
   long long answer = 1000000000000LL;
   //top
   for(int i = 0; i < w; i++) {
      if(D[0][i] != -1)
	 answer = min(answer, D[0][i]);
      //cout << D[0][i] << " ";
   }
   //cout << endl;
      
   //bottom
   for(int i = 0; i < w; i++) {
      if(D[h-1][i] != -1)
	 answer = min(answer, D[h-1][i]);
      //cout << D[h-1][i]<< " ";
   }
   //cout << endl;
      
   //left side
   for(int i = 0; i < h; i++) {
      if(D[i][0] != -1)
	 answer = min(answer, D[i][0]);
      // cout << D[i][0] << " ";
   }
   //cout << endl;
      
   //right side
   for(int i = 0; i < h; i++) {
      if(D[i][w-1] != -1)
	 answer = min(answer, D[i][w-1]);
//      cout << D[i][w-1] << " ";
   }
   //cout << endl;
   cout << answer << endl;


}

int main() {
   int cases;
   cin >> cases;
   for(int z = 0; z < cases; z++) {
      doCase();
   }
      
   return 0;
}
