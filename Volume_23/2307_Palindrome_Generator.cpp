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

int dp[101][101][1001];

bool is_palindrome(const string& str){
  for(int i = 0; i < str.size() / 2; i++){
    if(str[i] != str[str.size() - i - 1]){
      return false;
    }
  }
  return true;
}

void connect(const vector<string>& words,
	     vector<int> forward_connection[101],
	     vector<int> backward_connection[101],
	     int word_i, int word_j, int remaining){
  // add to left side
  if(remaining > 0){
    for(int i = 0; i < backward_connection[word_i].size(); i ++){
      string front = words[word_j];
      string rear = words[backward_connection[word_i][i]];

      string other_side = front.substr(front.size() - remaining,remaining);
      string add_side = rear.substr(rear.size() - remaining,remaining);
      cout << is_palindrome(add_side + other_side) << endl;
    }
  }

  // add to right side
  else {
    for(int i = 0; i < forward_connection[word_j].size(); i ++){
      string front = words[forward_connection[word_j][i]];
      string rear = words[word_i];

      string other_side = front.substr(front.size() - remaining,remaining);
      string add_side = rear.substr(rear.size() - remaining,remaining);
      cout << is_palindrome(add_side + other_side) << endl;
    }
  }
}

int main(){
  int num_of_words;
  int num_of_pairs;
  while(~scanf("%d %d",&num_of_words,&num_of_pairs)){
    memset(dp,-1,sizeof(dp));

    vector<string> words;
    for(int word_i = 0; word_i < num_of_words; word_i++){
      string word;
      cin >> word;
      words.push_back(word);
    }
    
    vector<int> forward_connection[101];
    vector<int> backward_connection[101];
    for(int pair_i = 0; pair_i < num_of_pairs; pair_i++){
      int from, to;
      scanf("%d %d",&from,&to);
      from--; to--;
      forward_connection[from].push_back(to);
      backward_connection[to].push_back(from);
    }

    for(int i = 0; i < words.size(); i++){
      
    }
  }
}
