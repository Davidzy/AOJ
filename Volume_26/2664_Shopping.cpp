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

class UnionFindTree {
private:
  int* par;
  int* rank;
  int* weight;
public:
  UnionFindTree(int n){
    par = new int[n]();
    rank = new int[n]();
    weight = new int[n]();
    for(int i=0;i<n;i++){
      par[i] = i;
      rank[i] = 0;
      weight[i] = 1;
    }
  }

  ~UnionFindTree(){
    delete[] rank;
    delete[] par;
    delete[] weight;
  }

  int find(int x){
    if(par[x] == x){
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if (x == y) return;

    if(rank[x] < rank[y]){
      par[x] = y;
      weight[y] += weight[x];
    } else {
      par[y] = x;
      weight[x] += weight[y];
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  int count(int x){
    return weight[find(x)];
  }
  bool same(int x,int y){
    return find(x) == find(y);
  }
};

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
    int min_cost[5001];
    memset(min_cost,0x3f,sizeof(min_cost));

    map<string,int> dict;
    for(int food_stuff_i = 0; food_stuff_i < num_of_foodstuffs; food_stuff_i++){
      string name;
      int price;
      cin >> name >> price;
      prices[name2idx(dict,name)] = price;
      min_cost[name2idx(dict,name)] = price;
    }
    int num_of_magics;
    scanf("%d",&num_of_magics);

    UnionFindTree uft(5001);
    for(int magic_i = 0; magic_i < num_of_magics; magic_i++){
      string from_food, to_food;
      cin >> from_food >> to_food;
      uft.unite(name2idx(dict,from_food),name2idx(dict,to_food));
      if(min_cost[uft.find(name2idx(dict,from_food))]
	 > min(prices[name2idx(dict,from_food)],prices[name2idx(dict,to_food)])){
	min_cost[uft.find(name2idx(dict,from_food))]
	  = min(prices[name2idx(dict,from_food)],prices[name2idx(dict,to_food)]);
      }
    }

    int res = 0;
    for(int food_stuff_i = 0; food_stuff_i < num_of_foodstuffs; food_stuff_i++){
      res += min_cost[uft.find(food_stuff_i)];
    }
    printf("%d\n",res);
  }
}
