#include <iostream>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
const int MAX=10;
int main()
{
   int r,d,s;
   bool doors[MAX][MAX];
   bool switches[MAX][MAX];
   pair<int,int> initial(1,1);
   while(cin >> r >> d >> s && r!=0 && d!=0 && s!=0)
   {
      pair<int,int> goal(r,pow(10,r));
      // filling doors and switches with false
      for(int i=0;i<MAX;i++)
      {
	 for(int j=0;j<MAX;j++)
	 {
	    doors[i][j]=false;
	    switches[i][j]=false;
	 }
      }
      // filling doors with it's connecting doors
      for(int i=0;i<d;i++)
      {
	 int x,y;
	 cin >> x >> y;
	 doors[x][y]=true;
	 doors[y][x]=true;
      }
      // filling switches so that x is the room you are in and y is the light
      // switches you control
      for(int i=0;i<s;i++)
      {
	 int x,y;
	 cin >> x >> y;
	 switches[x][y]=true;
      }
      queue<pair<int,int> > q;
      map<pair<int,int>,int> dist;
      map<pair<int,int>,int> pred;
      q.push(initial);
      dist[initial]=0;
      while(!q.empty())
      {
	 pair<int,int> curr=q.front();
	 q.pop();
	 if(curr==goal)
	    break;
	 for(;;)// all neighbour states s from curr by 1 move
	    // move by room or move by switching light on or off
	    // make the next state a pair<int,int> called s
	 {
	    
	    if(dist.find(s)!=dist.end()) //?
	       continue;
	    dist[s]=dist[curr]+1;
	    pred[s]=curr;
	 }
      }
      // if goal state then solvable (traverse backwards)
      // else not solvable
   }
   return 0;
}

// use if light is on and adjacency matrix to see if you can move
// use if you have switch to a light and turn it on or off depending on state
