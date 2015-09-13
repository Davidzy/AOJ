#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
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
 
using namespace std;
 
typedef long long ll;
typedef pair <int,vector<int> > P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

class UnionFindTree {
  int* _par;
  int* _rank;
public:
  UnionFindTree(int N){
    _par = new int[N];
    _rank = new int[N];
    for(int i = 0; i < N; i++){
      _par[i] = i;
      _rank[i] = 0;
    }
  }

  ~UnionFindTree(){
    delete[] _par;
    delete[] _rank;
  }

  int find(int u){
    if(_par[u] == u) return u;
    return find(_par[u]);
  }

  bool unite(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    
    if(_rank[u] < _rank[v]){
      _par[u] = v;
    }
    else{
      _par[v] = u;
      if(_rank[u] == _rank[v]) _rank[u]++;
    }
    return true;
  }
};

class Edge {
public:
  int from;
  int to;
  int cost;
  Edge(int from,int to,int cost) 
    : from(from), to(to), cost(cost) {}
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
  bool operator>(const Edge& e) const {
    return cost > e.cost;
  }
};

int main(){
  int num_of_springs;
  int num_of_districts;
  while(~scanf("%d %d",&num_of_springs,&num_of_districts)){
    if(num_of_springs == 0 && num_of_districts == 0) break;
    priority_queue<Edge,vector<Edge>, greater<Edge> > que;

    int spring_district_distance[51][51];
    for(int spring_i = 0; spring_i < num_of_springs; spring_i++){
      for(int district_i = 0; district_i < num_of_districts; district_i++){
	scanf("%d",&spring_district_distance[spring_i][district_i]);
	if(spring_district_distance[spring_i][district_i] == 0) continue;
	que.push(Edge(0,num_of_springs + district_i,spring_district_distance[spring_i][district_i]));
      }
    }

    int district_distance[51][51];
    for(int i = 0; i < num_of_districts - 1; i++){
      for(int j = 0; j < num_of_districts - i - 1; j++){
	scanf("%d",&district_distance[i][i+j+1]);
	district_distance[j+i+1][i] = district_distance[i][i+j+1];
	if(district_distance[j+i+1][i] == 0) continue;
	que.push(Edge(num_of_springs + i,num_of_springs + i + j + 1,district_distance[i][i+j+1]));
      }
    }

    int res = 0;
    UnionFindTree uft(101);
    while(!que.empty()){
      Edge e = que.top();
      que.pop();
      if(e.cost == 0) continue;
      if(uft.unite(e.from,e.to)){
	res += e.cost;
      }
    }

    printf("%d\n",res);
  }
}
