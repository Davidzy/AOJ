#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f

#include <iostream>
#include <cstdio>
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
typedef pair <int,P> PP;
  
static const double EPS = 1e-8;
  
static const int tx[] = {+0,+1,+1,+1,+0,-1,-1,-1};
static const int ty[] = {-1,-1,+0,+1,+1,+1,+0,-1};

char stage[1001][1001];
int cost[1001][1001];
int H,W;

class State {
public:
  int x;
  int y;
  int cost;

  State(int x, int y, int cost){
    this->x = x;
    this->y = y;
    this->cost = cost;
  }

  bool operator<(State s) const {
    return cost < s.cost;
  }

  bool operator>(State s) const {
    return cost > s.cost;
  }
};

bool is_new_vacant_lot(int x, int y,int current_cost){
  if(stage[y][x] == '.') return false;

  int count = 0;
  int strongness = stage[y][x] - '0';

  for(int i = 0; i < 8; i++){
    int dx = x + tx[i];
    int dy = y + ty[i];
    if(dx < 0 || dx >= W || dy < 0 || dy >= H) continue;
    if(stage[dy][dx] == '.' && current_cost > cost[dy][dx]){
      count++;
    }
  }
  return (count >= strongness);
}

int main(){
  while(~scanf("%d %d",&H,&W)){
    memset(cost,0x3f,sizeof(cost));
    priority_queue<State,vector<State>,greater<State> > que;
    for(int y = 0; y < H; y++){
      char line[1001];
      scanf("%s",line);
      for(int x = 0; x < W; x++){
	stage[y][x] = line[x];
	if(line[x] == '.'){
	  que.push(State(x,y,0));
	  cost[y][x] = 0;
	}
      }
    }


    int res = 0;
    while(!que.empty()){
      State s = que.top();
      que.pop();
      res = max(s.cost,res);

      for(int i = 0; i < 8; i++){
	int dx = s.x + tx[i];
	int dy = s.y + ty[i];
	if(dx < 0 || dx >= W || dy < 0 || dy >= H) continue;
	if(cost[dy][dx] <= s.cost + 1) continue;
	if(!is_new_vacant_lot(dx,dy,s.cost + 1)) continue;
	
	stage[dy][dx] = '.';
	cost[dy][dx] = s.cost + 1;
	que.push(State(dx,dy,s.cost + 1));
      }
    }
    printf("%d\n",res);
  }
}
