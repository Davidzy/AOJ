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

static const int tx[] = {+0,+1,+1,+1,+0,-1,-1,-1,+0};
static const int ty[] = {-1,-1,+0,+1,+1,+1,+0,-1,+0};

struct Cafe {
  int x,y,v;
  Cafe(int x,int y,int v)
    : x(x),y(y),v(v) {}
};

double compute_cost(const vector<Cafe>& cafes, double x, double y){
  double max_cost = 0.0;
  for(int cafe_i = 0; cafe_i < cafes.size(); cafe_i++){
    max_cost = max(max_cost,
		   sqrt((double)(cafes[cafe_i].x - x) * (double)(cafes[cafe_i].x - x)
			+ (double)(cafes[cafe_i].y - y) * (double)(cafes[cafe_i].y - y))
		   / (double)cafes[cafe_i].v);
  }
  return max_cost;
}

double compute_cost(const vector<Cafe>& cafes, double x){
  double upper_y = 100.0;
  double lower_y = 0.0;
  for(int round = 0; round < 50; round++){
    double mid1 = lower_y + (upper_y - lower_y) / 3.0;
    double mid2 = lower_y + 2.0 * (upper_y - lower_y) / 3.0;
    if(compute_cost(cafes,x,mid1) < compute_cost(cafes,x,mid2)){
      upper_y = mid2;
    }
    else{
      lower_y = mid1;
    }
  }
  return compute_cost(cafes,x,lower_y);
}

double compute_cost(const vector<Cafe>& cafes){
  double upper_x = 100.0;
  double lower_x = 0.0;
  for(int round = 0; round < 50; round++){
    double mid1 = lower_x + (upper_x - lower_x) / 3.0;
    double mid2 = lower_x + 2.0 * (upper_x - lower_x) / 3.0;
    if(compute_cost(cafes,mid1) < compute_cost(cafes,mid2)){
      upper_x = mid2;
    }
    else{
      lower_x = mid1;
    }
  }

  return compute_cost(cafes,lower_x);
}


int main(){
  int num_of_cafes;
  while(~scanf("%d",&num_of_cafes)){
    if(num_of_cafes == 0) break;
    vector<Cafe> cafes;
    for(int cafe_i = 0; cafe_i < num_of_cafes; cafe_i++){
      int x,y,v;
      scanf("%d %d %d",&x,&y,&v);
      cafes.push_back(Cafe(x,y,v));
    }
    
    printf("%lf\n",compute_cost(cafes));
  }
}
