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

vector<string> split(string delim,string str){
  vector<string> res;
  str += delim;
  for(int i=0;i<str.size();i++){
    for(int j=1;i+j<=str.size();j++){
      if(str.substr(i,j).find(delim) != string::npos){
	if(str.substr(i,j-1).size() >0 ) res.push_back(str.substr(i,j-1));
	i+=j-1;
	break;
      }
    }
  }
  return res;
}

static const ll days_per_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int year){
  if(year % 4 == 0){
    if(year % 100 != 0) return true;
    if(year % 400 == 0) return true;
  }
  return false;
}

string maya2christ(ll passed_day){
  passed_day += 355LL;
  int year = 2012;
  for(int prev = 2012; prev < 10000000; prev++){
    if(is_leap_year(prev) && passed_day - 366LL >= 0){
      passed_day -= 366LL;
    }
    else if(!is_leap_year(prev) && passed_day - 365LL >= 0){
      passed_day -= 365LL;
    }
    else{
      break;
    }
    year = prev + 1;
  }

  int month = 1;
  for(int prev = 1; prev < 12; prev++){
    if(is_leap_year(year) && prev == 2){
      if(passed_day - (days_per_month[prev] + 1LL) >= 0){
	passed_day -= (days_per_month[prev] + 1LL);
      }
      else{
	break;
      }
    }
    else{
      if(passed_day - days_per_month[prev] >= 0){
	passed_day -= days_per_month[prev];
      }
      else{
	break;
      }
    }
    month = prev + 1;
  }  
  int day = 1;
  day += passed_day;
  stringstream ss;
  ss << year << "." << month << "." << day;
  return ss.str();
}

string christ2maya(ll passed_day){
  passed_day %= 13*20*20*18*20;
  ll b = passed_day / (20*20*18*20);
  passed_day %= (20*20*18*20);

  ll ka = passed_day / (20*18*20);
  passed_day %= (20*18*20);

  ll t = passed_day / (18*20);
  passed_day %= (18*20);

  ll w = passed_day / 20;
  passed_day %= 20;
  
  ll ki = passed_day;
  stringstream ss;
  ss << b << "." << ka << "." << t << "." << w << "." << ki;
  return ss.str();
}

ll compute_christ_passed_day(const string& str){
  vector<string> elements = split(".",str);
  ll year = atol(elements[0].c_str());
  ll month = atol(elements[1].c_str());
  ll day = atol(elements[2].c_str());
  
  ll passed_day = 0;
  for(ll prev = 2012; prev < year; prev++){
    passed_day += (is_leap_year(prev) ? 366LL : 365LL);
  }
  
  for(ll prev = 1; prev < month; prev++){
    if(is_leap_year(year) && prev == 2){
      passed_day++;
    }
    passed_day += days_per_month[prev];
  }
  for(ll prev = 1; prev < day; prev++){
    passed_day++;
  }
  passed_day -= 355LL; //2012.01.01 - 2012.12.20
  
  return passed_day;
}

ll compute_maya_passed_day(const string& str){
  vector<string> elements = split(".",str);
  ll b = atol(elements[0].c_str());
  ll ka = atol(elements[1].c_str());
  ll t = atol(elements[2].c_str());
  ll w = atol(elements[3].c_str());
  ll ki = atol(elements[4].c_str());
  
  ll passed_day = b * (20*20*18*20) + ka * (20*18*20) + t * (18*20) + w * 20 + ki;
  return passed_day;
}

int main(){
  string str;
  while(cin >> str){
    if(str == "#") break;
    int total_dots = count(str.begin(),str.end(),'.');
    if(total_dots == 2){
      //after christ
      cout << christ2maya(compute_christ_passed_day(str)) << endl;
    }
    else{
      //maya
      cout << maya2christ(compute_maya_passed_day(str)) << endl;
    }
  }
}
