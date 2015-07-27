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

int dp[100001][51][2]; //dp[pos][buffered char][hidden or not]

int compute_attribute(int hiragana){
  if(0 <= hiragana && hiragana <= 4) return 1; //あ～お
  if(5 <= hiragana && hiragana <= 9) return 2; //か～こ
  if(10 <= hiragana && hiragana <= 14) return 3; //さ～そ
  if(15 <= hiragana && hiragana <= 19) return 4; //た～と
  if(20 <= hiragana && hiragana <= 24) return 5; //な～の
  if(25 <= hiragana && hiragana <= 29) return 6; //は～ほ
  if(30 <= hiragana && hiragana <= 34) return 7; //ま～も
  if(35 <= hiragana && hiragana <= 37) return 8; //や～よ
  if(38 <= hiragana && hiragana <= 42) return 9; //ら～ろ
  if(43 <= hiragana && hiragana <= 45) return 0; //わ～ん
  return -1;
}

int next_hiragana(int hiragana){
  if(0 <= hiragana && hiragana <= 4) return (hiragana - 0 + 1) % 5 + 0; //あ～お
  if(5 <= hiragana && hiragana <= 9) return (hiragana - 5 + 1) % 5 + 5; //か～こ
  if(10 <= hiragana && hiragana <= 14) return (hiragana - 10 + 1) % 5 + 10; //さ～そ
  if(15 <= hiragana && hiragana <= 19) return (hiragana - 15 + 1) % 5 + 15; //た～と
  if(20 <= hiragana && hiragana <= 24) return (hiragana - 20 + 1) % 5 + 20; //な～の
  if(25 <= hiragana && hiragana <= 29) return (hiragana - 25 + 1) % 5 + 25; //は～ほ
  if(30 <= hiragana && hiragana <= 34) return (hiragana - 30 + 1) % 5 + 30; //ま～も
  if(35 <= hiragana && hiragana <= 37) return (hiragana - 35 + 1) % 3 + 35; //や～よ
  if(38 <= hiragana && hiragana <= 42) return (hiragana - 38 + 1) % 5 + 38; //ら～ろ
  if(43 <= hiragana && hiragana <= 45) return (hiragana - 43 + 1) % 3 + 43; //わ～ん
  return -1;
}

int head_hiragana(int attribute){
  if(attribute == 1) return 0;
  if(attribute == 2) return 5;
  if(attribute == 3) return 10;
  if(attribute == 4) return 15;
  if(attribute == 5) return 20;
  if(attribute == 6) return 25;
  if(attribute == 7) return 30;
  if(attribute == 8) return 35;
  if(attribute == 9) return 38;
  if(attribute == 0) return 43;
  return -1;
}

const static int MOD = 100000007;

int main(){
  string text;
  while(cin >> text){
    if(text == "#") break;
    memset(dp,0,sizeof(dp));
    dp[0][head_hiragana(text[0] - '0')][1] = 1;
    dp[0][head_hiragana(text[0] - '0')][0] = 1;

    for(int text_i = 1; text_i < text.size(); text_i++){
      int current_attribute = text[text_i] - '0';
      for(int prev_hiragana = 0; prev_hiragana <= 40; prev_hiragana++){
	int prev_attribute = compute_attribute(prev_hiragana);
	if(current_attribute == prev_attribute){
	  //h:あ->h:い
	  dp[text_i + 1][next_hiragana(prev_hiragana)][0]
	    += dp[text_i][prev_hiragana][0] % MOD;
	  //h:え->o:あ
	  dp[text_i + 1][head_hiragana(text[text_i] - '0')][1]
	    += dp[text_i][prev_hiragana][0] % MOD;
	  //o:え->o:あ
	  dp[text_i + 1][head_hiragana(text[text_i] - '0')][1]
	    += dp[text_i][prev_hiragana][1] % MOD;
	  //o:え->h:あ
	  dp[text_i + 1][head_hiragana(text[text_i] - '0')][0]
	    += dp[text_i][prev_hiragana][1] % MOD;
	}
	else {
	  //o:あ->o:は
	  dp[text_i + 1][head_hiragana(text[text_i] - '0')][1]
	    += dp[text_i][prev_hiragana][1] % MOD;
	  //h:あ->o:は
	  dp[text_i + 1][head_hiragana(text[text_i] - '0')][1]
	    += dp[text_i][prev_hiragana][0] % MOD;
	}
      }
    }

    int res = 0;
    if(text.size() == 1){
      res = 1;
    }
    else {
      for(int hiragana = 0; hiragana <= 40; hiragana++){
	res += dp[text.size()][hiragana][1] % MOD;
      }
    }
    printf("%d\n",res % MOD);
  }
}
