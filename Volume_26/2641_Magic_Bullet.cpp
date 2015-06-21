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
   
static const double EPS = 1e-8;
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int num_of_obstacles;
  int num_of_objects;
  while(~scanf("%d %d",
	       &num_of_obstacles,
	       &num_of_objects)){
    for(int obstacle_i = 0; obstacle_i < num_of_obstacles; obstacle_i++){
      int x,y,z;
      int radius;
      int amount_of_consumption;
      scanf("%d %d %d %d %d",&x,&y,&z,&radius,&amount_of_consumption);
    }
    for(int object_i = 0; object_i < num_of_obstacles; object_i++){
      int red_x,red_y,red_z;
      int blue_x,blue_y,blue_z;
      scanf("%d %d %d %d %d %d",
	    &red_x,&red_y,&red_z,
	    &blue_x,&blue_y,&blue_z);
    }
  }
}
