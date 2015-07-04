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

class BrokenBar {
public:
  int digit_pos;
  int bar_pos;
  BrokenBar(int digit_pos, int bar_pos)
    : digit_pos(digit_pos), bar_pos(bar_pos) {}
};

bool is_leap_year(int year){
  if(year % 400 == 0) return true;
  if(year % 400 != 0 && year % 100 == 0) return false;
  if(year % 100 !=0 && year % 4 == 0) return true;
  if(year % 4 != 0) return false;
  return false;
}

static const int digit2bar[] = {6,2,5,5,4,5,6,4,7,6};

enum Type {
  YEAR = 4,
  MONTH = 2,
  DAY = 2,
  HOUR = 2,
  MINUTE = 2,
  SECOND = 2
};

ll digits2bar(int digits,Type type){
  ll res = 0;
  for(int i = 0; i < type; i++){
    res += digit2bar[digits % 10];
    digits /= 10;
  }
  return res;
}

int main(){
  int num_of_lightning_bars;
  while(~scanf("%d",&num_of_lightning_bars)){
    int num_of_broken_bars;
    scanf("%d",&num_of_broken_bars);
    vector<BrokenBar> broken_bars;
    for(int i = 0; i < num_of_broken_bars; i++){
      int digit_pos;
      int bar_pos;
      scanf("%d %d",&digit_pos,&bar_pos);
      broken_bars.push_back(BrokenBar(digit_pos,bar_pos));
    }
    
    ll dp[7][110] = {};    
    for(int year = 0; year <= 9999; year++){
      int days[] = {0,31,28 + is_leap_year(year) ? 1 : 0,31,30,31,30,31,31,30,31,30,31};
      for(int month = 1; month <= 12; month++){
	for(int day = 1; day <= days[month]; day++){
	  dp[0][digits2bar(month,MONTH) + digits2bar(year,YEAR) + digits2bar(day,DAY)]++;
	}
      }
    }
    
    for(int hour = 0; hour < 24; hour++){
      for(int prev = 0; prev <= 100; prev++){
	dp[1][prev + digits2bar(hour,HOUR)] += dp[0][prev];
      }
    }

    for(int minute = 0; minute < 60; minute++){
      for(int prev = 0; prev <= 100; prev++){
	dp[2][prev + digits2bar(minute,MINUTE)] += dp[1][prev];
      }
    }
    for(int second = 0; second < 60; second++){
      for(int prev = 0; prev <= 100; prev++){
	dp[3][prev + digits2bar(second,SECOND)] += dp[2][prev];
      }
    }
    printf("%lld\n",dp[3][num_of_lightning_bars]);
  }
}
