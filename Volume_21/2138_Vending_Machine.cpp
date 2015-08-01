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

int dp[1<<20];

int main(){
  int num_of_coins;
  int change;
  while(~scanf("%d %d",&num_of_coins,&change)){
    if(num_of_coins == 0 && change == 0) break;
    memset(dp,0x3f,sizeof(dp));

    vector<int> coins;
    for(int coin_i = 0; coin_i < num_of_coins; coin_i++){
      int price;
      scanf("%d",&price);
      coins.push_back(price);
    }

    int sum[1<<12] = {};
    for(int S = 0; S < (1<<num_of_coins); S++){
      for(int coin_i = 0; coin_i < num_of_coins; coin_i++){
	if(!(S & (1<<coin_i))) continue;
	sum[S] += coins[coin_i];
      }
    }

    dp[0] = 0;
    for(int S = 0; S < (1<<num_of_coins); S++){
      for(int prev = 0; prev + sum[S] <= change; prev++){
	int next = prev + sum[S];
	dp[next] = min(dp[prev] + 1,dp[next]);
      }
    }

    printf("%d\n",dp[change]);
  }
}
