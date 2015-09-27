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

bool intersectCS(const Circle& s,const Line& t){
  Point v = t[1] - t[0];
  Point c = s.p - t[0];
  Point b = s.p - t[1];
  if(dot(v,c) < 0){
    if(abs(c) < s.r) return true;
    return false;
  }
  else{
    if(dot(v,c) > dot(v,v)){
      if(dot(s.r,s.r) > dot(b,b)) return true;
      return false;
    }
    else{
      if(dot(c,c) - dot(v,c) * dot(v,c) / dot(v,v) < dot(s.r,s.r)) return true;
      if(abs(c) < s.r || abs(b) < s.r) return true;
      return false;
    }
  }
}

vector<Point> crosspointLC(const Line& l,const Circle& ci){
  Point dir = unit(l[1] - l[0]);
  // a * t^2 + b * t + c = 0
  double a = norm(dir);
  double b = dot(l[0] - ci.p,dir);
  double c = norm(l[0] - ci.p) - ci.r * ci.r;
  double D = b * b - a * c;

  vector<Point> res;
  if(D < EPS) return res;
  double t1 = (-b - sqrt(D))/a;
  double t2 = (-b + sqrt(D))/a;

  if(dot(l[0] + dir * t1,l[1] - l[0]) > 0){
    res.push_back(l[0] + dir * t1);
  }
  else{
    res.push_back(l[0] + dir * t2);
  }
  return res;
}

Point projection(const Line& l,const Point& p){
  double t = dot(p - l[0],l[0]-l[1]) / norm(l[0] - l[1]);
  return l[0] + (l[0] - l[1]) * t;
}

Point reflection(const Line& l,const Point& p){
  return p + (projection(l,p) - p) * 2.0;
}

int main(){
  double limit_distance;
  while(~scanf("%lf",&limit_distance)){
    if(limit_distance < EPS) break;
    double px,py;
    double vx,vy;
    scanf("%lf %lf",&px,&py);
    scanf("%lf %lf",&vx,&vy);

    Circle circle(Point(0,0),1.0);
    Line laser(Point(px,py),Point(px + vx,py + vy));

    double moved_distance = 0;
    while(moved_distance <= limit_distance){
      Point prev = laser[0];
      vector<Point> tmp_points = crosspointLC(laser,circle);
      Point reflection_point = tmp_points[0];
      Line nv(reflection_point,circle.p);

      // to circle wall
      if(abs(ccw(reflection_point,circle.p,10000.0 * (prev - reflection_point))) == 2){
	moved_distance += abs(circle.p - prev);
	break;
      }

      // don't pass center
      moved_distance += abs(reflection_point - prev);

      // from circle wall
      laser = Line(reflection_point,reflection(nv,laser[0]));
      if(abs(ccw(laser[0],circle.p,laser[0] + 100000.0 * (laser[1] - laser[0]))) == 2){
	moved_distance += abs(laser[1] - circle.p);
	break;
      }
    }
    
    if(moved_distance <= limit_distance){
      printf("%lf\n",moved_distance);
    }
    else{
      printf("impossible\n");
    }
  }
}
