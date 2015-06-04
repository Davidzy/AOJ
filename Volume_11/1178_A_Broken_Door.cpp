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
 
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};
 
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

bool doors[51][51][51][51];
int state_cost[51][51][4];
int dp[51][51];

void compute_state_cost(int H,int W){

  memset(state_cost,0x3f,sizeof(state_cost));

  for(int sy = 0; sy < H; sy++){
    for(int sx = 0; sx < W; sx++){
      for(int dir = 0; dir < 4; dir++){
	int tmp_state_cost[51][51];
	memset(tmp_state_cost,0x3f,sizeof(tmp_state_cost));
	priority_queue<State> que;
	que.push(State(sx,sy,0));

	while(!que.empty()){
	  State s = que.top();
	  que.pop();
	  
	  for(int i = 0; i < 4; i++){
	    int dx = tx[i] + s.x;
	    int dy = ty[i] + s.y;
	    if(dx >= W || dy >= H || dx < 0 || dy < 0) continue;
	    if(doors[s.y][s.x][dy][dx]) continue;
	    if(dx == sx && dy == sy && dir == i) continue;
	    if(tmp_state_cost[dy][dx] <= s.cost + 1) continue;
	    tmp_state_cost[dy][dx] = s.cost + 1;
	    que.push(State(dx,dy,s.cost + 1));
	  }
	}

	state_cost[sy][sx][dir] = tmp_state_cost[H-1][W-1];
      }
    }
  } 

}

int main(){
  int H,W;

  while(~scanf("%d %d",&H,&W)){
    if(H == 0 && W == 0) break;

    int pos = 0;
    int patterns[] = {W - 1, W};
    int accumulate[31] = {};
    accumulate[0] = patterns[0];
    for(int i = 1; i < 30; i++){
      accumulate[i] = patterns[i % 2] + accumulate[i - 1];
    }
    while(pos < ((H - 1) * W) + (H * (W - 1))){
      int flag;
      scanf("%d",&flag);
      pos++;
      int depth = (lower_bound(accumulate,accumulate + 30,pos) - accumulate);
      int type = depth % 2;
      if(type == 0){
	int from_y = depth/2;
	int from_x = (pos - 1)- accumulate[depth - 1];
	int to_y = depth/2;
	int to_x = (pos - 1) - accumulate[depth - 1] + 1;
	doors[from_y][from_x][to_y][to_x] = (bool)flag;
	doors[to_y][to_x][from_y][from_x] = (bool)flag;
      }
      else{
	int from_y = depth/2;
	int from_x = (pos - 1) - accumulate[depth - 1];
	int to_y = depth/2 + 1;
	int to_x = (pos - 1) - accumulate[depth - 1];
	doors[from_y][from_x][to_y][to_x] = (bool)flag;
	doors[to_y][to_x][from_y][from_x] = (bool)flag;
      }
    }

    compute_state_cost(H,W);
  }
}
