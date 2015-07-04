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

ll digit2bar[14][10] = 
  {
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6},
    {6,2,5,5,4,5,6,3,7,6}
  };


enum Type {
  YEAR = 4,
  MONTH = 2,
  DAY = 2,
  HOUR = 2,
  MINUTE = 2,
  SECOND = 2
};

bool is_leap_year(int year){
  if(year % 400 == 0) return true;
  if(year % 400 != 0 && year % 100 == 0) return false;
  if(year % 100 !=0 && year % 4 == 0) return true;
  if(year % 4 != 0) return false;
  return false;
}

ll digits2bar(int digits,Type type,int offset){
  ll res = 0;
  for(int i = 0; i < type; i++){
    res += digit2bar[offset][digits % 10];
    digits /= 10;
    offset--;
  }
  return res;
}

int main(){
  vector<int> bar_pos2digit[8];
  bar_pos2digit[0].push_back(0);
  bar_pos2digit[0].push_back(2);
  bar_pos2digit[0].push_back(3);  
  bar_pos2digit[0].push_back(5);  
  bar_pos2digit[0].push_back(6);
  bar_pos2digit[0].push_back(7);
  bar_pos2digit[0].push_back(8);
  bar_pos2digit[0].push_back(9);

  bar_pos2digit[1].push_back(0);
  bar_pos2digit[1].push_back(4);
  bar_pos2digit[1].push_back(5);
  bar_pos2digit[1].push_back(6);
  bar_pos2digit[1].push_back(8);
  bar_pos2digit[1].push_back(9);

  bar_pos2digit[2].push_back(0);
  bar_pos2digit[2].push_back(1);
  bar_pos2digit[2].push_back(2);
  bar_pos2digit[2].push_back(3);
  bar_pos2digit[2].push_back(4);
  bar_pos2digit[2].push_back(7);
  bar_pos2digit[2].push_back(8);
  bar_pos2digit[2].push_back(9);

  bar_pos2digit[3].push_back(2);
  bar_pos2digit[3].push_back(3);
  bar_pos2digit[3].push_back(4);
  bar_pos2digit[3].push_back(5);
  bar_pos2digit[3].push_back(6);
  bar_pos2digit[3].push_back(8);
  bar_pos2digit[3].push_back(9);

  bar_pos2digit[4].push_back(0);
  bar_pos2digit[4].push_back(2);
  bar_pos2digit[4].push_back(6);
  bar_pos2digit[4].push_back(8);

  bar_pos2digit[5].push_back(0);
  bar_pos2digit[5].push_back(3);
  bar_pos2digit[5].push_back(4);
  bar_pos2digit[5].push_back(5);
  bar_pos2digit[5].push_back(6);
  bar_pos2digit[5].push_back(7);
  bar_pos2digit[5].push_back(8);
  bar_pos2digit[5].push_back(9);

  bar_pos2digit[6].push_back(0);
  bar_pos2digit[6].push_back(2);
  bar_pos2digit[6].push_back(3);
  bar_pos2digit[6].push_back(5);
  bar_pos2digit[6].push_back(6);
  bar_pos2digit[6].push_back(8);
  bar_pos2digit[6].push_back(9);

  int num_of_lightning_bars;
  while(~scanf("%d",&num_of_lightning_bars)){
    int num_of_broken_bars;
    scanf("%d",&num_of_broken_bars);
    for(int i = 0; i < num_of_broken_bars; i++){
      int digit_pos;
      int bar_pos;
      scanf("%d %d",&digit_pos,&bar_pos);
      for(int j = 0; j < bar_pos2digit[bar_pos].size(); j++){
	int digit = bar_pos2digit[bar_pos][j];
	digit2bar[digit_pos][digit]--;
      }
    }
    
    ll dp[7][110] = {};    
    for(int year = 0; year <= 9999; year++){
      int days[] = {0,31,28 + (is_leap_year(year) ? 1 : 0),31,30,31,30,31,31,30,31,30,31};
      for(int month = 1; month <= 12; month++){
	for(int day = 1; day <= days[month]; day++){
	  dp[0][digits2bar(year,YEAR,3) + digits2bar(month,MONTH,5) +digits2bar(day,DAY,7)]++;
	}
      }
    }
    
    for(int hour = 0; hour < 24; hour++){
      for(int prev = 0; prev <= 100; prev++){
	dp[1][prev + digits2bar(hour,HOUR,9)] += dp[0][prev];
      }
    }

    for(int minute = 0; minute < 60; minute++){
      for(int prev = 0; prev <= 100; prev++){
	dp[2][prev + digits2bar(minute,MINUTE,11)] += dp[1][prev];
      }
    }
    for(int second = 0; second < 60; second++){
      for(int prev = 0; prev <= 100; prev++){
	dp[3][prev + digits2bar(second,SECOND,13)] += dp[2][prev];
      }
    }
    printf("%lld\n",dp[3][num_of_lightning_bars]);
  }
}
