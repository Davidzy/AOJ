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

int main(){
  int num_of_coins;
  ll change;
  while(~scanf("%d %lld",&num_of_coins,&change)){
    if(num_of_coins == 0 && change == 0) break;

    vector<ll> coins;
    for(int coin_i = 0; coin_i < num_of_coins; coin_i++){
      ll price;
      scanf("%lld",&price);
      coins.push_back(price);
    }
    sort(coins.begin(),coins.end(),greater<ll>());
    ll min_coins = numeric_limits<ll>::max();
    for(int S = 0; S < (1<<coins.size()); S++){
      ll upper = 1000000;
      ll lower = 0;
      ll last_sum = 0;
      for(int round = 0; round < 50; round++){
	ll mid = lower + (upper - lower) / 2LL;
	ll sum = 0;
	for(int coin_i = 0; coin_i < num_of_coins; coin_i++){
	  if(!(S & (1<<coin_i))) continue;
	  sum += coins[coin_i] * mid;
	}

	if(sum >= change){
	  upper = mid;
	  last_sum = sum;
	}
	else {
	  lower = mid;
	}
      }
      
      for(int coin_i = 0; coin_i < num_of_coins; coin_i++){
	  if(!(S & (1<<coin_i))) continue;
	  ll cut_num = 0;
	  while(last_sum - (coins[coin_i] * (cut_num+1)) >= change
		&& (cut_num + 1) <= upper){
	    cut_num++;
	  }
	  last_sum -= coins[coin_i] * cut_num;
      }

      if(last_sum == change){
	min_coins = min(upper,min_coins);
      }
    }

    printf("%lld\n",min_coins);
  }
}
