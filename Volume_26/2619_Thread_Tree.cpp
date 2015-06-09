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

bool visited[1001];

void dfs(int current,
	 int depth,
	 const vector<int> edges[1001],
	 const vector<string>& messages){
  for(int i = 0; i < depth; i++){
    cout << ".";
  }
  cout << messages[current] << endl;
  for(int i = 0; i < edges[current].size(); i++){
    int next = edges[current][i];
    if(visited[next]) continue;
    visited[next] = true;
    dfs(next,depth+1,edges,messages);
  }
}

int main(){
  int num_of_posts;
  while(~scanf("%d",&num_of_posts)){
    memset(visited,false,sizeof(visited));

    vector<int> edges[1001];
    vector<string> messages;
    for(int post_i = 0; post_i < num_of_posts; post_i++){
      string message;
      int reply_to;
      cin >> reply_to >> message;
      messages.push_back(message);

      if(reply_to - 1 >= 0){
	edges[reply_to - 1].push_back(post_i);
      }
    }
    dfs(0,0,edges,messages);
  }
}
