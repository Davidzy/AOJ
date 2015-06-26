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

int main(){
  int num_of_stocks;
  int period;
  int init_money;
  while(~scanf("%d %d %d",
	       &num_of_stocks,
	       &period,
	       &init_money)){
    int price[11][11];
    map<vector<int>,int> dp[11][11];

    for(int day = 0; day < period; day++){
      for(int stock_i = 0; stock_i < num_of_stocks; stock_i++){
	scanf("%d",&price[day][stock_i]);
      }
    }
    vector<int> init_state(10);
    dp[0][0][init_state] = init_money;
    for(int day = 0; day < period; day++){
      for(int stock_i = 0; stock_i < num_of_stocks; stock_i++){
	for(map<vector<int>,int>::iterator it = dp[day][stock_i].begin(); it != dp[day][stock_i].end(); it++){
	  vector<int> prev_state = it->first;
	  int prev_money = it->second;
	  dp[day][stock_i+1][prev_state] = max(prev_money,dp[day][stock_i+1][prev_state]);
	  
	  if(prev_state[stock_i] > 0){
	    vector<int> next_state = prev_state;
	    next_state[stock_i] = 0;
	    dp[day][stock_i+1][next_state] = max(dp[day][stock_i+1][next_state],
						 prev_money
						 + price[day][stock_i] * prev_state[stock_i]);
	  }
	  for(int buy = 1; buy <= 1000000; buy++){
	    if(prev_money - buy * price[day][stock_i] < 0) break;
	    vector<int> next_state = prev_state;
	    next_state[stock_i] += buy;
	    dp[day][stock_i+1][next_state] = max(dp[day][stock_i+1][next_state],
						 prev_money
						 - price[day][stock_i] * buy);
	  }
	}
      }
      dp[day+1][0] = dp[day][num_of_stocks];
    }

    int res = 0;
    for(map<vector<int>,int>::iterator it = dp[period][0].begin(); it != dp[period][0].end(); it++){
      res = max(it->second,res);
    }
    printf("%d\n",res);
  }
}
