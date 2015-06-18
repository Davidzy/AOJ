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
  int W, H;
  int num_of_staff;
  while(~scanf("%d %d %d",&W,&H,&num_of_staff)){
    int lan_start_x,lan_start_y;
    int lan_end_x,lan_end_y;
    scanf("%d %d %d %d",
	  &lan_start_x,&lan_start_y,
	  &lan_end_x,&lan_end_y);
    for(int i = 0; i < num_of_staff; i++){
      int init_x,init_y;
      int repeat_time;
      string commands;
      cin >> init_x >> init_y >> repeat_time >> commands;
    }
  }
}
