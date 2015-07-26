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

int dp[100001][51]; //dp[pos][output char]

int compute_attribute(int hiragana){
  if(0 <= hiragana && hiragana <= 4) return 0; //あ～お
  if(5 <= hiragana && hiragana <= 9) return 1; //か～こ
  if(10 <= hiragana && hiragana <= 14) return 2; //さ～そ
  if(15 <= hiragana && hiragana <= 19) return 3; //た～と
  if(20 <= hiragana && hiragana <= 24) return 4; //は～ほ
  if(25 <= hiragana && hiragana <= 29) return 5; //ま～も
  if(30 <= hiragana && hiragana <= 32) return 6; //や～よ
  if(33 <= hiragana && hiragana <= 37) return 7; //ら～ろ
  if(38 <= hiragana && hiragana <= 40) return 8; //わ～ん
  return -1;
}

int next_hiragana(int hiragana){
  if(0 <= hiragana && hiragana <= 4) return (hiragana - 0 + 1) % 5 + 0; //あ～お
  if(5 <= hiragana && hiragana <= 9) return (hiragana - 5 + 1) % 5 + 5; //か～こ
  if(10 <= hiragana && hiragana <= 14) return (hiragana - 10 + 1) % 5 + 10; //さ～そ
  if(15 <= hiragana && hiragana <= 19) return (hiragana - 15 + 1) % 5 + 15; //た～と
  if(20 <= hiragana && hiragana <= 24) return (hiragana - 20 + 1) % 5 + 20; //は～ほ
  if(25 <= hiragana && hiragana <= 29) return (hiragana - 25 + 1) % 5 + 25; //ま～も
  if(30 <= hiragana && hiragana <= 32) return (hiragana - 30 + 1) % 3 + 30; //や～よ
  if(33 <= hiragana && hiragana <= 37) return (hiragana - 33 + 1) % 5 + 33; //ら～ろ
  if(38 <= hiragana && hiragana <= 40) return (hiragana - 38 + 1) % 3 + 38; //わ～ん
}

int main(){
  string text;
  while(cin >> text){
    if(text == "#") break;
    memset(dp,0,sizeof(dp));
    for(int text_i = 0; text_i < text.size(); text_i++){
      int current_attribute = compute_attribute(text[text_i]);
      for(int prev_hiragana = 0; prev_hiragana <= 40; prev_hiragana++){
	int prev_attribute = compute_attribute(prev_hiragana);
      }
    }
  }
}
