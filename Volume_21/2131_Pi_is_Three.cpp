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
  
static const double EPS = 1e-10;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

bool equal(double lhs, double rhs){
  return (lhs - EPS <= rhs && rhs - EPS <= lhs);
}

int main(){
  double R;
  while(~scanf("%lf",&R)){
    if(equal(R,0.0)) break;
    for(int denominator = 1; denominator <= 10000000; denominator++){
      int upper = 10000000;
      int lower = 0;
      for(int round = 0; round < 30; round++){
	int mid = lower + (upper - lower)/2;
	if((double)mid/(double)denominator >= M_PI - R){
	  upper = mid;
	}
	else{
	  lower = mid;
	}
      }

      int numerator = upper;
      if((double)numerator/(double)denominator > M_PI + R) continue;

      printf("%d/%d\n",numerator,denominator);
      break;
    }
  }
}
