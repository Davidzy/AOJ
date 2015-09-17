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

// <TREE> := (<LEAF><OPE><LEAF>)
// <LEAF> := (<TREE>) | <NUMBER>

P tree(const string& expr,int sweets[16],int pos);
P leaf(const string& expr,int sweets[16],int pos);

P tree(const string& expr,int sweets[16],int pos){
  int set = 0;
  while(pos < expr.size() && expr[pos] == '('){
    P r1 = leaf(expr,sweets,pos + 1);
    pos = r1.first;
    char ope = expr[pos];
    P r2 = leaf(expr,sweets,pos+1);
    if(ope == 'A'){
      set |= r1.second & r2.second;
    }
    else if(ope == 'O'){
      set |= r1.second | r2.second;
    }

    else if(ope == 'X'){
      set |= r1.second ^ r2.second;
    }
    pos = r2.first;
  }
  return P(pos,set);
}

P leaf(const string& expr,int sweets[16], int pos){
  if(expr[pos] == '('){
    P r = tree(expr,sweets,pos+1);
    pos = r.first + 1;
    return P(pos,r.second);
  }
  else{
    return P(pos+1,expr[pos] - '0');
  }
}

int dfs(string expr,int sweets[16],int pos,int N){
  if(pos >= expr.size()){
    P r = tree(expr,sweets,0);
    cout << expr << endl;
    cout << r. second << endl;
    if(r.second == (1<<N) - 1){
      return 1;
    }
    else{
      return 0;
    }
  }

  int res = 0;
  const char ope[] = {'A','O','X'};
  if(expr[pos] == ' '){
    for(int i = 0; i < 3; i++){
      expr[pos] = ope[i];
      res += dfs(expr,sweets,pos+1,N);
    }
  }
  else{
    res += dfs(expr,sweets,pos+1,N);
  }
  return res;
}

int main(){
  string expr;
  while(getline(cin,expr)){
    if(expr == "END") break;
    int N;
    string N_str;
    getline(cin,N_str);
    N = atoi(N_str.c_str());
    int sweets[16];
    for(int i = 1; i <= N; i++){
      int bit = 0;
      string flag_str;
      getline(cin,flag_str);
      for(int j = 0; j <= 6; j+=2){
	if(flag_str[j] - '0'){
	  bit |= (1<<(flag_str[j] - '0'));
	}
      }
      sweets[i] = bit;
    }
    printf("%d\n",dfs(expr,sweets,0,N));
  }
}
