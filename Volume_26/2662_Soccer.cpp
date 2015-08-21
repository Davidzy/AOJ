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
   
static const double EPS = 1e-8;
   
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

class Player {
public:
  int frame;
  int back_number;
  int team;
  int x,y;
  Player(int frame, int back_number, int team, int x, int y)
    : frame(frame), back_number(back_number), team(team), x(x), y(y) {}
};

bool equals(double lhs,double rhs){
  return (lhs <= rhs + EPS && lhs >= rhs - EPS);
}

P calc(vector<Player> players){
  int time = INF;
  double distance = -1;
  for(int player_i = 0; player_i + 1 < players.size(); player_i++){
    if(players[player_i].team != players[player_i + 1].team) continue;
    if(players[player_i].back_number == players[player_i + 1].back_number) continue;
    double tmp;
    if((tmp = sqrt((double)(players[player_i].x - players[player_i + 1].x) * (players[player_i].x - players[player_i + 1].x)
		   + (double)(players[player_i].y - players[player_i + 1].y) * (players[player_i].y - players[player_i + 1].y))) < distance) continue;
    
    // equal
    if(equals(tmp,distance)){
      if(time > (players[player_i + 1].frame - players[player_i].frame)){
	time = players[player_i + 1].frame - players[player_i].frame;
	distance = tmp;
      }
      continue;
    }
    // larger
    else {
      time = players[player_i + 1].frame - players[player_i].frame;
      distance = tmp;
    }
  }

  if(time == INF){
    return P(-1, -1);
  }
  else{
    return P(distance,(double)time/60.0);
  }
}

int main()
{
  int num_of_frames;
  while(~scanf("%d",&num_of_frames)){
    vector<Player> players[2];
    for(int frame_i = 0; frame_i < num_of_frames; frame_i++){
      int frame;
      int back_number;
      int team;
      int x,y;
      scanf("%d %d %d %d %d",&frame,&back_number,&team,&x,&y);
      players[team].push_back(Player(frame,back_number,team,x,y));
    }
    P team_A = calc(players[0]);
    P team_B = calc(players[1]);
    if(equals(team_A.first,-1)){
      printf("%d %d\n",-1,-1);
    }
    else{
      printf("%.8lf %.8lf\n",team_A.first,team_A.second);
    }
    if(equals(team_B.first,-1)){
      printf("%d %d\n",-1,-1);
    }
    else{
      printf("%.8lf %.8lf\n",team_B.first,team_B.second);
    }
  }
}
