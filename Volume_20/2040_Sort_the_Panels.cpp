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
 
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};
 
static const double EPS = 1e-8;

class State {
public:
  int panel;
  int cost;
  int machine_pos;
  State(int panel,int cost,int machine_pos){
    this->panel = panel;
    this->cost = cost;
    this->machine_pos = machine_pos;
  }
  bool operator<(const State& s) const {
    return cost < s.cost;
  }
  bool operator>(const State& s) const {
    return cost > s.cost;
  }
};

int dp[16][1<<16];

int main(){
  int num_of_panels;
  while(~scanf("%d",&num_of_panels)){
    if(num_of_panels == 0) break;

    int panels[2] = {};
    for(int set_i = 0; set_i < 2; set_i++){
      string panel;
      cin >> panel;
      for(int pos = 0; pos < num_of_panels; pos++){
	if(panel[pos] == 'B'){
	  panels[set_i] |= (1<<pos);
	}
      }
    }
  
    priority_queue<State,vector<State>,greater<State> > que;

    memset(dp,0x3f,sizeof(dp));
    for(int pos = 0; pos < num_of_panels; pos++){
      dp[pos][panels[0]] = 0;
      que.push(State(panels[0],0,pos));      
    }

    while(!que.empty()){
      State s = que.top();
      que.pop();

      if(s.panel == panels[1]) goto found;

      for(int from = 0; from < num_of_panels; from++){
	for(int to = 0; to < num_of_panels; to++){
	  if(from == to) continue;

	  int from_bit = (s.panel >> from) & 1;
	  int to_bit = (s.panel >> to) & 1;
	  
	  int next_panel = s.panel;
	  if(to_bit == 1){
	    next_panel = next_panel | (1 << from);
	  }
	  else {
	    next_panel = next_panel & (((1<<num_of_panels) - 1) ^ (1 << from));
	  }
	  
	  if(from_bit == 1){
	    next_panel = next_panel | (1 << to);
	  }
	  else {
	    next_panel = next_panel & (((1<<num_of_panels) - 1) ^ (1 << to));
	  }
	  
	  if(dp[to][next_panel] <= s.cost + abs(to - from) + abs(from - s.machine_pos)) continue;
	  dp[to][next_panel] = s.cost + abs(to - from) + abs(from - s.machine_pos);
	  que.push(State(next_panel,s.cost + abs(to - from) + abs(from - s.machine_pos),to));
	}
      }
    }
  found:;
    int res = INF;
    for(int pos = 0; pos < num_of_panels; pos++){
      res = min(res,dp[pos][panels[1]]);
    }
    printf("%d\n",res);
  }
}
