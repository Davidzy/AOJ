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

struct State {
  int point;
  int total_cost;
  int cost2zero_times;
  State(int p) : point(p),total_cost(0),cost2zero_times(0) {}
  State(int p,int tc,int cz)
    : point(p), total_cost(tc),cost2zero_times(cz) {}
  bool operator<(const State& s) const{
    return cost2zero_times < s.cost2zero_times;
  }
  bool operator>(const State& s) const{
    return cost2zero_times > s.cost2zero_times;
  }
};

int dp[101][1001];

int bfs(const vector<P> edges[101],int num_of_nodes,int target_cost){
  int res = INF;
  priority_queue<State,vector<State>,greater<State> > que;
  que.push(State(0));
  while(!que.empty()){
    State s = que.top();
    if(s.point == num_of_nodes - 1 && dp[s.point][s.cost2zero_times] <= target_cost){
      return s.cost2zero_times;
    }
    que.pop();
    for(int edge_i = 0; edge_i < edges[s.point].size(); edge_i++){
      int next = edges[s.point][edge_i].first;
      int cost = edges[s.point][edge_i].second;
      if(dp[next][s.cost2zero_times] > s.total_cost + cost){
	dp[next][s.cost2zero_times] = s.total_cost + cost;
	que.push(State(next,s.total_cost + cost,s.cost2zero_times));
      }
      if(dp[next][s.cost2zero_times + 1] > s.total_cost){
	dp[next][s.cost2zero_times + 1] = s.total_cost;
	que.push(State(next,s.total_cost,s.cost2zero_times + 1));
      }
    }
  }
  return res;
}

int main(){
  int num_of_nodes;
  int num_of_edges;
  int target_cost;
  while(~scanf("%d %d %d",
	       &num_of_nodes,
	       &num_of_edges,
	       &target_cost)){
    if(num_of_nodes == 0 && num_of_edges == 0 && target_cost == 0){
      break;
    }
    memset(dp,0x3f,sizeof(dp));
    vector<P> edges[101];
    for(int edge_i = 0; edge_i < num_of_edges; edge_i++){
      int src,dst,cost;
      scanf("%d %d %d",&src,&dst,&cost);
      src--; dst--;
      edges[src].push_back(P(dst,cost));
    }
    vector<int> current_cost;
    dp[0][0] = 0;
    printf("%d\n",bfs(edges,num_of_nodes,target_cost));
  }
}
