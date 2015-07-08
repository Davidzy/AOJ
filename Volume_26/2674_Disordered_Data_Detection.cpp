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

class SegmentTree {
private:
  int mSize;
  vector<int> scores[100001];
public:
  SegmentTree(int n) {
    mSize = 1;
    while(mSize < n) mSize *= 2;
  }

  int getSize() const{
    return mSize;
  } 

  void insert(const vector<int>& sequence){
    for(int i = mSize - 1,j=0; i < mSize * 2 - 1; i++,j++){
      int score = INF;
      if(j < sequence.size()){
	score = sequence[j];
      }
      scores[i].push_back(score);
      int idx = i;
      while(idx > 0){
    	idx = (idx - 1) / 2;
	scores[idx].push_back(score);
	sort(scores[idx].begin(),scores[idx].end());
      }
    }
  }

  int query(int left_i,int right_i,int current_idx,int current_lhs,int current_rhs,int min_v,int max_v){
    if(current_rhs <= left_i || right_i <= current_lhs){
      return 0;
    }
    if(left_i <= current_lhs && current_rhs <= right_i) {
      int upper = upper_bound(scores[current_idx].begin(),scores[current_idx].end(),max_v) - scores[current_idx].begin();
      int lower = lower_bound(scores[current_idx].begin(),scores[current_idx].end(),min_v) - scores[current_idx].begin();
      int unused = scores[current_idx].end() - lower_bound(scores[current_idx].begin(),scores[current_idx].end(),INF);
      return scores[current_idx].size() - (upper - lower) - unused;
    }
    else {
      int vl = query(left_i,right_i,current_idx * 2 + 1, current_lhs, (current_lhs + current_rhs) / 2, min_v, max_v);
      int vr = query(left_i,right_i,current_idx * 2 + 2, (current_lhs + current_rhs) / 2, current_rhs, min_v, max_v);
      return vl + vr;
    }
  }
};

int main(){
  int sequence_length;
  while(~scanf("%d",&sequence_length)){
    vector<int> sequence;
    for(int seq_i = 0; seq_i < sequence_length; seq_i++){
      int x;
      scanf("%d",&x);
      sequence.push_back(x);
    }

    SegmentTree seg_tree(sequence_length);
    seg_tree.insert(sequence);

    int total_queries;
    scanf("%d",&total_queries);
    for(int query_i = 0; query_i < total_queries; query_i++){
      int left_i;
      int right_i;
      int offset;
      scanf("%d %d %d",&left_i,&right_i,&offset);
      left_i--;
      right_i--;
      int max_v = max(sequence[left_i],sequence[right_i]) + offset;
      int min_v = min(sequence[left_i],sequence[right_i]) - offset;
      int n = seg_tree.getSize() - 1;
      printf("%d\n",seg_tree.query(left_i,right_i,0,0,n,min_v,max_v));
    }
  }
}
