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
  int cost;
  Edge(int to, int cost) {
    this->to = to;
    this->cost = cost;
  }
};

int main(){
  int num_of_vertex;
  while(~scanf("%d",&num_of_vertex)){
    int cicadas[1001] = {};
    for(int vertex_i = 1; vertex_i < num_of_vertex; vertex_i++){
      int num_of_cicadas;
      scanf("%d",&num_of_cicadas);
      cicadas[vertex_i] = num_of_cicadas;
    }

    vector<Edge> edges[1001];
    for(int vertex_i = 0; vertex_i < num_of_vertex - 1; vertex_i++){
      int from,to,cost;
      cin >> from >> to >> cost;
      edges[from].push_back(Edge(to,cost));
    }

    int res = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
      int pos = que.front();
      que.pop();
      for(int next_i = 0; next_i < edges[pos].size(); next_i++){
	int to = edges[pos][next_i].to;
	int cost = edges[pos][next_i].cost;
	if(cicadas[to] > 0){
	  res += cost;
	}
	else {
	  que.push(to);
	}
      }
    }

    printf("%d\n",res);
  }
}
