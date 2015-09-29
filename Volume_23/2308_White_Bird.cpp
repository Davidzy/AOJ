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
 
static const double EPS = 1e-6;

class Obstacle {
public:
  int left_x, bottom_y, right_x, top_y;
  Obstacle(int left_x, int bottom_y, int right_x, int top_y)
    : left_x(left_x), bottom_y(bottom_y), right_x(right_x), top_y(top_y) {}
};

const static double g = 9.8;

int main(){
  int num_of_obstacles;
  int v;
  int gx,gy;
  while(~scanf("%d %d %d %d",&num_of_obstacles,&v,&gx,&gy)){
    vector<Obstacle> obstacles;
    for(int i = 0; i < num_of_obstacles; i++){
      int left_x, bottom_y, right_x, top_y;
      scanf("%d %d %d %d",&left_x, &bottom_y, &right_x, &top_y);
      obstacles.push_back(Obstacle(left_x,bottom_y,right_x,top_y));
    }

    string res = "No";
    for(double rad = 0.0000001; rad < M_PI / 2.0; rad += 0.0000001){
      bool isok = true;
      double vx = (double)v * cos(rad);
      double vy = (double)v * sin(rad);

      double gtime = (double)gx / vx;
      double y = vy * gtime - g * gtime * gtime * 0.5;
      if(!((double)gy - EPS <= y && y <= (double)gy + EPS)){
	continue;
      }

      for(int i = 0; i < num_of_obstacles; i++){
	double t1 = (double)obstacles[i].left_x / vx;
	double t2 = (double)obstacles[i].right_x / vx;

	double y1 = vy * t1 - g * t1 * t1 * 0.5;
	double y2 = vy * t2 - g * t2 * t2 * 0.5;
	if(y1 < 0 || y2 < 0){
	  isok = false;
	  break;
	}
	if(!((double)obstacles[i].bottom_y > y1 + EPS
	     || (double)obstacles[i].top_y < y1 - EPS)){
	  isok = false;
	  break;
	}
	if(!((double)obstacles[i].bottom_y > y2 + EPS
	     || (double)obstacles[i].top_y < y2 - EPS)){
	  isok = false;
	  break;
	}
      }
      if(isok){
	res = "Yes";
	break;
      }
    }

    cout << res << endl;
  }
}
