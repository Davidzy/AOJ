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

class Query {
public:
  int command;
  int left_i;
  int right_i;
  Query(int command, int left_i, int right_i){
    this->command = command;
    this->left_i = left_i;
    this->right_i = right_i;
  }
};

struct Node {
  int val;
  Node* children[2];
  double priority;
  int size;
  int val_sum;
  Node(int val,double priority)
    : val(val), priority(priority),size(1),val_sum(val){
    children[0] = children[1] = NULL;
  }
};

class Treap {
private:
  Node* root;

  int compute_size(Node *current) {
    return (current == NULL ? 0 : current->size);
  }

  int compute_sum(Node *current) {
    return (current == NULL ? 0 : current->val_sum);
  }

  Node* update(Node *current) {
    current->size
      = compute_size(current->children[0])
      + compute_size(current->children[1]) + 1;
    current->val_sum
      = compute_sum(current->children[0])
      + compute_sum(current->children[1]) + current->val;
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
    assert(current != NULL);
    int current_size = compute_size(current->children[0]);
    if(k < current_size) {
      return find(current->children[0], k);
    }
    else if(k == current_size) {
      return current;
    }
    else {
      return find(current->children[1], k - current_size - 1);
    }
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
};

int main(){
  int sequence_length;
  int total_queries;
  Treap treap;
  treap.insert(0,1);
  treap.insert(1,22);
  treap.insert(2,101010);
  treap.insert(5,27);
  cout << treap.find(0) << endl;
  cout << treap.find(1) << endl;
  cout << treap.find(2) << endl;
  cout << treap.find(3) << endl;
  cout << "------" << endl;
  treap.erase(3);
  cout << treap.find(0) << endl;
  cout << treap.find(1) << endl;
  cout << treap.find(2) << endl;
  cout << treap.find(3) << endl;

  while(~scanf("%d %d",&sequence_length,&total_queries)){
    vector<int> sequence;
    for(int seq_i = 0; seq_i < sequence_length; seq_i++){
      int num;
      scanf("%d",&num);
      sequence.push_back(num);
    }

    vector<Query> queries;
    for(int query_i = 0; query_i < total_queries; query_i++){
      int command;
      int left_i;
      int right_i;
      scanf("%d %d %d",&command,&left_i,&right_i);
      queries.push_back(Query(command,left_i,right_i));
    }
  }
}
