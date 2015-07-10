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
  int H,W;
  while(~scanf("%d %d",&H,&W)){
    char stage[101][101];
    for(int y = 0; y < H; y++){
      int time = -1;
      bool has_cloud = false;
      char line[128];
      scanf("%s",line);
      for(int x = 0; x < W; x++){
	stage[y][x] = line[x];
	if(stage[y][x] == 'c'){
	  time = 0;
	  has_cloud = true;
	}

	printf("%d%s",time,(x == W - 1 ? "" : " "));
	if(has_cloud){
	  time++;
	}
      }
      printf("\n");
    }
  }
}
