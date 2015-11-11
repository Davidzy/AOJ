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

    bool lose[1001] = {};
    for(int player_i = 0; player_i < num_of_players; player_i++){
      for(int player_j = 0; player_j < num_of_players; player_j++){
	if(player_i == player_j) continue;
	
	for(int offset = 1; offset <= 7; offset++){
	  if(dict[players[player_j]] == (dict[players[player_i]] + offset) % 15){
	    lose[player_j] = true;
	  }
	}
      }
    }

    string res = "Draw";
    for(int player_i = 0; player_i < num_of_players; player_i++){
      if(!lose[player_i]){
	res = players[player_i];
	break;
      }
    }
    cout << res << endl;
  }
}
