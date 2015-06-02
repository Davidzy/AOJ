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
int edges[51][51][51][51];

int main(){
  int H,W;

  while(~scanf("%d %d",&H,&W)){
    if(H == 0 && W == 0) break;

    int pos = 0;
    int patterns[] = {W - 1, W};
    int accumulate[31] = {};
    accumulate[0] = patterns[0];
    for(int i = 1; i < 30; i++){
      accumulate[i] = patterns[i % 2] + accumulate[i - 1];
    }
    while(pos < ((H - 1) * W) + (H * (W - 1))){
      int flag;
      scanf("%d",&flag);
      pos++;
      int depth = (lower_bound(accumulate,accumulate + 30,pos) - accumulate);
      int type = depth % 2;
      if(type == 0){
	int from_y = depth/2;
	int from_x = (pos - 1)- accumulate[depth - 1];
	int to_y = depth/2;
	int to_x = (pos - 1) - accumulate[depth - 1] + 1;
	edges[from_y][from_x][to_y][to_x] = flag;
	edges[to_y][to_x][from_y][from_x] = flag;
      }
      else{
	int from_y = depth/2;
	int from_x = (pos - 1) - accumulate[depth - 1];
	int to_y = depth/2 + 1;
	int to_x = (pos - 1) - accumulate[depth - 1];
	edges[from_y][from_x][to_y][to_x] = flag;
	edges[to_y][to_x][from_y][from_x] = flag;
      }
    }

    for(int sy = 0; sy < 5; sy++){
      for(int sx = 0; sx < 5; sx++){
	for(int gy = 0; gy < 5; gy++){
	  for(int gx = 0; gx < 5; gx++){
	    printf("(%d %d) -> (%d %d) %d\n",sx,sy,gx,gy,edges[sy][sx][gy][gx]);
	  }
	}
      }
    }
  }
}
