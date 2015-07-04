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

class Duration {
public:
  int from;
  int to;
  Duration(int hour[2],int minute[2]){
    from = hour[0] * 60 + minute[0];
    to = hour[1] * 60 + minute[1];
  }
  
  bool contains(Duration t){
    if(t.from < from || t.to > to) return false;
    return true;
  }
};

int main(){
  int total_lectures;
  while(~scanf("%d",&total_lectures)){
    vector<Duration> lectures;
    for(int lecture_i = 0; lecture_i < total_lectures; lecture_i++){
      int hour[2];
      int minute[2];
      scanf("%d:%d-%d:%d",&hour[0],&minute[0],&hour[1],&minute[1]);
      lectures.push_back(Duration(hour,minute));
    }

    int total_teachers;
    scanf("%d",&total_teachers);
    vector<Duration> teachers[101];
    for(int teacher_i = 0; teacher_i < total_teachers; teacher_i++){
      int num_of_spare_times;
      scanf("%d",&num_of_spare_times);
      for(int spare_i = 0; spare_i < num_of_spare_times; spare_i++){
	int hour[2];
	int minute[2];
	scanf("%d:%d-%d:%d",&hour[0],&minute[0],&hour[1],&minute[1]);
	teachers[teacher_i].push_back(Duration(hour,minute));
      }
    }
    int total_students;
    scanf("%d",&total_students);
    vector<Duration> students[101];
    for(int student_i = 0; student_i < total_students; student_i++){
      int num_of_spare_times;
      scanf("%d",&num_of_spare_times);
      for(int spare_i = 0; spare_i < num_of_spare_times; spare_i++){
	int hour[2];
	int minute[2];
	scanf("%d:%d-%d:%d",&hour[0],&minute[0],&hour[1],&minute[1]);
	students[student_i].push_back(Duration(hour,minute));
      }
    }

    int res = 0;
    for(int lecture_i = 0; lecture_i < total_lectures; lecture_i++){
      
      int teacher_available_count = 0;
      for(int teacher_i = 0; teacher_i < total_teachers; teacher_i++){
	for(int duration_i = 0; duration_i < teachers[teacher_i].size(); duration_i++){
	  if(teachers[teacher_i][duration_i].contains(lectures[lecture_i])){
	    teacher_available_count++;
	  }
	}
      }

      int student_available_count = 0;
      for(int student_i = 0; student_i < total_students; student_i++){
	for(int duration_i = 0; duration_i < students[student_i].size(); duration_i++){
	  if(students[student_i][duration_i].contains(lectures[lecture_i])){
	    student_available_count++;
	  }
	}
      }

      res += min(teacher_available_count,student_available_count);
    }
    printf("%d\n",res);
  }
}
