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

class Edge {
public:
  int to;
  int weight;
  Edge(int to, int weight)
    : to(to), weight(weight) {}
};

class State {
public:
  int pos;
  int cost;
  int visited;
  State(int pos, int cost)
    : pos(pos), cost(cost), visited(0) {}
  State(int pos, int cost, int visited)
    : pos(pos), cost(cost), visited(visited) {}
  bool operator<(const State& s) const {
    return cost < s.cost;
  }
  bool operator>(const State& s) const {
    return cost > s.cost;
  }
};

int dp[1001][1<<12];

int main(){
  int total_nodes;
  int total_edges;
  int total_lost_posts;
  int starting_point;
  while(~scanf("%d %d %d %d",
	       &total_nodes,
	       &total_edges,
	       &total_lost_posts,
	       &starting_point)){
    starting_point--;
    memset(dp,0x3f,sizeof(dp));
    vector<Edge> edges[1001];
    for(int edge_i = 0; edge_i < total_edges; edge_i++){
      int from,to,weight;
      scanf("%d %d %d",&from,&to,&weight);
      from--; to--;
      edges[from].push_back(Edge(to,weight));
      edges[to].push_back(Edge(from,weight));
    }

    bool is_letter[1001] = {};
    bool is_post[1001] = {};
    int letter2idx[1001] = {};
    int post2idx[1001] = {};
    int post2letter[1001] = {};
    for(int post_i = 0; post_i < total_lost_posts; post_i++){
      int from,to;
      scanf("%d %d",&from,&to);
      from--; to--;
      is_letter[from] = true;
      is_post[to] = true;
      letter2idx[from] = post_i;
      post2idx[to] = total_lost_posts +  post_i;
      post2letter[to] = from;
    }

    priority_queue<State,vector<State>,greater<State> > que;
    que.push(State(starting_point,0));
    dp[starting_point][0] = 0;
    while(!que.empty()){
      State s = que.top();
      que.pop();
      for(int i = 0; i < edges[s.pos].size(); i++){
	int to = edges[s.pos][i].to;
	int weight = edges[s.pos][i].weight;
	int next_visited = s.visited;
	if(is_letter[to]){
	  next_visited |= (1<<letter2idx[to]);
	}
	if(is_post[to] && (s.visited & (1<<letter2idx[post2letter[to]]))){
	  next_visited |= (1<<post2idx[to]);
	}
	if(dp[to][next_visited] <= s.cost + weight) continue;
	dp[to][next_visited] = s.cost + weight;
	que.push(State(to,s.cost + weight,next_visited));
      }
    }

    int res = INF;
    for(int node_i = 0; node_i < total_nodes; node_i++){
      res = min(res,dp[node_i][(1<<(total_lost_posts*2)) - 1]);
    }
    
    if(res == INF){
      printf("Cannot deliver\n");
    }
    else{
      printf("%d\n",res);
    }
  }
}
