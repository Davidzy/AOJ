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
#include <assert.h>

using namespace std;

typedef long long ll;

static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

struct Node {
  int val;
  Node* children[2];
  double priority;
  int size;
  int range_min;
  Node(int val,double priority)
    : val(val), priority(priority),size(1),range_min(val){
    children[0] = children[1] = NULL;
  }
};

class Treap {
private:
  Node* root;

  int compute_size(Node *current) {
    return (current == NULL ? 0 : current->size);
  }

  int compute_range_min(Node *current) {
    return (current == NULL ? INF : current->range_min);
  }

  Node* update(Node *current) {
    current->size
      = compute_size(current->children[0])
      + compute_size(current->children[1]) + 1;
    current->range_min
      = min(min(compute_range_min(current->children[0]),current->val),
	    min(compute_range_min(current->children[1]),current->val));
    return current;
  }

  Node* merge(Node* lhs, Node* rhs) {
    if (lhs == NULL || rhs == NULL) {
	return (lhs == NULL ? rhs : lhs);
    }

    if (lhs->priority > rhs->priority) {
      lhs->children[1] = merge(lhs->children[1], rhs);
      return update(lhs);
    } else {
      rhs->children[0] = merge(lhs, rhs->children[0]);
      return update(rhs);
    }
  }

  pair<Node*, Node*> split(Node* current, int k) { // [0,k), [k,n)
    if(current == NULL) {
      Node* dummy = NULL;
      return make_pair(dummy, dummy);
    }
    
    if (k <= compute_size(current->children[0])) {
      pair<Node*, Node*> s = split(current->children[0], k);
      current->children[0] = s.second;
      return make_pair(s.first, update(current));
    }
    else {
      pair<Node*, Node*> s = split(current->children[1],
				   k - compute_size(current->children[0]) - 1);
      current->children[1] = s.first;
      return make_pair(update(current), s.second);
    }
  }

  Node* insert(Node* current, int k, int v) {
    pair<Node*, Node*> splitted = split(current, k);
    double priority = (double)rand() / (double)RAND_MAX;
    current = merge(splitted.first, new Node(v, priority));
    current = merge(current, splitted.second);
    return update(current);
  }

  Node* erase(Node* current, int k) {
    // lhs: [0,k+1) [k+1,n) == [0,k] [k+1,n)
    // rhs: [0,k) [k,n) == [0,k-1] [k,n)
    // [0,k-1] [k+1,n) == rhs.first lhs.second
    pair<Node*, Node*> lhs = split(current, k + 1);
    pair<Node*, Node*> rhs = split(lhs.first, k);
    return merge(rhs.first, lhs.second);
  }

  Node* find(Node* current, int k) {
    if(current == NULL) return NULL;
    assert(current != NULL);
    int lhs_size = compute_size(current->children[0]);
    if(k < lhs_size) {
      return find(current->children[0], k);
    }
    else if(k == lhs_size) {
      return current;
    }
    else {
      return find(current->children[1], k - lhs_size - 1);
    }
  }
  
  Node* shift(Node* current, int left_i, int right_i) { // [left_i,right_i]
    pair<Node*, Node*> rhs = split(current, right_i + 1); // 1st:[0,right_i] 2nd:[right_i + 1,n)
    pair<Node*, Node*> lhs = split(rhs.first, right_i); // 1st:[0,right_i-1] 2nd:[right_i,right_i]
    pair<Node*, Node*> mid = split(lhs.first, left_i); // 1st:[0,left_i-1] 2nd:[left_i,right_i-1]

    //[0,left_i-1] [right_i] [left_i,right_i-1] [right_i+1,n)
    return merge(merge(merge(mid.first,lhs.second),mid.second),rhs.second);
  }
  
  int query(Node* current, int left_i, int right_i) {
    int current_size = compute_size(current);
    if(left_i >= current_size || right_i < 0) return INF;
    if(left_i <= 0 && right_i >= current_size - 1) return compute_range_min(current);

    int lhs_size = compute_size(current->children[0]);
    return min(query(current->children[0], left_i, right_i),
	       query(current->children[1], left_i - lhs_size - 1, right_i - lhs_size - 1));
  }

public:
  Treap() {
    root = NULL;
  }

  void insert(int k, int v) {
    root = insert(root, k, v);
  }

  void erase(int k) {
    root = erase(root, k); 
  }

  int find(int k) {
    Node* node = find(root, k);
    return node->val;
  }

  void shift(int left_i, int right_i) {
    root = shift(root, left_i, right_i);
  }

  int query(int left_i, int right_i) {
    return query(root, left_i, right_i);
  }

  void disp() {
    int idx = 0;
    Node* node;
    printf("---------------\n");
    while((node = find(root, idx)) != NULL) {
      printf("%d: %d\n",idx,node->val);
      idx++;
    }
  }
};

int main(){
  int sequence_length;
  int total_queries;

  while(~scanf("%d %d",&sequence_length,&total_queries)){
    vector<int> sequence;
    Treap treap;
    for(int seq_i = 0; seq_i < sequence_length; seq_i++){
      int num;
      scanf("%d",&num);
      treap.insert(seq_i,num);
    }

    for(int query_i = 0; query_i < total_queries; query_i++){
      int command;
      int left_i;
      int right_i;
      scanf("%d %d %d",&command,&left_i,&right_i);
      if(command == 0) {
	treap.shift(left_i, right_i);
      }
      else if(command == 1) {
	printf("%d\n",treap.query(left_i, right_i));
      }
      else if(command == 2) {
	treap.erase(left_i);
	treap.insert(left_i,right_i);
      }
      // printf("command:%d\n",command);
      // treap.disp();
    }
  }
}
