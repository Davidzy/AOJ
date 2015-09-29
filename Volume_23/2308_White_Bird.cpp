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
#include <complex>
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

typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

double cross(const Point& a, const Point& b) {
  return imag(conj(a)*b);
}
double dot(const Point& a, const Point& b) {
  return real(conj(a)*b);
}

struct Line : public vector<Point> {
  Line(const Point &a, const Point &b) {
    push_back(a); push_back(b);
  }
};

int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

bool is_inside(double lower, double upper,double pos){
  if(lower > pos) return false;
  if(upper < pos) return false;
  return true;
}

bool can_drop(const vector<Obstacle>& obstacles,double sx, double sy,double gx,double gy){
  if(sy < gy) return false;

  for(int i = 0; i < obstacles.size(); i++){
    Line l1(Point(obstacles[i].left_x,obstacles[i].bottom_y),
	    Point(obstacles[i].right_x,obstacles[i].bottom_y));
    Line l2(Point(sx,sy),Point(gx,gy));
    if(intersectSS(l1,l2)) return false;
  }
  return true;
}

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
    for(double rad = 0; rad <= M_PI / 2.0; rad += EPS){
      bool isok = true;
      double vx = (double)v * cos(rad);
      double vy = (double)v * sin(rad);

      double gtime = (double)gx / vx;
      double y = vy * gtime - g * gtime * gtime * 0.5;
      if(!can_drop(obstacles,gx,y,gx,gy)){
	continue;
      }

      for(int i = 0; i < num_of_obstacles; i++){
	if(obstacles[i].right_x > gx) continue;

	double t1 = (double)obstacles[i].left_x / vx;
	double t2 = (double)obstacles[i].right_x / vx;

	double y1 = vy * t1 - g * t1 * t1 * 0.5;
	double y2 = vy * t2 - g * t2 * t2 * 0.5;
	if(is_inside(obstacles[i].bottom_y,obstacles[i].top_y,y1)
	   || is_inside(obstacles[i].bottom_y,obstacles[i].top_y,y2)){
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
