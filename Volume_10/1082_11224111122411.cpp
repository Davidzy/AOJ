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

ll dp[6][100001]; //dp[pos][buffered char][hidden or not]

const static ll MOD = 100000007;

int main(){
  string text;

  memset(dp,0,sizeof(dp));
  dp[3][0] = 0;
  dp[3][1] = 1;
  dp[3][2] = 2;

  dp[5][0] = 0;
  dp[5][1] = 1;
  dp[5][2] = 2;
  dp[5][3] = 4;
  dp[5][4] = 8;

  for(int text_i = 0; text_i < 100000; text_i++){
    dp[3][text_i + 3] += 1;
    for(int offset = 0; offset <= 2; offset++){
      dp[3][text_i + 3] += dp[3][text_i + offset];
      dp[3][text_i + 3] %= MOD;
    }

    dp[5][text_i + 5] += 1;
    for(int offset = 0; offset <= 4; offset++){
      dp[5][text_i + 5] += dp[5][text_i + offset];
      dp[5][text_i + 5] %= MOD;
    }
  }

  while(cin >> text){
    if(text == "#") break;

    ll res = 1;
    int length = 1;
    for(int text_i = 0; text_i + 1 < text.size(); text_i++){
      if(text[text_i] == text[text_i + 1]){
	length++;
      }
      else{
	if(text[text_i] == '8' || text[text_i] == '0'){
	  res = (res * dp[3][length]) % MOD;
	  res %= MOD;
	}
	else{
	  res = (res * dp[5][length]) % MOD;
	  res %= MOD;
	}
	length = 1;
      }
    }

    if(length > 0){
      if(text[text.size() - 1] == '8' || text[text.size() - 1] == '0'){
	res = (res * dp[3][length]) % MOD;
	res %= MOD;
      }
      else{
	res = (res * dp[5][length]) % MOD;
	res %= MOD;
      }
    }
    printf("%lld\n",res % MOD);
  }
}
