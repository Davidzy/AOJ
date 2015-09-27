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
 
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};
 
static const double EPS = 1e-8;

typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

struct Line : public vector<Point> {
  Line(const Point &a, const Point &b) {
    push_back(a); push_back(b);
  }
};

struct Circle {
  Point p; double r;
  Circle(const Point &p, double r) : p(p), r(r) { }
};

double norm(const Point& p){
  return p.real() * p.real() + p.imag() * p.imag();
}

double abs(const Point& p){
  return sqrt(norm(p));
}

Point unit(const Point& p){
  return p/abs(p);
}

double cross(const Point& a, const Point& b) {
  return imag(conj(a)*b);
}

double dot(const Point& a, const Point& b) {
  return real(conj(a)*b);
}

int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

int main(){
  double limit_distance;
  while(~scanf("%lf",&limit_distance)){
    if(limit_distance == 0) break;
    double px,py;
    double vx,vy;
    scanf("%lf %lf",&px,&py);
    scanf("%lf %lf",&vx,&vy);

    Circle circle(Point(0,0),1.0);
    Line laser(Point(px,py),Point(px + vx, py + vy));

    int pos = ccw(laser[0],circle.p,laser[1]);
    double distance = 0.0;
    if(pos == -2 || pos == 0){
      distance = abs(laser[0] - circle.p);
    }
    else if(pos == 2){
      distance = 2.0 - abs(laser[0] - circle.p);
    }
    else{
      printf("impossible\n");
      continue;
    }

    if(distance >= limit_distance){
      printf("impossible\n");
    }
    else{
      printf("%.8lf\n",distance);
    }
  }
}
