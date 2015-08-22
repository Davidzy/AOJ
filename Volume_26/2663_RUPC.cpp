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
typedef pair <double,double> P;
typedef pair <int,P> PP;
   
static const double EPS = 1e-12;
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int num_of_problems;

  while(~scanf("%d",&num_of_problems)){
    vector<int> problems;
    for(int problem_i = 0; problem_i < num_of_problems; problem_i++){
      int problem;
      scanf("%d",&problem);
      problems.push_back(problem);
    }
    int sum[300001] = {};
    sort(problems.begin(),problems.end());
    for(int problem_i = 0; problem_i < num_of_problems; problem_i++){
      sum[problem_i + 1] += sum[problem_i] + problems[problem_i];
    }

    int num_of_participants;
    scanf("%d",&num_of_participants);

    int abilities[300000];
    for(int participant_i = 0; participant_i < num_of_participants; participant_i++){
      int ability;
      scanf("%d",&ability);
      abilities[participant_i] = ability;
    }

    int targets[300000];
    for(int participant_i = 0; participant_i < num_of_participants; participant_i++){
      int target;
      scanf("%d",&target);
      targets[participant_i] = target;
    }
    for(int participant_i = 0; participant_i < num_of_participants; participant_i++){
      int solved = upper_bound(problems.begin(),problems.end(),abilities[participant_i]) - problems.begin() - 1;
      printf("%s\n",(sum[solved + 1] >= targets[participant_i]) ? "Yes" : "No");
    }
  }
}
