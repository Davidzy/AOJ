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
 
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};
 
static const double EPS = 1e-8;

double time_x_to_next_x(double x, double r, double v, double e, double f){
  if(x >= r){
    return 1.0 / (v - e * (x - r));
  }
  else{
    return 1.0 / (v - f * (r - x));
  }
}

int main(){
  int num_of_checkpoints;
  while(~scanf("%d",&num_of_checkpoints)){
    vector<int> checkpoints;
    for(int checkpoint_i = 0; checkpoint_i < num_of_checkpoints; checkpoint_i++){
      int pos;
      scanf("%d",&pos);
      checkpoints.push_back(pos);
    }
    double tire_change_time;
    scanf("%lf",&tire_change_time);
    double r,v,e,f;
    scanf("%lf %lf %lf %lf",&r,&v,&e,&f);
  }
}
