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
  int money;
  while(~scanf("%d %d %d",
	       &num_of_stocks,
	       &period,
	       &money)){
    int price[11][11];
    for(int day = 0; day < period; day++){
      for(int stock_i = 0; stock_i < num_of_stocks; stock_i++){
	scanf("%d",&price[day][stock_i]);
      }
    }
  }
}
