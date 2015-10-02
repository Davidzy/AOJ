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
#include <complex>
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;
 
const static int tx[] = {0,1,1,1,0,-1,-1,-1};
const static int ty[] = {-1,-1,0,1,1,1,0,-1};
 
static const double EPS = 1e-6;

int main(){
  int num_of_words;
  int num_of_pairs;
  while(~scanf("%d %d",&num_of_words,&num_of_pairs)){
    vector<string> words;
    for(int word_i = 0; word_i < num_of_words; word_i++){
      string word;
      cin >> word;
      words.push_back(word);
    }

    bool has_path[101][101] = {};
    for(int pair_i = 0; pair_i < num_of_pairs; pair_i++){
      int from, to;
      scanf("%d %d",&from,&to);
      has_path[from][to] = true;
    }
  }
}
