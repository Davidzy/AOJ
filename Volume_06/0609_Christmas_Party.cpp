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
  int total_friends;
  int total_games;
  while(~scanf("%d",&total_friends)){
    scanf("%d",&total_games);
    int targets[101] = {};
    int scores[101] = {};
    for(int game_i = 0; game_i < total_games; game_i++){
      scanf("%d",targets + game_i);
      targets[game_i]--;
    }
    for(int game_i = 0; game_i < total_games; game_i++){
      int to[101] = {};
      for(int friend_i = 0; friend_i < total_friends; friend_i++){
	scanf("%d",to + friend_i);
	to[friend_i]--;
	if(to[friend_i] != targets[game_i]){
	  scores[targets[game_i]]++;
	}
	else {
	  scores[friend_i]++;
	}
      }
    }
    for(int friend_i = 0; friend_i < total_friends; friend_i++){
      printf("%d\n",scores[friend_i]);
    }
  }
}
