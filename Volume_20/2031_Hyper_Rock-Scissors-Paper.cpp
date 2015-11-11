#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
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
typedef pair <int,P > PP;
 
const static int tx[] = {0,1,0,-1};
const static int ty[] = {-1,0,1,0};

const static double EPS = 1e-8;

int main(){
  int num_of_players;
  map<string,int> dict;
  dict["Rock"] = 0;
  dict["Fire"] = 1;
  dict["Scissors"] = 2;
  dict["Snake"] = 3;
  dict["Human"] = 4;
  dict["Tree"] = 5;
  dict["Wolf"] = 6;
  dict["Sponge"] = 7;
  dict["Paper"] = 8;
  dict["Air"] = 9;
  dict["Water"] = 10;
  dict["Dragon"] = 11;
  dict["Devil"] = 12;
  dict["Lightning"] = 13;
  dict["Gun"] = 14;

  map<int,bool> canWin;
  for(int hand_i = 0; hand_i < 15; hand_i++){
    for(int hand_j = 0; hand_j < 15; hand_j++){
      canWin[hand_i * 15 + hand_j] = false;
      for(int offset = 1; offset <= 7; offset++){
	if(hand_j == (hand_i + offset) % 15){
	  canWin[hand_i * 15 + hand_j] = true;
	}
      }
    }
  }

  while(~scanf("%d",&num_of_players)){
    if(num_of_players == 0){
      break;
    }
    vector<string> players;
    for(int player_i = 0; player_i < num_of_players; player_i++){
      string hand;
      cin >> hand;
      players.push_back(hand);
    }

    map<string,bool> lose;
    map<string,bool> win;

    set<string> hands;
    for(int player_i = 0; player_i < num_of_players; player_i++){
      hands.insert(players[player_i]);
    }
    for(set<string>::iterator ally_it = hands.begin(); ally_it != hands.end(); ally_it++){
      for(set<string>::iterator foe_it = hands.begin(); foe_it != hands.end(); foe_it++){
	if(canWin[dict[*ally_it] * 15 + dict[*foe_it]]){
	  win[*ally_it] = true;
	  lose[*foe_it] = true;
	}
      }
    }

    string res = "Draw";
    for(set<string>::iterator ally_it = hands.begin(); ally_it != hands.end(); ally_it++){
      if(win[*ally_it] && !lose[*ally_it]){
	res = *ally_it;
      }
    }
    printf("%s\n",res.c_str());
  }
}
