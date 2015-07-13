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
  int normal_fare;
  int ic_fare;
  int ic_price;
  City(int normal_fare,int ic_fare,int ic_price){
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
    for(int city_i = 0; city_i < total_cities; city_i++){
      int normal_fare;
      int ic_fare;
      int ic_price;
      scanf("%d %d %d",&normal_fare,&ic_fare,&ic_price);
      cities.push_back(City(normal_fare,ic_fare,ic_price));
    }
  }
}
