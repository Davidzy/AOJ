#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
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
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  char alphabet[2];
  int num_of_elements;
  vector<int> numbers[256];  
  while(~scanf("%s %d",alphabet,&num_of_elements)){

    if(alphabet[0] == 'R' && num_of_elements == 0){
      goto skip;
    }
    
    for(int element_i = 0; element_i < num_of_elements; element_i++){
      int num;
      scanf("%d",&num);
      numbers[alphabet[0]].push_back(num);
    }
  skip:;
    string equation;
    cin >> equation;

    for(int i = 0; i < 256; i++){
      numbers[i].clear();
    }
  }
}
