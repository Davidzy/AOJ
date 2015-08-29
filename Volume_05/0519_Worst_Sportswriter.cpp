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

void compute_path(int team, int depth, vector<int> edges[5001], int num_of_teams, vector<int>& path){
  if(edges[team].size() == 0 && depth == num_of_teams){
    ans_path = path;
    return;
  }

  for(int i = 0; i < edges[team].size(); i++){
    int next = edges[team][i];
    path.push_back(next);
    compute_path(next,depth + 1,edges,num_of_teams,path);
    path.pop_back();
  }
}

bool visited[5002][5002];
int win[5002];

int main(){
  int num_of_teams;
  int num_of_results;
  while(~scanf("%d %d",&num_of_teams,&num_of_results)){
    vector<int> edges[5002];
    memset(visited,false,sizeof(visited));
    memset(win,0,sizeof(win));
    for(int i = 0; i < num_of_results; i++){
      int from,to;
      scanf("%d %d",&from,&to);
      edges[from].push_back(to);
      visited[from][to] = true;
      visited[to][from] = true;
      win[from]++;
    }

    int count = 0;
    for(int team = 1; team <= num_of_teams; team++){
      count += count_candidate(team,1,edges,num_of_teams);
    }
    for(int team_i = 1; team_i <= num_of_teams; team_i++){
      for(int team_j = team_i + 1; team_j <= num_of_teams; team_j++){
    	if(visited[team_i][team_j]) continue;
	if(win[team_i] != win[team_j]) continue;

	win[team_j]++;
	edges[team_i].push_back(team_j);
      }
    }
    
    int champ_team = 1;
    int max_win = 0;
    for(int team = 1; team <= num_of_teams; team++){
      if(win[team] > max_win){
	max_win = win[team];
	champ_team = team;
      }
    }

    vector<int> path;
    path.push_back(champ_team);
    compute_path(champ_team,1,edges,num_of_teams,path);
    for(int i = 0; i < ans_path.size(); i++){
      printf("%d\n",ans_path[i]);
    }
    printf("%d\n",(count == 0 || count >= 2) ? 1 : 0);
  }
}
