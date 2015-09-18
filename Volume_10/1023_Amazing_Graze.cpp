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

int main(){
  int num_of_combat_planes;
  int num_of_energy_bullets;
  int radius;
  while(~scanf("%d %d %d",
	       &num_of_combat_planes,
	       &num_of_energy_bullets,
	       &radius)){
    for(int combat_plane_i = 0; combat_plane_i < num_of_combat_planes; combat_plane_i++){
      int x,y;
      scanf("%d %d",&x,&y);
    }
    for(int energy_bullet_i = 0; energy_bullet_i < num_of_energy_bullets; energy_bullet_i++){
      int x,y;
      scanf("%d %d",&x,&y);
    }
  }
}
