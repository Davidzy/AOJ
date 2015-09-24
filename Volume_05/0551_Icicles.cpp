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
 
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};
 
static const double EPS = 1e-8;

int dp[1000001];

int dfs(int icicles[100000],int num_of_icicles, int max_length,int icicle_i){
  if(dp[icicle_i] != -1) return dp[icicle_i];
  
  int neighbor_cost = 0;
  if(icicle_i < num_of_icicles - 1 && icicles[icicle_i + 1] > icicles[icicle_i]){
    neighbor_cost = max(dfs(icicles,num_of_icicles,max_length,icicle_i + 1),neighbor_cost);
  }
  if(icicle_i > 0 && icicles[icicle_i - 1] > icicles[icicle_i]){
    neighbor_cost = max(dfs(icicles,num_of_icicles,max_length,icicle_i - 1),neighbor_cost);
  }
  return (dp[icicle_i] = max(neighbor_cost + (max_length - icicles[icicle_i]),dp[icicle_i]));
}

int main(){
  int num_of_icicles;
  int max_length;
  while(~scanf("%d %d",&num_of_icicles,&max_length)){
    memset(dp,-1,sizeof(dp));
    int icicles[100000];
    for(int i = 0; i < num_of_icicles; i++){
      scanf("%d",&icicles[i]);
    }

    int res = 0;
    for(int i = 0; i < num_of_icicles; i++){
      res = max(res,dfs(icicles,num_of_icicles,max_length,i));
    }
    printf("%d\n",res);
  }
}
