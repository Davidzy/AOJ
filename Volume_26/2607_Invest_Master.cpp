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

int dp[11][100010];

int main(){
  int num_of_stocks;
  int period;
  int init_money;
  while(~scanf("%d %d %d",
	       &num_of_stocks,
	       &period,
	       &init_money)){
    int price[11][11];

    for(int day = 0; day < period; day++){
      for(int stock_i = 0; stock_i < num_of_stocks; stock_i++){
	scanf("%d",&price[day][stock_i]);
      }
    }
    memset(dp,0,sizeof(dp));
    for(int day = 0; day < period-1; day++){
      for(int start_money = 0; start_money <= 100000; start_money++){
	dp[day][start_money] = start_money;
      }

      for(int stock_i = 0; stock_i < num_of_stocks; stock_i++){
	for(int start_money = price[day][stock_i]; start_money <= 100000; start_money++){
	  dp[day][start_money] 
	    = max(dp[day][start_money],
		  dp[day][start_money - price[day][stock_i]] + price[day+1][stock_i]);
	}
      }
    }

    int res = init_money;
    for(int day = 0; day < period - 1; day++){
      res = dp[day][res];
    }

    printf("%d\n",res);
  }
}
