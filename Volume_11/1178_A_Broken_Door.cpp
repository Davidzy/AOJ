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
	    if(s.x == sx && s.y == sy && dir == i) continue;
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


int compute_goal2start_cost(int H,int W){
  compute_mid2goal_cost(H,W);

  int goal2start_cost[51][51];
  memset(goal2start_cost,0x3f,sizeof(goal2start_cost));

  priority_queue<State,vector<State>,greater<State> > que;
  que.push(State(W-1,H-1,0));
  goal2start_cost[H-1][W-1] = 0;
  while(!que.empty()){
    State s = que.top();
    que.pop();
    for(int i = 0; i < 4; i++){
      int dx = tx[i] + s.x;
      int dy = ty[i] + s.y;
      if(dx >= W || dy >= H || dx < 0 || dy < 0) continue;
      if(walls[s.y][s.x][dy][dx]) continue;

      int next_cost = max(s.cost + 1,mid2goal_cost[dy][dx][(i+2)%4]);
      if(goal2start_cost[dy][dx] <= next_cost) continue;
      goal2start_cost[dy][dx] = next_cost;
      que.push(State(dx,dy,next_cost));
    }
  }
  return (goal2start_cost[0][0] >= INF ? -1 : goal2start_cost[0][0]);
}

int main(){
  int H,W;

  while(~scanf("%d %d",&H,&W)){
    if(H == 0 && W == 0) break;
    memset(walls,false,sizeof(walls));

    int patterns[] = {W - 1, W};
    int accumulate[61] = {};
    for(int i = 0; i < 60; i++){
      accumulate[i + 1] = patterns[i % 2] + accumulate[i];
    }

    int pos = 0;
    while(pos < ((H - 1) * W) + (H * (W - 1))){
      int flag;
      scanf("%d",&flag);
      int depth = (lower_bound(accumulate,accumulate + 61,pos+1) - accumulate);
      int type = (depth-1) % 2;
      if(type == 0){
	int from_y = (depth - 1)/2;
	int from_x = pos - accumulate[depth - 1];
	int to_y = (depth - 1)/2;
	int to_x = pos - accumulate[depth - 1] + 1;
	walls[from_y][from_x][to_y][to_x] = (flag == 1 ? true : false);
	walls[to_y][to_x][from_y][from_x] = (flag == 1 ? true : false);
      }
      else{
	int from_y = (depth-1)/2;
	int from_x = pos - accumulate[depth - 1];
	int to_y = (depth-1)/2 + 1;
	int to_x = pos - accumulate[depth - 1];
	walls[from_y][from_x][to_y][to_x] = (flag == 1 ? true : false);
	walls[to_y][to_x][from_y][from_x] = (flag == 1 ? true : false);
      }
      pos++;
    }
    printf("%d\n",compute_goal2start_cost(H,W));
  }
}
