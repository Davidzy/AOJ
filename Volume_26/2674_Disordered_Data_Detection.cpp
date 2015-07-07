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
  multiset<int>* scores;
public:
  SegmentTree(int n) {
    mSize = 1;
    while(mSize < n) mSize *= 2;
    scores = new multiset<int>[mSize];
  }

  ~SegmentTree(){
    delete[] scores;
  }

  void insert(const vector<int>& sequence_length){
    for(int i = mSize - 1,j=0; i < mSize * 2 + 1; i++,j++){
      scores[i].insert(sequence_length[j]);
    }
    for(int tmp_idx = mSize - 1; tmp_idx < mSize * 2 + 1; tmp_idx++){
      int idx = tmp_idx;
      while(idx > 0){
	cout << "hoge" << endl;
    	idx = (idx - 1) / 2;
    	int lhs = idx * 2 + 1;
    	int rhs = idx * 2 + 2;
    	for(multiset<int>::iterator it = scores[lhs].begin();
    	    it != scores[lhs].end();
    	    it++){
    	  scores[idx].insert(*it);
    	}
    	for(multiset<int>::iterator it = scores[rhs].begin();
    	    it != scores[rhs].end();
    	    it++){
    	  scores[idx].insert(*it);
    	}
      }
    }
  }

  void query(int idx){
    for(multiset<int>::iterator it = scores[idx].begin();
	it != scores[idx].end();
	it++){
      cout << *it << endl;
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
    // seg_tree.query(0);

    int total_queries;
    scanf("%d",&total_queries);
    for(int query_i = 0; query_i < total_queries; query_i++){
      int left_i;
      int right_i;
      int offset;
      scanf("%d %d %d",&left_i,&right_i,&offset);
      left_i--;
      right_i--;
      int max_v = max(sequence[left_i],sequence[right_i]);
      int min_v = min(sequence[left_i],sequence[right_i]);
      int count = 0;
      for(int seq_i = left_i; seq_i <= right_i; seq_i++){
	if(sequence[seq_i] < min_v - offset
	   || max_v + offset < sequence[seq_i]){
	  count++;
	}
      }
      printf("%d\n",count);
    }
  }
}
