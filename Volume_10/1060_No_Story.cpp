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

bool is_prime[1000001];

vector<ll> compute_factors(ll target_num){
  vector<ll> res;
  for(ll i = 2; i * i <= target_num; i++){
    if(!is_prime[i]) continue;
    if(target_num % i == 0){
      int count = 0;
      while(target_num % i == 0){
	target_num /= i;
	count++;
      }
      res.push_back(count);
    }
  }

  if(target_num != 1){
    res.push_back(1);
  }
  return res;
}

ll count_combination(const vector<ll>& factors,vector<ll>& current){
  if(current.size() == factors.size()){
    ll tmp = 1;
    for(int i = 0; i < factors.size(); i++){
      if(factors[i] == current[i]){
	tmp *= factors[i] + 1;
      }
    }
    return tmp;
  }

  ll res = 0;
  for(int i = 0; i <= factors[current.size()]; i++){
    current.push_back(i);
    res += count_combination(factors,current);
    current.pop_back();
  }
  return res;
}

int main(){
  memset(is_prime,true,sizeof(is_prime));
  is_prime[0] = false;
  is_prime[1] = false;
  for(ll i = 2; i * i <= 1000000000000; i++){
    if(is_prime[i]){
      for(ll j = i + i; j <= 1000000; j += i){
	is_prime[j] = false;
      }
    }
  }

  ll target_num;
  while(~scanf("%lld",&target_num)){
    if(target_num == 0) break;
    vector<ll> factors = compute_factors(target_num);
    vector<ll> current;
    printf("%lld\n",(count_combination(factors,current) + 1) / 2);
  }
}
