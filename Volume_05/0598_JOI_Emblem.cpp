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

char stage[1010][1010];
char crest[8][8];
int dp[1001][1001];
int W,H;

int match(int x,int y){
  int count = 0;
  if(x < 0 || y < 0 || x + 1 >= W || y + 1 >= H) return 0;
  for(int stage_y = y,crest_y = 0; stage_y <= y + 1; stage_y++,crest_y++){
    for(int stage_x = x,crest_x = 0; stage_x <= x + 1; stage_x++,crest_x++){
      if(stage[stage_y][stage_x] == crest[crest_y][crest_x]){
	count++;
      }
    }
  }
  return (count == 4 ? 1 : 0);
}

int main(){
  while(~scanf("%d %d",&H,&W)){
    memset(dp,0,sizeof(dp));
    memset(stage,'\0',sizeof(stage));
    memset(crest,'\0',sizeof(crest));
    for(int y = 0; y < H; y++){
      char line[1010];
      scanf("%s",line);
      for(int x = 0; x < W; x++){
	stage[y][x] = line[x];
      }
    }
    for(int y = 0; y < 2; y++){
      char line[4];
      scanf("%s",line);
      for(int x = 0; x < 2; x++){
	crest[y][x] = line[x];
      }
    }

    int res = 0;

    for(int y = 0; y < H; y++){
      for(int x = 0; x < W; x++){
	res += match(x,y);
      }
    }

    const char JOI[] = {'J','O','I'};
    for(int y = 0; y < H; y++){
      for(int x = 0; x < W; x++){
	for(int char_i = 0; char_i < 3; char_i++){
	  int tmp = match(x,y) + match(x-1,y) + match(x,y-1) + match(x-1,y-1);
	  char prev = stage[y][x];
	  stage[y][x] = JOI[char_i];
	  res = max(res,res - tmp + (match(x,y) + match(x-1,y) + match(x,y-1) + match(x-1,y-1)));
	  stage[y][x] = prev;
	}
      }
    }
    
    printf("%d\n",res);
  }
}
