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

struct State {
  int pos;
  string str_result;
  int int_result;
  State(int pos,string str_result) 
    : pos(pos), str_result(str_result) {}
  State(int pos,int int_result) 
    : pos(pos), int_result(int_result) {}
};

// EXPR ::= NUMBERS ( EXPR ) | ALPHAS

State alphas(const string& str,int pos){
  string tmp = "";
  while(isalpha(str[pos])){
    tmp.push_back(str[pos]);
    pos++;
  }
  return State(pos,tmp);
}

State numbers(const string& str,int pos){
  stringstream ss;
  while(isdigit(str[pos])){
    ss << str[pos];
    pos++;
  }
  return State(pos,atoi(ss.str().c_str()));
}

State expr(const string& str,int pos){
  if(isdigit(str[pos])){
    State s1 = numbers(str,pos);
    State s2 = expr(str,s1.pos + 1);

    string tmp = "";
    for(int i = 0; i < s1.int_result; i++){
      tmp += s2.str_result;
    }
    return State(s2.pos,tmp);
  }
  else{
    return alphas(str,pos);
  }
}


int main(){
  string genome;
  int pos;
  while(cin >> genome >> pos){
    cout << expr(genome,0).str_result << endl;
  }
}
