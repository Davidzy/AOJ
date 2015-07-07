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
  multiset<int> scores[100001];
public:
  SegmentTree(int n) {
    mSize = 1;
    while(mSize < n) mSize *= 2;
  }

  void insert(const vector<int>& sequence_length){
    for(int i = mSize - 1,j=0; i < mSize * 2 - 1; i++,j++){
      scores[i].insert(sequence_length[j]);
      int idx = i;
      while(idx > 0){
    	idx = (idx - 1) / 2;
	scores[idx].insert(sequence_length[j]);
      }
    }
  }

  void query(int idx){
    cout << "ore" << endl;
    for(multiset<int>::iterator it = scores[idx].begin();
	it != scores[idx].end();
	it++){
      cout << *it << endl;
    }
    cout << "ore" << endl;
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
    seg_tree.query(0);

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
