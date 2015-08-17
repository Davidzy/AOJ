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

int main(){
  int H,W;
  while(~scanf("%d %d",&H,&W)){
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
      for(int x = 0; x < W; x++){
	crest[y][x] = line[x];
      }
    }
  }
}
