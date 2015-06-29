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
  int num_of_chopsticks;
  int num_of_divisors;
  int total_days;
  while(~scanf("%d %d %d",
	       &num_of_chopsticks,
	       &num_of_divisors,
	       &total_days)){
    int divisors[11];
    for(int div_i = 0; div_i < num_of_divisors; div_i++){
      scanf("%d",&divisors[div_i]);
    }
    int record[101][11];
    for(int day = 0; day < total_days; day++){
      for(int div_i = 0; div_i < num_of_divisors; div_i++){
	scanf("%d",&record[day][div_i]);
      }
    }
  }
}
