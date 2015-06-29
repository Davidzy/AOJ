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

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

ll mod_inverse(ll a, ll m){
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

pair<ll, ll> linear_congruence(const vector<ll>& A, const vector<ll>& B,
				 const vector<ll>& M) {
  ll x = 0, m = 1;
  for(ll i = 0; i < A.size(); i++){
    if(B[i] == -1) continue;
    ll a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
    if(b % d != 0) return make_pair(0, -1);
    ll t = b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d);
    x = x + m * t;
    m *= M[i] / d;
  }
  return make_pair(x % m, m);
}

int main(){
  ll num_of_chopsticks;
  int num_of_divisors;
  int total_days;
  while(~scanf("%lld %d %d",
	       &num_of_chopsticks,
	       &num_of_divisors,
	       &total_days)){
    vector<ll> divisors(num_of_divisors);
    for(int div_i = 0; div_i < num_of_divisors; div_i++){
      scanf("%lld",&divisors[div_i]);
    }
    ll record[101][11];
    for(int day = 0; day < total_days; day++){
      for(int div_i = 0; div_i < num_of_divisors; div_i++){
	scanf("%lld",&record[day][div_i]);
      }
    }

    vector<ll> A(num_of_divisors,1);
    for(int day = 0; day < total_days; day++){
      vector<ll> reminder;
      for(int div_i = 0; div_i < num_of_divisors; div_i++){
	reminder.push_back(record[day][div_i]);
      }

      pair<ll,ll> ans = linear_congruence(A,reminder,divisors);
      num_of_chopsticks -= (num_of_chopsticks - ans.first + ans.second) % ans.second;
      if(num_of_chopsticks < 0 || ans.second == -1){
      	num_of_chopsticks = -1;
	break;
      }
    }
    printf("%lld\n",num_of_chopsticks);
  }
}
