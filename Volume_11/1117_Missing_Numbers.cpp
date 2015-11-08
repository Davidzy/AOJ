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
 
int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};
 
static const double EPS = 1e-8;

int main(){

  int num_of_rows,num_of_cols;
  bool is_first = true;
  while(~scanf("%d",&num_of_rows)){
    if(num_of_rows == 0) break;

    scanf("%d",&num_of_cols);
    int table[101][101];
    vector<P> masks;
    for(int row = 0; row < num_of_rows + 1; row++){
      for(int col = 0; col < num_of_cols + 1; col++){
	char val[32];
	scanf("%s",val);
	if(val[0] == '?'){
	  table[row][col] = 5000000;
	  masks.push_back(P(row,col));
	}
	else{
	  table[row][col] = atoi(val);
	}
      }
    }

    bool visited[101] = {};
    for(int round = 0; round < 100; round++){
      for(int mask_i = 0; mask_i < masks.size(); mask_i++){
	if(visited[mask_i]) continue;

	int masked_row = masks[mask_i].first;
	int masked_col = masks[mask_i].second;
	
	int sum = 0;
	for(int row = 0; row < num_of_rows; row++){
	  if(row == masked_row) continue;
	  sum += table[row][masked_col];
	}
	if(-10000 <= sum && sum <= 10000){
	  table[masked_row][masked_col] = table[num_of_rows][masked_col] - sum;
	  visited[mask_i] = true;
	  continue;
	}
	
	sum = 0;
	for(int col = 0; col < num_of_cols; col++){
	  if(col == masked_col) continue;
	  sum += table[masked_row][col];
	}
	if(-10000 <= sum && sum <= 10000){
	  table[masked_row][masked_col] = table[masked_row][num_of_cols] - sum;
	  visited[mask_i] = true;
	  continue;
	}
      }
    }

    bool isok = true;
    for(int mask_i = 0; mask_i < masks.size(); mask_i++){
      if(!visited[mask_i]){
	isok = false;
      }
    }

    if(!is_first){
      printf("\n");
    }

    if(isok){
      for(int mask_i = 0; mask_i < masks.size(); mask_i++){
	int row = masks[mask_i].first;
	int col = masks[mask_i].second;
	printf("%d\n",table[row][col]);
      }
    }
    else{
      printf("NO\n");      
    }
    is_first = false;
  }
}
