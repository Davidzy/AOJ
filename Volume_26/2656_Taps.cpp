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
  double target_temperature;
  int upper_bound;
  int temperature[2];
  int base_volume[2];
  while(~scanf("%lf %d",
	       &target_temperature,
	       &upper_bound)){
    scanf("%d %d",&temperature[0],&temperature[1]);
    scanf("%d %d",&base_volume[0],&base_volume[1]);
    
    double diff = numeric_limits<double>::max();
    for(int multiply_a = 0; multiply_a <= upper_bound; multiply_a++){
      for(int multiply_b = 0; multiply_b <= upper_bound; multiply_b++){
	int volume_a = multiply_a * base_volume[0];
	int volume_b = multiply_b * base_volume[1];
	if(volume_a + volume_b <= 0) continue;
	if(volume_a + volume_b > upper_bound) continue;
	double mix_temperature
	  = (double)(temperature[0] * volume_a + temperature[1] * volume_b)/(double)(volume_a + volume_b);
	diff = min(diff,abs(target_temperature - mix_temperature));
      }
    }

    printf("%5lf\n",diff);
  }
}
