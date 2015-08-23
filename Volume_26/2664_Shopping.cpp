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
typedef pair <double,double> P;
typedef pair <int,P> PP;
   
static const double EPS = 1e-12;
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int name2idx(map<string,int>& dict, string name){
  if(dict.find(name) == dict.end()){
    int res = dict.size();
    dict[name] = res;
    return res;
  }
  return dict[name];
}

int main(){
  int num_of_foodstuffs;
  while(~scanf("%d",&num_of_foodstuffs)){
    int prices[5001] = {};
    map<string,int> dict;
    for(int food_stuff_i = 0; food_stuff_i < num_of_foodstuffs; food_stuff_i++){
      string name;
      int price;
      cin >> name >> price;
      prices[name2idx(dict,name)] = price;
    }
    int num_of_magics;
    scanf("%d",&num_of_magics);
    vector<int> trans[5001];
    for(int magic_i = 0; magic_i < num_of_magics; magic_i++){
      string from_food, to_food;
      cin >> from_food >> to_food;
      trans[name2idx(dict,from_food)].push_back(name2idx(dict,to_food));
      trans[name2idx(dict,to_food)].push_back(name2idx(dict,from_food));
    }
  }
}
