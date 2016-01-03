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
  string cypher;
  while(cin >> cypher){
    if(cypher == "#END") break;

    string res = "";
    for(int split_i = 1; split_i < cypher.size(); split_i++){
      //[0,split_i),[split_i,cypher.size())
      string A = cypher.substr(0, split_i - 0);
      string B = cypher.substr(split_i, cypher.size() - split_i);

      string dp_str[301][301];
      dp_str[0][0] = "";
      for(int y = 0; y < A.size(); y++){
	for(int x = 0; x < B.size(); x++){
	  if(A[y] == B[x]){
	    dp_str[y+1][x+1] = dp_str[y][x] + A[y];
	  }
	  else {
	    if(dp_str[y][x+1].size() > dp_str[y+1][x].size()){
	      dp_str[y+1][x+1] = dp_str[y][x+1];
	    }
	    else{
	      dp_str[y+1][x+1] = dp_str[y+1][x];
	    }
	  }
	}
      }
      if(res.size() < dp_str[A.size()][B.size()].size()){
	res = dp_str[A.size()][B.size()];
      }
    }
    printf("%s\n",res.c_str());
  }
}
