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
 
const static int tx[] = {0,1,0,-1};
const static int ty[] = {-1,0,1,0};

const static double EPS = 1e-8;

int main(){
  int lhs,rhs;
  while(~scanf("%d %d",&lhs,&rhs)){
    if(lhs == 0 && rhs == 0) break;

    int res = INF;
    for(int a = 1; a * a <= lhs; a++){
      if(lhs % a != 0) continue;
      int b = lhs / a;
      for(int c = 1; c * c <= rhs; c++){
	if(rhs % c != 0) continue;
	int d = rhs / c;
	int tmp_numbers[4] = {a,b,c,d};
	sort(tmp_numbers, tmp_numbers + 4);

	int sum = 0;
	for(int num_i = 0; num_i < 3; num_i++){
	  sum += (tmp_numbers[num_i + 1] - tmp_numbers[num_i])
	    * (tmp_numbers[num_i + 1] - tmp_numbers[num_i]);
	}
	res = min(sum,res);
      }
    }

    printf("%d\n",res);
  }
}
