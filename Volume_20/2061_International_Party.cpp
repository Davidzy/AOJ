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
#include <complex>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;

static const double EPS = 1e-12;

static const int tx[] = {+0,+1,+0,-1};
static const int ty[] = {-1,+0,+1,+0};

class UnionFindTree {
  int* _par;
  int* _rank;
public:
  UnionFindTree(int N){
    _par = new int[N];
    _rank = new int[N];
    for(int i = 0; i < N; i++){
      _par[i] = i;
      _rank[i] = 0;
    }
  }

  ~UnionFindTree(){
    delete[] _par;
    delete[] _rank;
  }

  int find(int u){
    if(_par[u] == u) return u;
    return find(_par[u]);
  }

  bool unite(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    
    if(_rank[u] < _rank[v]){
      _par[u] = v;
    }
    else{
      _par[v] = u;
      if(_rank[u] == _rank[v]) _rank[u]++;
    }
    return true;
  }
};

int main(){
  int num_of_languages;
  int num_of_students;
  bool is_first = true;
  while(~scanf("%d %d",&num_of_languages,&num_of_students)){
    if(num_of_languages == 0 && num_of_students == 0){
      break;
    }
    if(!is_first){
      printf("\n");
    }
    map<string,int> lang2idx;
    map<int,string> idx2lang;
    for(int lang_i = 0; lang_i < num_of_languages; lang_i++){
      string lang;
      cin >> lang;
      lang2idx[lang] = lang_i;
      idx2lang[lang_i] = lang;
    }

    int students[21] = {};
    for(int student_i = 0; student_i < num_of_students; student_i++){
      int num_of_skills;
      scanf("%d",&num_of_skills);
      for(int skill_i = 0; skill_i < num_of_skills; skill_i++){
	string skill;
	cin >> skill;
	students[student_i] |= (1 << lang2idx[skill]);
      }
    }

    int res = 0;


    for(int used = 1; used <= 5; used++){
      vector<int> languages;
      for(int i = 0; i < min(used,num_of_languages); i++){
	languages.push_back(1);
      }
      for(int i = 0; i < num_of_languages - used; i++){
	languages.push_back(0);
      }
      
      sort(languages.begin(),languages.end());
      do {
	int S = 0;
	for(int i = 0; i < languages.size(); i++){
	  if(languages[i] == 1){
	    S |= (1<<i);
	  }
	}
	UnionFindTree uft(30);
	for(int student_i = 0; student_i < num_of_students; student_i++){
	  for(int student_j = student_i + 1; student_j < num_of_students; student_j++){
	    if(students[student_i] & students[student_j] & S){
	      uft.unite(student_i,student_j);
	    }
	  }
	}
	
	set<int> parents;
	for(int student_i = 0; student_i < num_of_students; student_i++){
	  parents.insert(uft.find(student_i));
	}
	if(parents.size() == 1){
	  res = S;
	  goto found;
	}
      } while(next_permutation(languages.begin(),languages.end()));
    }
  found:;

    if(res != 0){
      cout << __builtin_popcount(res) << endl;
      for(int lang_i = 0; lang_i < num_of_languages; lang_i++){
	if(res & (1<<lang_i)){
	  cout << idx2lang[lang_i] << endl;
	}
      }
    }
    else{
      cout << "Impossible" << endl;
    }
    is_first = false;
  }
}
