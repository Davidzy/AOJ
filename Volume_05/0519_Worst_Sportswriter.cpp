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

vector<int> ans_path;
int depth[5002];

int count_candidate(int team, int depth, vector<int> edges[5001], int num_of_teams){
  if(edges[team].size() == 0){
    return (depth == num_of_teams);
  }

  int res = 0;
  for(int i = 0; i < edges[team].size(); i++){
    int next = edges[team][i];
    res += count_candidate(next,depth + 1,edges,num_of_teams);
  }
  return res;
}

int main(){
  int num_of_teams;
  int num_of_results;
  while(~scanf("%d %d",&num_of_teams,&num_of_results)){
    vector<int> edges[5002];
    memset(depth,0,sizeof(depth));
    for(int i = 0; i < num_of_results; i++){
      int from,to;
      scanf("%d %d",&from,&to);
      edges[from].push_back(to);
      depth[to]++;
    }

    int count = 0;
    for(int team = 1; team <= num_of_teams; team++){
      count += count_candidate(team,1,edges,num_of_teams);
    }

    queue<int> que;
    for(int team = 1; team <= num_of_teams; team++){
      if(depth[team] == 0){
	que.push(team);
      }
    }
    
    while(!que.empty()){
      int team = que.front();
      que.pop();
      printf("%d\n",team);
      for(int i = 0; i < edges[team].size(); i++){
	int next = edges[team][i];
	depth[next]--;
	if(depth[next] == 0){
	  que.push(next);
	}
      }
    }

    printf("%d\n",(count == 0 || count >= 2) ? 1 : 0);
  }
}
