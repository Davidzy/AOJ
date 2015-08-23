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
  int* price;
public:
  UnionFindTree(vector<int> prices){
    int n = prices.size();
    par = new int[n]();
    rank = new int[n]();
    price = new int[n]();
    for(int i = 0; i < n; i++){
      par[i] = i;
      rank[i] = 0;
      price[i] = prices[i];
    }
  }

  ~UnionFindTree(){
    delete[] rank;
    delete[] par;
    delete[] price;
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
      price[y] = min(price[x],price[y]);
    } else {
      par[y] = x;
      price[x] = min(price[x],price[y]);
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  int get_min_price(int x){
    return price[find(x)];
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
    map<string,int> dict;
    vector<int> prices;
    for(int food_stuff_i = 0; food_stuff_i < num_of_foodstuffs; food_stuff_i++){
      string name;
      int price;
      cin >> name >> price;

      // for later str2idx process
      name2idx(dict,name);

      prices.push_back(price);
    }
    int num_of_magics;
    scanf("%d",&num_of_magics);

    UnionFindTree uft(prices);
    for(int magic_i = 0; magic_i < num_of_magics; magic_i++){
      string from_food, to_food;
      cin >> from_food >> to_food;
      uft.unite(name2idx(dict,from_food),name2idx(dict,to_food));
    }

    int res = 0;
    for(int food_stuff_i = 0; food_stuff_i < num_of_foodstuffs; food_stuff_i++){
      res += uft.get_min_price(food_stuff_i);
    }
    printf("%d\n",res);
  }
}
