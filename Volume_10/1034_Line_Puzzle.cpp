#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
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
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int stage_size;
  while(~scanf("%d",&stage_size)){
    if(stage_size == 0) break;
    int stage[12][12];
    for(int y = 0; y < stage_size; y++){
      for(int x = 0; x < stage_size; x++){
	scanf("%d",&stage[y][x]);
      }
    }
  }
}
