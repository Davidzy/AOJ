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
typedef pair <int,vector<int> > P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int num_of_springs;
  int num_of_districts;
  while(~scanf("%d %d",&num_of_springs,&num_of_districts)){
    if(num_of_springs == 0 && num_of_districts == 0) break;

    int spring_district_distance[51][51];
    for(int spring_i = 0; spring_i < num_of_springs; spring_i++){
      for(int district_i = 0; district_i < num_of_districts; district_i++){
	scanf("%d",&spring_district_distance[spring_i][district_i]);
      }
    }

    int district_distance[51][51];
    for(int i = 0; i < num_of_districts - 1; i++){
      for(int j = 0; j < num_of_springs - i; j++){
	scanf("%d",&district_distance[j][i+j]);
      }
    }
  }
}
