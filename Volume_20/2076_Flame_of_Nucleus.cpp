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
#include <complex>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;

static const double EPS = 1e-12;

static const int tx[] = {+0,+1,+0,-1};
static const int ty[] = {-1,+0,+1,+0};

int main(){
  int num_of_domes;
  int num_of_pipelines;
  int polluted_days;
  while(~scanf("%d %d %d",&num_of_domes,&num_of_pipelines,&polluted_days)){
    for(int pipeline_i = 0; pipeline_i < num_of_pipelines; pipeline_i++){
      int from,to,day;
      scanf("%d %d %d",&from,&to,&day);
    }
    for(int dome_i = 0; dome_i < num_of_domes; dome_i++){
      int current_reside_citizens;
      int protected_citizens;
      scanf("%d %d",&current_reside_citizens,&protected_citizens);
    }
  }
}
