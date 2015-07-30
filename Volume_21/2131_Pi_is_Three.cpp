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
  
static const double EPS = 1e-12;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};


class SternBrocotTree {
public:
  SternBrocotTree(double p)
    : max_depth(0),
      ans_left_numerator(0),
      ans_right_numerator(0),
      ans_left_denominator(0),
      ans_right_denominator(0){
    this->p = p;
  }

  void dfs(int left_numerator,int left_denominator,
	   int right_numerator,int right_denominator,int depth){
    int next_numerator = left_numerator + right_numerator;
    int next_denominator = left_denominator + right_denominator;
    if(depth > 30) return;

    if(contains(left_numerator,left_denominator,next_numerator,next_denominator)){
      dfs(left_numerator,left_denominator,next_numerator,next_denominator,depth+1);
    }

    if(max_depth < depth){
      max_depth = depth;
      ans_right_numerator = right_numerator;
      ans_right_denominator = right_denominator;
      ans_left_numerator = left_numerator;
      ans_left_denominator = left_denominator;
    }

    if(contains(next_numerator,next_denominator,right_numerator,right_denominator)){
      dfs(next_numerator,next_denominator,right_numerator,right_denominator,depth+1);
    }
  }
  void disp(){
    printf("%d/%d %d/%d\n",
	   ans_right_numerator,ans_right_denominator,
	   ans_left_numerator,ans_left_denominator);
  }

  void ans(int base){
    printf("%lld/%lld\n",(ll)ans_right_numerator + (ll)ans_right_denominator * (ll)base,(ll)ans_right_denominator);
  }
		     
private:
  double p;
  int max_depth;
  int ans_left_numerator;
  int ans_left_denominator;
  int ans_right_numerator;
  int ans_right_denominator;
  
  bool contains(int left_numerator,int left_denominator,
		int right_numerator,int right_denominator){
    if((double)left_numerator < (double)left_denominator * p
       && p * (double)right_denominator - EPS <= (double)right_numerator){
      return true;
    }
    return false;
  }
};

bool equal(double lhs, double rhs){
  return (lhs - EPS <= rhs && rhs - EPS <= lhs);
}

int main(){
  double R;
  while(cin >> R){
    if(equal(R,0.0)) break;
    double original = M_PI - R;
    int base = (int)(original + EPS);
    double target = original - (double)base;
    SternBrocotTree sbt(target);
    sbt.dfs(0,1,1,1,0);
    sbt.ans(base);
  }
}
