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
   
static const double EPS = 1e-12;
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

class Point {
public:
  double x;
  double y;
  double z;
  Point (double x,double y,double z) :
    x(x), y(y), z(z) {}
  Point () : x(0), y(0), z(0) {}
  Point operator-(const Point& p) const {
    return Point(this->x - p.x,
		 this->y - p.y,
		 this->z - p.z);
  }
  Point operator+(const Point& p) const {
    return Point(this->x + p.x,
		 this->y + p.y,
		 this->z + p.z);
  }
  void operator+=(const Point& p) const {
    this->x + p.x;
    this->y + p.y;
    this->z + p.z;
  }
  Point operator*(const double t) const {
    return Point(this->x * t,
		 this->y * t,
		 this->z * t);
  }
  Point operator*(const Point&p) const {
    return Point(this->x * p.x,
		 this->y * p.y,
		 this->z * p.z);
  }
  Point operator/(const double t) const {
    return Point(this->x / t,
		 this->y / t,
		 this->z / t);
  }
  void operator/=(const double t) {
    this->x /= t;
    this->y /= t;
    this->z /= t;
  }
  void print_vec() const{
    printf("(%lf,%lf,%lf)\n",this->x,this->y,this->z);
  }
};

class Line : public vector<Point> {
public:
  Line(const Point& p1,const Point& p2) {
    push_back(p1);
    push_back(p2);
  }
};

class Circle {
public:
  Point p;
  double r;
  Circle(const Point& p,double r) : p(p),r(r) {}
};

double norm(const Point& p){
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

double abs(const Point& p){
  return sqrt(norm(p));
}

Point unit(const Point& p){
  return p/abs(p);
}

double dot(const Point& p1,const Point& p2){
  return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

Point cross(const Point& p1,const Point& p2){
  return Point(p1.y * p2.z - p1.z * p2.y,
	       p1.z * p2.x - p1.x * p2.z,
	       p1.x * p2.y - p1.y * p2.x);
}

Point projection(const Line& l,const Point& p){
  double t = dot(p - l[0],l[0]-l[1]) / norm(l[0] - l[1]);
  return l[0] + (l[0] - l[1]) * t;
}

bool EQ(const Point& s,const Point& t) {
  if((t.x - EPS <= s.x && s.x <= t.x + EPS)
     && (t.y - EPS <= s.y && s.y <= t.y + EPS)
     && (t.z - EPS <= s.z && s.z <= t.z + EPS)) return true;
  return false;
}

bool parallelLL(const Line &l, const Line &m) {
  return EQ(cross(l[1]-l[0], m[1]-m[0]),Point(0,0,0));
}

bool intersectLP(const Line &l, const Point &p) {
  return (abs(cross(l[1]-p, l[0]-p)) < EPS);
}

double distanceLP(const Line& l,const Point& p){
  if(intersectLP(l,p)) return 0;
  return abs(p - projection(l,p));
}

double distanceLL(const Line& l,const Line& m){
  if(parallelLL(l,m)) return distanceLP(l,m[0]);

  const Point V1 = l[1] - l[0];
  const Point V2 = m[1] - m[0];
  const Point V3 = m[0] - l[0];
  return abs(dot(cross(V1,V2),V3)/abs(cross(V1,V2)));
}

double distancePP(const Point& s,const Point& t) {
  if(EQ(s,t)) return 0;
  return abs(Point(s.x - t.x,s.y - t.y,s.z - t.z));
}

vector<Point> crosspointLC(const Line& l,const Circle& ci){
  Point dir = unit(l[1] - l[0]);
  // a * t^2 + b * t + c = 0
  double a = norm(dir);
  double b = dot(l[0] - ci.p,dir);
  double c = norm(l[0] - ci.p) - ci.r * ci.r;
  double D = b * b - a * c;

  vector<Point> res;
  if(D < 0) return res;
  double t1 = (-b - sqrt(D))/a;
  double t2 = (-b + sqrt(D))/a;

  if(abs(t1) < abs(t2)){
    res.push_back(l[0] + dir * t1);
  }
  else{
    res.push_back(l[0] + dir * t2);
  }
  return res;
}

Point reflection(const Line& l,const Point& p){
  return p + (projection(l,p) - p) * 2.0;
}

int main(){
  int num_of_obstacles;
  int num_of_objects;
  while(~scanf("%d %d",
	       &num_of_obstacles,
	       &num_of_objects)){
    vector<Circle> obstacles;
    vector<int> costs;
    for(int obstacle_i = 0; obstacle_i < num_of_obstacles; obstacle_i++){
      int x,y,z;
      int radius;
      int amount_of_consumption;
      scanf("%d %d %d %d %d",&x,&y,&z,&radius,&amount_of_consumption);
      obstacles.push_back(Circle(Point(x,y,z),radius));
      costs.push_back(amount_of_consumption);
    }
    for(int object_i = 0; object_i < num_of_objects; object_i++){
      int red_x,red_y,red_z;
      int blue_x,blue_y,blue_z;
      scanf("%d %d %d %d %d %d",
	    &red_x,&red_y,&red_z,
	    &blue_x,&blue_y,&blue_z);
      Line line(Point(red_x,red_y,red_z),Point(blue_x,blue_y,blue_z));

      int sum = 0;
      for(int obstacle_i = 0; obstacle_i < num_of_obstacles; obstacle_i++){
	vector<Point> p = crosspointLC(line,obstacles[obstacle_i]);
	if(p.size() > 0) sum += costs[obstacle_i];
      }
      printf("%d\n",sum);
    }
  }
}
