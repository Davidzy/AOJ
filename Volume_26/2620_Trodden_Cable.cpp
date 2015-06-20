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
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int cost[1010][1010];
int dp[1010][1010];

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

int main(){
  int W, H;
  int num_of_staff;

  map<char,int> dict;
  dict['U'] = 0;
  dict['R'] = 1;
  dict['D'] = 2;
  dict['L'] = 3;

  while(~scanf("%d %d %d",&W,&H,&num_of_staff)){
    memset(cost,0,sizeof(cost));
    memset(dp,0x3f,sizeof(dp));

    int lan_start_x,lan_start_y;
    int lan_end_x,lan_end_y;
    scanf("%d %d %d %d",
	  &lan_start_x,&lan_start_y,
	  &lan_end_x,&lan_end_y);
    for(int staff_i = 0; staff_i < num_of_staff; staff_i++){
      int current_x,current_y;
      int repeat_time;
      string commands;
      cin >> current_x >> current_y >> repeat_time >> commands;
      current_x = 2 * current_x + 1;
      current_y = 2 * current_y + 1;

      for(int repeat_i = 0; repeat_i < repeat_time; repeat_i++){
	for(int command_i = 0; command_i < commands.size(); command_i++){
	  int dir = dict[commands[command_i]];
	  int dx = current_x + tx[dir] * 2;
	  int dy = current_y + ty[dir] * 2;
	  if(dx >= 2 * W || dx < 0 || dy >= 2 * H || dy < 0) continue;
	  
	  int mx = current_x + tx[dir];
	  int my = current_y + ty[dir];
	  
	  cost[my][mx]++;
	  current_x = dx;
	  current_y = dy;
	}
      }
    }
    priority_queue<State,vector<State>,greater<State> > que;
    que.push(State(lan_start_x * 2, lan_start_y * 2, 0));
    dp[lan_start_y * 2][lan_start_x * 2] = 0;
    while(!que.empty()){
      State s = que.top();
      que.pop();
      for(int i = 0; i < 4; i++){
	int dx = s.x + tx[i] * 2;
	int dy = s.y + ty[i] * 2;
	if(dx >= 2 * W + 1 || dx < 0 || dy >= 2 * H + 1 || dy < 0) continue;

	int mx = s.x + tx[i];
	int my = s.y + ty[i];
	if(dp[dy][dx] <= s.cost + cost[my][mx]) continue;
	dp[dy][dx] = s.cost + cost[my][mx];
	que.push(State(dx, dy, s.cost + cost[my][mx]));
      }
    }

    printf("%d\n",dp[lan_end_y * 2][lan_end_x * 2]);
  }
}
