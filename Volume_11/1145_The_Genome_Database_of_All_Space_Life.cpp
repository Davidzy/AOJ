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

// EXPR ::= NUMBERS ( EXPR ) | NUMBERS ALPHA | ALPHAS

State alphas(const string& str,int pos){
  string tmp = "";
  while(isalpha(str[pos])){
    tmp.push_back(str[pos]);
    pos++;
  }
  return State(pos,tmp);
}

State numbers(const string& str,int pos){
  int tmp = 0;
  while(isdigit(str[pos])){
    tmp += (str[pos] - '0');
    tmp *= 10;
    pos++;
  }
  tmp /= 10;
  return State(pos,tmp);
}

State expr(const string& str,int pos){
  string result = "";
  while(pos < str.size() && (isdigit(str[pos]) || isalpha(str[pos]))){
    if(isdigit(str[pos])){
      State s1 = numbers(str,pos);
      pos = s1.pos;
      if(str[s1.pos] == '(') pos++;
      State s2 = expr(str,pos);
      
      string tmp = "";
      for(int i = 0; i < s1.int_result; i++){
	tmp += s2.str_result;
	if(tmp.size() > 1000000) break;
      }
      result += tmp;
      pos = s2.pos + 1;
    }
    else if(isalpha(str[pos])){
      State s1 = alphas(str,pos);
      result += s1.str_result;
      pos = s1.pos;
    }
  }
  return State(pos,result);
}


int main(){
  string genome;
  int pos;
  while(cin >> genome >> pos){
    if(genome == "0" && pos == 0) break;
    string result = expr(genome,0).str_result;
    if(pos < result.size()){
      cout << result[pos] << endl;      
    }
    else{
      cout << 0 << endl;
    }
  }
}
