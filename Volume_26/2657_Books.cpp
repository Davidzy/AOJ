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

class Book {
private:
  string title;
  string author;
  string date;

  int date2sec(string date){
    vector<string> elements;
    string tmp = "";
    for(int i = 0; i < date.size(); i++){
      if(date[i] == '/'){
	elements.push_back(tmp);
	tmp = "";
	continue;
      }
      tmp += date[i];
    }
    elements.push_back(tmp);
    
    return 365 * (atoi(elements[0].c_str()) - 1970)
      + atoi(elements[1].c_str()) * 31
      + atoi(elements[2].c_str());
  }

public:
  Book(string title, string author, string date) {
    this->title = title;
    this->author = author;
    this->date = date;
  }

  bool match_title(string query){
    if(query == "*") return true;
    for(int i = 0; i + query.size() <= title.size(); i++){
      if(title.substr(i,query.size()) == query) return true;
    }
    return false;
  }

  bool match_author(string query){
    if(query == "*") return true;
    for(int i = 0; i + query.size() <= author.size(); i++){
      if(author.substr(i,query.size()) == query) return true;
    }
    return false;
  }

  bool match_date(string from,string to) {
    int my_sec = date2sec(date);
    if(from != "*" && my_sec < date2sec(from)) return false;
    if(to != "*" && my_sec > date2sec(to)) return false;
    return true;
  }

  string get_title() const {
    return title;
  }
};

int main(){
  int num_of_books;
  int num_of_queries;
  while(~scanf("%d",&num_of_books)){
    vector<Book> books;
    for(int book_i = 0; book_i < num_of_books; book_i++){
      string title,author,date;
      cin >> title >> author >> date;
      books.push_back(Book(title,author,date));
    }
    scanf("%d",&num_of_queries);
    for(int query_i = 0; query_i < num_of_queries; query_i++){
      string title,author,from,to;
      cin >> title >> author >> from >> to;
      for(int book_i = 0; book_i < num_of_books; book_i++){
	if(books[book_i].match_title(title)
	   && books[book_i].match_author(author)
	   && books[book_i].match_date(from,to)){
	  cout << books[book_i].get_title() << endl;
	}
      }
      if(query_i != num_of_queries -1){
	cout << endl;
      }
    }
  }
}
