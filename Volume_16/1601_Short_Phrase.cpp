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
  
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};

int main(){
  int num_word;
  while(~scanf("%d",&num_word)) {
    if (num_word == 0) break;
    
    vector<string> words;
    for (int word_i = 0; word_i < num_word; word_i++) {
      string word;
      cin >> word;
      words.push_back(word);
    }
    int res = 0;
    for (int start = 0; start < num_word; start++) {
      bool has_end[256];
      memset(has_end, 0, sizeof(has_end));
      int pos = 0;
      for (int word_i = start; word_i < num_word; word_i++) {
	pos += words[word_i].size();
	has_end[pos] = true;
      }

      if (has_end[5] && has_end[5 + 7] && has_end[5 + 7 + 5]
	  && has_end[5 + 7 + 5 + 7] && has_end[5 + 7 + 5 + 7 + 7]) {
	res = start + 1;
	break;
      }
    }
    printf("%d\n",res);
  }
}
