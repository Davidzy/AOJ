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

vector<string> candidates;

int dfs(int pos,int used,const string& encrypted,string current){
  if(pos == encrypted.size()){
    candidates.push_back(current);
    return 1;
  }
  int res = 0;
  for(int offset = 0; offset <= 1; offset++){
    if(encrypted[pos] == 'z' && offset == 1) continue;
    if(offset == 0){
      if(encrypted[pos] != 'a' 
	 && !(used & (1 << ((encrypted[pos] + offset) - 'a')))) continue;
      res += dfs(pos + 1,used,encrypted,current + (char)(encrypted[pos] + offset));
    }
    else if(offset == 1){
      if(used & (1 << ((encrypted[pos] + offset) - 'a'))) continue;
      res += dfs(pos + 1,used | (1 << ((encrypted[pos] + offset) - 'a')),encrypted,current + (char)(encrypted[pos] + offset));
    }
  }
  return res;
}

int main(){
  string str;
  while(cin >> str){
    if(str == "#") break;
    candidates.clear();
    printf("%d\n",dfs(0,0,str,""));
    sort(candidates.begin(),candidates.end());
    if(candidates.size() > 10){
      for(int i = 0; i < 5; i++){
	cout << candidates[i] << endl;
      }
      for(int i = candidates.size() - 5; i < candidates.size(); i++){
	cout << candidates[i] << endl;
      }
    }
    else{
      for(int i = 0; i < candidates.size(); i++){
	cout << candidates[i] << endl;
      }
    }
  }
}
