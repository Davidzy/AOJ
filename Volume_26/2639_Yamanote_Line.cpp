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
  int stand_duration;
  int sleep_duration;
  int cost;
  while(~scanf("%d %d %d",
	       &stand_duration,
	       &sleep_duration,
	       &cost)){
    int current = 0;
    int res = -1;

    int count = 0;
    for(int round = 0; round < 100000 + cost; round++){
      int prev = current;

      current += stand_duration;

      for(int time = prev; time <= current; time++){
	if(time == cost){
	  res = count * 60 + cost;
	  goto found;
	}
      }

      current += sleep_duration;
      if(current >= 60){
	count++;
	current -= 60;
      }
    }

  found:;
    printf("%d\n",res);
  }
}
