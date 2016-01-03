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
      queue<char> que;
      if(A.size() < B.size()){
	swap(A,B);
      }
      
      // A is longer than B
      for(int A_i = 0; A_i < A.size(); A_i++){
	que.push(A[A_i]);
      }

      int B_i = 0;
      bool isok = false;
      while(!que.empty()){
	char current_char = que.front();
	que.pop();
	if(B[B_i] == current_char){
	  B_i++;
	}
	if(B_i >= B.size()){
	  isok = true;
	  break;
	}
      }

      if(isok && res.size() < B.size()){
	res = B;
      }
    }
    printf("%s\n",res.c_str());
  }
}
