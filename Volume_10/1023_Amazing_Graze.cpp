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

class Point {
public:
  int x;
  int y;
  Point(int x,int y){
    this->x = x;
    this->y = y;
  }
  bool include(const Point& p,int radius){
    return ((x - p.x) * (x - p.x)
	    + (y - p.y) * (y - p.y) <= 16 * radius * radius);
  }
};

int main(){
  int num_of_combat_planes;
  int num_of_energy_bullets;
  int radius;
  while(~scanf("%d %d %d",
	       &num_of_combat_planes,
	       &num_of_energy_bullets,
	       &radius)){
    if(num_of_combat_planes == 0 && num_of_energy_bullets == 0){
      break;
    }
    vector<Point> combat_planes;
    for(int combat_plane_i = 0; combat_plane_i < num_of_combat_planes; combat_plane_i++){
      int x,y;
      scanf("%d %d",&x,&y);
      combat_planes.push_back(Point(x,y));
    }
    vector<int> energy_bullets[10001];
    for(int energy_bullet_i = 0; energy_bullet_i < num_of_energy_bullets; energy_bullet_i++){
      int x,y;
      scanf("%d %d",&x,&y);
      energy_bullets[x].push_back(y);
    }
    for(int x = 0; x <= 10000; x++){
      sort(energy_bullets[x].begin(),energy_bullets[x].end());
    }

    int sum = 0;
    for(int combat_plane_i = 0; combat_plane_i < num_of_combat_planes; combat_plane_i++){
      for(int x = max(combat_planes[combat_plane_i].x - (4 * radius),0); x <= combat_planes[combat_plane_i].x + (4 * radius); x++){
	int end_y = upper_bound(energy_bullets[x].begin(),energy_bullets[x].end(),combat_planes[combat_plane_i].y + 4 * radius) - energy_bullets[x].begin();
	int begin_y = lower_bound(energy_bullets[x].begin(),energy_bullets[x].end(),combat_planes[combat_plane_i].y - 4 * radius) - energy_bullets[x].begin();
	for(int i = begin_y; i < end_y; i++){
	  sum += combat_planes[combat_plane_i].include(Point(x,energy_bullets[x][i]),radius);
	}
      }
    }

    printf("%d\n",sum);
  }
}
