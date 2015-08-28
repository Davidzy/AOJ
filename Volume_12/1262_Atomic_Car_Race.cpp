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

double compute_next_x_duration(double x, double r, double v, double e, double f){
  if(x >= r){
    return 1.0 / (v - e * (x - r));
  }
  else{
    return 1.0 / (v - f * (r - x));
  }
}

double compute_duration(double from, double to, double r, double v, double e, double f){
  double sum = 0;
  for(int pos = from; pos < to; pos++){
    sum += compute_next_x_duration(pos,r,v,e,f);
  }
  return sum;
}


double dp[101][2]; // dp[current_i][used]

int main(){
  int num_of_checkpoints;
  while(~scanf("%d",&num_of_checkpoints)){
    if(num_of_checkpoints == 0) break;

    vector<int> checkpoints;
    checkpoints.push_back(0);
    for(int checkpoint_i = 0; checkpoint_i < num_of_checkpoints; checkpoint_i++){
      int pos;
      scanf("%d",&pos);
      checkpoints.push_back(pos);
    }
    double tire_change_time;
    scanf("%lf",&tire_change_time);
    double r,v,e,f;
    scanf("%lf %lf %lf %lf",&r,&v,&e,&f);

    fill((double*)dp,(double*)dp + 101 * 2,1000000000000.0);
    dp[0][1] = 0;
    for(int current_i = 0; current_i < checkpoints.size(); current_i++){
      for(int prev_i = 0; prev_i < current_i; prev_i++){
	// x is a nonnegative integer denoting the distance (in kilometers) 
	// from the latest checkpoint where tires are changed
	
	dp[current_i][0]
	  = min(dp[prev_i][1]
		+ compute_duration(checkpoints[prev_i],checkpoints[current_i],r,v,e,f),
		dp[current_i][0]);

	dp[current_i][1]
	  = min(dp[prev_i][1]
		+ compute_duration(checkpoints[prev_i],checkpoints[current_i],r,v,e,f)
		+ tire_change_time,
		dp[current_i][1]);
      }
    }

    printf("%lf\n",min(dp[checkpoints.size()-1][1],dp[checkpoints.size()-1][0]));
  }
}
