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
  
static const int tx[] = {+0,+1,+1,+1,+0,-1,-1,-1};
static const int ty[] = {-1,-1,+0,+1,+1,+1,+0,-1};

char stage[1001][1001];
char buffer[1001][1001];

int main(){
  int H,W;
  while(~scanf("%d %d",&H,&W)){
    for(int y = 0; y < H; y++){
      char line[1001];
      scanf("%s",line);
      for(int x = 0; x < W; x++){
	stage[y][x] = line[x];
	buffer[y][x] = line[x];
      }
    }

    int res = 0;
    for(int round = 0; round < 10010; round++){
      bool is_over = true;
      for(int y = 0; y < H; y++){
	for(int x = 0; x < W; x++){
	  if(stage[y][x] == '.') continue;
	  int strongness = stage[y][x] - '0';

	  int count = 0;
	  for(int i = 0; i < 8; i++){
	    int dx = x + tx[i];
	    int dy = y + ty[i];
	    if(dx < 0 || dx >= W || dy < 0 || dy >= H) continue;
	    if(stage[dy][dx] == '.'){
	      count++;
	    }
	  }

	  if(count >= strongness){
	    is_over = false;
	    buffer[y][x] = '.';
	  }
	}
      }
      if(is_over){
	res = round;
	break;
      }
      memcpy(stage,buffer,sizeof(char)*1001*1001);
    }
    printf("%d\n",res);
  }
}
