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
  
static const double EPS = 1e-8;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

class City{
public:
  ll normal_fare;
  ll ic_fare;
  ll ic_price;
  City(ll normal_fare,ll ic_fare,ll ic_price){
    this->normal_fare = normal_fare;
    this->ic_fare = ic_fare;
    this->ic_price = ic_price;
  }
};

int main(){
  int total_cities;
  int travel_period;
  while(~scanf("%d %d",&total_cities,&travel_period)){
    vector<int> route;
    for(int day = 0; day < travel_period; day++){
      int city;
      scanf("%d",&city);
      city--;
      route.push_back(city);
    }
    
    vector<City> cities;
    for(int city_i = 0; city_i < total_cities - 1; city_i++){
      ll normal_fare;
      ll ic_fare;
      ll ic_price;
      scanf("%lld %lld %lld",&normal_fare,&ic_fare,&ic_price);
      cities.push_back(City(normal_fare,ic_fare,ic_price));
    }
    ll count[100001] = {};
    for(int route_i = 0; route_i + 1 < route.size(); route_i++){
      int from = route[route_i];
      int to = route[route_i + 1];
      if(from < to){
	count[from]++;
	count[to]--;
      }
      else{
	count[to]++;
	count[from]--;
      }
    }

    ll res = 0;
    int sum = 0;
    for(int city_i = 0; city_i < total_cities - 1; city_i++){
      sum += count[city_i];
      res += min(sum * cities[city_i].normal_fare,
		 sum * cities[city_i].ic_fare + cities[city_i].ic_price);
    }
    printf("%lld\n",res);
  }
}
