#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;
 
static const int tx[] = {+0,+1,+0,-1};
static const int ty[] = {-1,+0,+1,+0};
 
static const double EPS = 1e-8;

class State {
public:
  int x;
  int y;
  int cost;
  State(int x,int y,int cost)
    : x(x), y(y), cost(cost) {}
  bool operator<(const State& s) const {
    return cost < s.cost;
  }
  bool operator>(const State& s) const {
    return cost > s.cost;
  }
};

bool walls[51][51][51][51];
int mid2goal_cost[51][51][4];

void compute_mid2goal_cost(int H,int W){

  memset(mid2goal_cost,0x3f,sizeof(mid2goal_cost));

  for(int sy = 0; sy < H; sy++){
    for(int sx = 0; sx < W; sx++){
      for(int dir = 0; dir < 4; dir++){
	int tmp_mid2goal_cost[51][51];
	memset(tmp_mid2goal_cost,0x3f,sizeof(tmp_mid2goal_cost));
	priority_queue<State,vector<State>,greater<State> > que;
	que.push(State(sx,sy,0));
	tmp_mid2goal_cost[sy][sx] = 0;
	while(!que.empty()){
	  State s = que.top();
	  que.pop();
	  
	  for(int i = 0; i < 4; i++){
	    int dx = tx[i] + s.x;
	    int dy = ty[i] + s.y;
	    if(dx >= W || dy >= H || dx < 0 || dy < 0) continue;
	    if(walls[s.y][s.x][dy][dx]) continue;
	    if(!walls[s.y][s.x][dy][dx] && dx == sx && dy == sy && dir == i) continue;
	    if(tmp_mid2goal_cost[dy][dx] <= s.cost + 1) continue;
	    tmp_mid2goal_cost[dy][dx] = s.cost + 1;
	    que.push(State(dx,dy,s.cost + 1));
	  }
	}

	mid2goal_cost[sy][sx][dir] = tmp_mid2goal_cost[H-1][W-1];
      }
    }
  } 
}


int compute_start2goal_cost(int H,int W){
  compute_mid2goal_cost(H,W);

  int start2mid_cost[51][51];
  memset(start2mid_cost,0x3f,sizeof(start2mid_cost));

  priority_queue<State,vector<State>,greater<State> > que;
  que.push(State(0,0,0));
  start2mid_cost[0][0] = 0;
  while(!que.empty()){
    State s = que.top();
    que.pop();
    for(int i = 0; i < 4; i++){
      int dx = tx[i] + s.x;
      int dy = ty[i] + s.y;
      if(dx >= W || dy >= H || dx < 0 || dy < 0) continue;
      if(walls[s.y][s.x][dy][dx]) continue;
      if(start2mid_cost[dy][dx] <= s.cost + 1) continue;
      start2mid_cost[dy][dx] = s.cost + 1;
      que.push(State(dx,dy,s.cost + 1));
    }
  }
  
  bool isok = true;
  int min_cost = INF;
  for(int sy = 0; sy < H; sy++){
    for(int sx = 0; sx < W; sx++){
      for(int i = 0; i < 4; i++){
	int dx = tx[i] + sx;
	int dy = ty[i] + sy;
	if(dx >= W || dy >= H || dx < 0 || dy < 0) continue;
	if(walls[sy][sx][dy][dx]) continue;
	int cost = start2mid_cost[sy][sx] + mid2goal_cost[sy][sx][i];
	min_cost = min(cost,min_cost);
	if(cost >= INF) isok = false;
      }
    }
  }
  return (isok ? min_cost + 2 : -1);
}

int main(){
  int H,W;

  while(~scanf("%d %d",&H,&W)){
    if(H == 0 && W == 0) break;
    memset(walls,false,sizeof(walls));

    int patterns[] = {W - 1, W};
    int accumulate[41] = {};
    accumulate[0] = patterns[0];
    for(int i = 1; i <= 40; i++){
      accumulate[i] = patterns[i % 2] + accumulate[i - 1];
    }

    int pos = 0;
    while(pos < ((H - 1) * W) + (H * (W - 1))){
      int flag;
      scanf("%d",&flag);
      pos++;
      int depth = (lower_bound(accumulate,accumulate + 41,pos) - accumulate);
      int type = depth % 2;
      if(type == 0){
	int from_y = depth/2;
	int from_x = (pos - 1) - accumulate[depth - 1];
	int to_y = depth/2;
	int to_x = (pos - 1) - accumulate[depth - 1] + 1;
	walls[from_y][from_x][to_y][to_x] = (flag == 1 ? true : false);
	walls[to_y][to_x][from_y][from_x] = (flag == 1 ? true : false);
      }
      else{
	int from_y = depth/2;
	int from_x = (pos - 1) - accumulate[depth - 1];
	int to_y = depth/2 + 1;
	int to_x = (pos - 1) - accumulate[depth - 1];
	walls[from_y][from_x][to_y][to_x] = (flag == 1 ? true : false);
	walls[to_y][to_x][from_y][from_x] = (flag == 1 ? true : false);
      }
    }
    
    // for(int sy = 0; sy < 3; sy++){
    //   for(int sx = 0; sx < 3; sx++){
    // 	for(int gy = 0; gy < 3; gy++){
    // 	  for(int gx = 0; gx < 3; gx++){
    // 	    printf("%d %d %d %d %s\n",sx,sy,gx,gy,walls[sy][sx][gy][gx] ? "on" : "off");
    // 	  }
    // 	}
    //   }
    // }

    printf("%d\n",compute_start2goal_cost(H,W));
  }
}
