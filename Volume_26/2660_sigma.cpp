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
    cost += lhs % 10 + rhs % 10 + carry;
    carry = (lhs % 10 + rhs % 10 + carry > 10 ? 1 : 0);
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
  }
}
