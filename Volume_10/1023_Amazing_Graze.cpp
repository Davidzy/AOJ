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

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

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

vector<Point> buckets[2501][2501];

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
    vector<Point> energy_bullets;
    for(int combat_plane_i = 0; combat_plane_i < num_of_combat_planes; combat_plane_i++){
      int x,y;
      scanf("%d %d",&x,&y);
      combat_planes.push_back(Point(x,y));
    }
    for(int energy_bullet_i = 0; energy_bullet_i < num_of_energy_bullets; energy_bullet_i++){
      int x,y;
      scanf("%d %d",&x,&y);
      energy_bullets.push_back(Point(x,y));
    }

    const int MAX_H = 10000;
    const int MAX_W = 10000;
    for(int energy_bullet_i = 0; energy_bullet_i < num_of_energy_bullets; energy_bullet_i++){
      int bucket_x = energy_bullets[energy_bullet_i].x / (MAX_W / (radius * 4));
      int bucket_y = energy_bullets[energy_bullet_i].y / (MAX_H / (radius * 4));
      buckets[bucket_y][bucket_x].push_back(energy_bullets[energy_bullet_i]);
    }

    int sum = 0;
    for(int combat_plane_i = 0; combat_plane_i < num_of_combat_planes; combat_plane_i++){
      int bucket_x = combat_planes[combat_plane_i].x / (MAX_W / (radius * 4));
      int bucket_y = combat_planes[combat_plane_i].y / (MAX_H / (radius * 4));
      for(int tx = max(bucket_x - 1,0); tx <= bucket_x + 1; tx++){
	for(int ty = max(bucket_y - 1,0); ty <= bucket_y + 1; ty++){
	  for(int i = 0; i < buckets[ty][tx].size(); i++){
	    if(combat_planes[combat_plane_i].include(buckets[ty][tx][i],radius)){
	      sum++;
	    }
	  }
	}
      }
    }
    
    for(int i = 0; i <= 2500; i++){
      for(int j = 0; j <= 2500; j++){
	buckets[i][j].clear();
      }
    }

    printf("%d\n",sum);
  }
}
