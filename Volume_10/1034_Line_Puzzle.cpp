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

void disp(int stage[12][12], const int stage_size){
  for(int y = 0; y < stage_size; y++){
    for(int x = 0; x < stage_size; x++){
      printf("%d ",stage[y][x]);
    }
    printf("\n");
  }
  printf("\n");
}

class Cell {
public:
  int x;
  int y;
  int energy;
  Cell(int x,int y,int energy)
    : x(x), y(y), energy(energy) {}
};

bool check_all_zero(int stage[12][12], const int stage_size){
  for(int y = 0; y < stage_size; y++){
    for(int x = 0; x < stage_size; x++){
      if(stage[y][x] != 0) return false;
    }
  }
  return true;
}

Cell find_starting_point(int stage[12][12], const int stage_size){
  for(int y = 0; y < stage_size; y++){
    for(int x = 0; x < stage_size; x++){
      if(stage[y][x] < 0){
	return Cell(x,y,-stage[y][x]);
      }
    }
  }
  return Cell(-1,-1,0);
}

bool dfs(int stage[12][12], const int stage_size,
	 int sx, int sy,int life){
  bool res = false;
  if(life < 0){
    return false;
  }
  if(life == 0){
    if(check_all_zero(stage,stage_size)){
      return true;
    }
    else{
      Cell c = find_starting_point(stage,stage_size);
      if(c.x == -1 && c.y == -1) return false;
      stage[c.y][c.x] = 0;
      res |= dfs(stage,stage_size,c.x,c.y,c.energy);
      stage[c.y][c.x] = -c.energy;
    }
  }

  for(int i = 0; i < 4; i++){
    int dx = tx[i] + sx;
    int dy = ty[i] + sy;
    if(dx < 0 || dy < 0 || dx >= stage_size || dy >= stage_size){
      continue;
    }
    if(stage[dy][dx] <= 0){
      continue;
    }
    if(life - stage[dy][dx] < 0){
      continue;
    }

    int tmp = stage[dy][dx];
    stage[dy][dx] = 0;
    res |= dfs(stage,stage_size,dx,dy,life - tmp);
    stage[dy][dx] = tmp;
  }
  return res;
}

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

    printf("%s\n",dfs(stage,stage_size,0,0,0) ? "YES" : "NO");
  }
}
