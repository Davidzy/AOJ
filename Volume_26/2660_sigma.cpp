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

P calc(int lhs,int rhs){
  int sum = lhs + rhs;
  int carry = 0;
  int cost = 0;
  for(int i = 0; i < 9; i++){
    cost += (lhs % 10) * (rhs % 10) + carry;
    carry = (lhs % 10 + rhs % 10 + carry >= 10 ? 1 : 0);
    lhs /= 10;
    rhs /= 10;
  }
  return P(sum,cost);
}

int main(){
  int N;
  while(~scanf("%d",&N)){
    vector<int> numbers;
    for(int i = 0; i < N; i++){
      int number;
      scanf("%d",&number);
      numbers.push_back(number);
    }
    P dp[301][301];
    for(int i = 0; i < numbers.size(); i++) {
      dp[i][i].first = numbers[i];
      dp[i][i].second = 0;
    }

    for(int d = 1; d < numbers.size(); d++){
      for(int i = 0; i < numbers.size() - d; i++){
	int j = i + d;
	dp[i][j].second = INF;
	for(int k = i; k < j; k++){
	  P tmp = calc(dp[i][k].first,dp[k+1][j].first);
	  dp[i][j].first = tmp.first;
	  dp[i][j].second = min(dp[i][j].second,
				tmp.second + dp[i][k].second + dp[k+1][j].second);
	}
      }
    }

    printf("%d\n",dp[0][numbers.size()-1].second);
  }
}
