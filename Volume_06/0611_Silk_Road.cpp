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

int dp[1001][1001];

int main(){
  int last_city;
  int day_limit;
  while(~scanf("%d %d",&last_city,&day_limit)){
    
    int distance[1001];
    for(int city_i = 0; city_i < last_city; city_i++){
      scanf("%d",&distance[city_i]);
    }

    int badness[1001];
    for(int day = 0; day < day_limit; day++){
      scanf("%d",&badness[day]);
    }

    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int day = 0; day < day_limit; day++){
      for(int city_i = last_city - 1; city_i >= 0; city_i--){
	dp[day + 1][city_i + 1]
	  = min(dp[day][city_i] + badness[day] * distance[city_i],
		dp[day + 1][city_i + 1]);
	dp[day + 1][city_i]
	  = min(dp[day][city_i],
		dp[day + 1][city_i]);

      }
    }

    int res = INF;
    for(int day = 0; day <= day_limit; day++){
      res = min(res,dp[day][last_city]);
    }
    printf("%d\n",res);
  }
}
