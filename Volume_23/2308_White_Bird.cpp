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
 
const static int tx[] = {0,1,1,1,0,-1,-1,-1};
const static int ty[] = {-1,-1,0,1,1,1,0,-1};
 
static const double EPS = 1e-8;

class Obstacle {
public:
  int left_x, bottom_y, right_x, top_y;
  Obstacle(int left_x, int bottom_y, int right_x, int top_y)
    : left_x(left_x), bottom_y(bottom_y), right_x(right_x), top_y(top_y) {}
};

int main(){
  int num_of_obstacles;
  int velocity;
  int x,y;
  while(~scanf("%d %d %d %d",&num_of_obstacles,&velocity,&x,&y)){
    vector<Obstacle> obstacles;
    for(int i = 0; i < num_of_obstacles; i++){
      int left_x, bottom_y, right_x, top_y;
      scanf("%d %d %d %d",&left_x, &bottom_y, &right_x, &top_y);
      obstacles.push_back(Obstacle(left_x,bottom_y,right_x,top_y));
    }
  }
}
