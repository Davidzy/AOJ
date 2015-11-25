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

int main(){
  int num_of_languages;
  int num_of_students;
  while(~scanf("%d %d",&num_of_languages,&num_of_students)){
    if(num_of_languages == 0 && num_of_students == 0){
      break;
    }

    map<string,int> dict;
    for(int lang_i = 0; lang_i < num_of_languages; lang_i++){
      string lang;
      cin >> lang;
      dict[lang] = lang_i;
    }

    vector<int> students[21];
    for(int student_i = 0; student_i < num_of_students; student_i++){
      int num_of_skills;
      for(int skill_i = 0; skill_i < num_of_skills; skill_i++){
	string skill;
	cin >> skill;
	students[student_i].push_back(dict[skill]);
      }
    }
  }
}
