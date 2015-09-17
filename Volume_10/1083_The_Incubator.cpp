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

int main(){
  int num_of_queries;
  int limits;
  while(~scanf("%d %d",&num_of_queries,&limits)){
    if(num_of_queries == 0 && limits == 0){
      break;
    }

    deque<int> deq;
    for(int query_i = 0; query_i < num_of_queries; query_i++){
      int query,x;
      scanf("%d %d",&query,&x);
      if(query == 0){
	deq.push_back(x);
      }
      else if(query == 1){
	deq.erase(deq.begin() + x - 1);
      }
      else if(query == 2){
	printf("%d\n",deq[x-1]);
      }
      else if(query == 3){
	for(int i = 0; i < deq.size(); i++){
	  if(deq[i] == x){
	    deq.erase(deq.begin() + i);
	    break;
	  }
	}
      }

      while(!deq.empty() && deq.size() > limits){
      	deq.pop_front();
      }
    }
    printf("end\n");
  }
}
