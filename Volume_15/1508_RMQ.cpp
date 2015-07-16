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
  int sub_tree_size;
  int sub_tree_sum;
  Node(int val,double priority)
    : val(val), priority(priority),sub_tree_size(1),sub_tree_sum(val){
    children[0] = children[1] = NULL;
  }
};

class Treap {
public:
  Node* update(Node *current){
    current->sub_tree_size
      = compute_size(current->children[0])
      + compute_size(current->children[1]) + 1;
    current->sub_tree_sum
      = compute_sum(current->children[0])
      + compute_sum(current->children[1]);
    return current;
  }
private:
  int compute_size(Node *current) {
    return (current == NULL ? 0 : current->sub_tree_size);
  }
  int compute_sum(Node *current) {
    return (current == NULL ? 0 : current->sub_tree_sum);
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

  pair<Node*, Node*> split(Node* current, int k){
    if(current == NULL) {
      Node* dummy = NULL;
      return make_pair(dummy, dummy);
    }
    
    if(k <= compute_size(current->children[0])){
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
};

int main(){
  int sequence_length;
  int total_queries;
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
