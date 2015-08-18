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
  
static const double EPS = 1e-8;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

char stage[1001][1001];
char crest[5][5];
int dp[1001][1001];

bool match(int x,int y){
  int count = 0;
  for(int crest_y = y - 1,dy = 0; crest_y <= y; crest_y++,dy++){
    for(int crest_x = x - 1,dx = 0; crest_x <= x; crest_x++,dx++){
      if(stage[crest_y][crest_x] == crest[dy][dx]){
	count++;
      }
    }
  }
  return (count == 4);
}

int main(){
  int H,W;
  while(~scanf("%d %d",&H,&W)){
    memset(dp,0,sizeof(dp));
    for(int y = 0; y < H; y++){
      char line[1001];
      scanf("%s",line);
      for(int x = 0; x < W; x++){
	stage[y][x] = line[x];
      }
    }
    for(int y = 0; y < 2; y++){
      char line[3];
      scanf("%s",line);
      for(int x = 0; x < 2; x++){
	crest[y][x] = line[x];
      }
    }
    for(int y = 1; y < H; y++){
      for(int x = 1; x < W; x++){
	if(match(x,y)){
	  for(int dy = y - 2,dx = x - 2; dy <= y && dx >= 0; dy++){
	    dp[y][x] = max(dp[y][x],dp[dy][dx] + 1);
	  }
	  for(int dx =  x - 2,dy = y - 2; dx <= x && dy >= 0; dx++){
	    dp[y][x] = max(dp[y][x],dp[dy][dx] + 1);
	  }
	}
      }
    }

    int res = 0;
    for(int y = 1; y < H; y++){
      for(int x = 1; x < W; x++){
	res = max(dp[y][x],res);
      }
    }
    printf("%d\n",res);
  }
}
