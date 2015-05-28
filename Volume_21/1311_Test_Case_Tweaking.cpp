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
  vector<int> cost_log;
  State(int p) : point(p) {}
  State(int p,const vector<int>& cl)
    : point(p), cost_log(cl) {}
};

bool visited[101];

int dfs(const vector<P> edges[101],int num_of_nodes,int target_cost,
	int point,vector<int> current_cost){

  if(point == num_of_nodes - 1){
    sort(current_cost.begin(),current_cost.end(),greater<int>());
    int sum = 0;
    for(int i = 0; i < current_cost.size(); i++){
      sum += current_cost[i];
    }
    int ans = 0;
    for(int i = 0; i < current_cost.size(); i++){
      sum -= current_cost[i];
      ans++;
      if(sum <= target_cost){
	break;
      }
    }
    return ans;
  }

  int res = INF;
  for(int edge_i = 0; edge_i < edges[point].size(); edge_i++){
    int next = edges[point][edge_i].first;
    int cost = edges[point][edge_i].second;
    if(visited[next]) continue;

    current_cost.push_back(cost);
    visited[next] = true;
    res = min(res,dfs(edges,num_of_nodes,target_cost,next,current_cost));
    visited[next] = false;
    current_cost.pop_back();
  }
  return res;
}

int bfs(const vector<P> edges[101],int num_of_nodes,int target_cost){
  int res = INF;
  queue<State> que;
  que.push(State(0));
  while(!que.empty()){
    State s = que.front();
    que.pop();
    for(int edge_i = 0; edge_i < edges[s.point].size(); edge_i++){
      int next = edges[s.point][edge_i].first;
      int cost = edges[s.point][edge_i].second;
      vector<int> next_cost = s.cost_log;
      next_cost.push_back(cost);

      if(next == num_of_nodes - 1){
	sort(next_cost.begin(),next_cost.end(),greater<int>());
	int sum = 0;
	for(int i = 0; i < next_cost.size(); i++){
	  sum += next_cost[i];
	}
	int ans = 0;
	for(int i = 0; i < next_cost.size(); i++){
	  sum -= next_cost[i];
	  ans++;
	  if(sum <= target_cost){
	    res = min(ans,res);
	    break;
	  }
	}
	continue;
      }
      que.push(State(next,next_cost));
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
    memset(visited,false,sizeof(visited));
    vector<P> edges[101];
    for(int edge_i = 0; edge_i < num_of_edges; edge_i++){
      int src,dst,cost;
      scanf("%d %d %d",&src,&dst,&cost);
      src--; dst--;
      edges[src].push_back(P(dst,cost));
    }
    vector<int> current_cost;
    visited[0] = true;
    printf("%d\n",dfs(edges,num_of_nodes,target_cost,0,current_cost));
  }
}
