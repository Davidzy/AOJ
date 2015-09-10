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
typedef pair <int,vector<int> > P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

vector<int> compute_union(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    tmp.insert(A[i]);
  }
  for(int i = 0; i < B.size(); i++){
    tmp.insert(B[i]);
  }
  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_intersection(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    for(int j = 0; j < B.size(); j++){
      if(A[i] == B[j]){
	tmp.insert(A[i]);
      }
    }
  }
  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_difference(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    bool isok = true;
    for(int j = 0; j < B.size(); j++){
      if(A[i] == B[j]){
	isok = false;
      }
    }
    if(isok){
      tmp.insert(A[i]);
    }
  }

  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_symmetric_difference(const vector<int>& A,const vector<int>& B){
  vector<int> intersection = compute_intersection(A,B);
  vector<int> diff_a = compute_difference(A,intersection);
  vector<int> diff_b = compute_difference(B,intersection);
  return compute_union(diff_a,diff_b);
}

vector<int> compute_complement(const vector<int>& A,const vector<int>& U){
  vector<int> intersection = compute_intersection(A,U);
  return compute_difference(U,intersection);
}

P equation(const string& str,vector<int> numbers[256],const vector<int>& U, int pos);
P factor(const string& str,vector<int> numbers[256],const vector<int>& U, int pos);
P term(const string& str,vector<int> numbers[256],const vector<int>& U, int pos);

P equation(const string& str,vector<int> numbers[256],const vector<int>& U, int pos){
  return factor(str,numbers,U,pos);
}

P factor(const string& str,vector<int> numbers[256],const vector<int>& U, int pos){
  P r1 = term(str,numbers,U,pos);
  pos = r1.first;
  vector<int> current_set = r1.second;
  while(1){
    if(pos >= str.size()){
      break;
    }
    if(str[pos] == 'u'){
      P r2 = term(str,numbers,U,pos+1);
      current_set = compute_union(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 'i'){
      P r2 = term(str,numbers,U,pos+1);
      current_set = compute_intersection(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 'd'){
      P r2 = term(str,numbers,U,pos+1);
      current_set = compute_difference(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 's'){
      P r2 = term(str,numbers,U,pos+1);
      current_set = compute_symmetric_difference(current_set,r2.second);
      pos = r2.first;
    }
    else{
      break;
    }
  }
  return P(pos,current_set);
}

P term(const string& str,vector<int> numbers[256],const vector<int>& U, int pos){
  if(str[pos] == '('){
    P r = equation(str,numbers,U,pos+1);
    pos = r.first;
    pos++;
    return P(pos,r.second);
  }
  else if(str[pos] == 'c'){
    P r = term(str,numbers,U,pos+1);
    vector<int> current_set = compute_complement(r.second,U);
    return P(r.first,current_set);
  }
  else if(str[pos] == 'A' || str[pos] == 'B'
	  || str[pos] == 'C' || str[pos] == 'D'
	  || str[pos] == 'E'){
    return P(pos+1,numbers[str[pos]]);
  }
}

int main(){
  while(!cin.eof()){
    char alphabet[2];
    int num_of_elements;
    vector<int> numbers[256];
    vector<int> U;
    while(~scanf("%s %d",alphabet,&num_of_elements)){
      if(alphabet[0] == 'R' && num_of_elements == 0){
	goto skip;
      }
      
      for(int element_i = 0; element_i < num_of_elements; element_i++){
	int num;
	scanf("%d",&num);
	numbers[alphabet[0]].push_back(num);
      }
      U = compute_union(numbers[alphabet[0]],U);
    }
  skip:;
    string text;
    cin >> text;
    P r = equation(text,numbers,U,0);
    vector<int> result = r.second;
    for(int i = 0; i < result.size(); i++){
      printf("%s%d", i == 0 ? "" : " ", i);
    }
    printf("\n");
  }
}
