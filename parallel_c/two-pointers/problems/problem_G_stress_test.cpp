// https://usaco.org/index.php?page=viewproblem2&cpid=89
// Задача G: Cow Lineup

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <limits>
#include <random>
using namespace std;


struct Cow {
  int x;
  int type;
};


int algo_solution(const vector<Cow>& cow, const map<int, int>& unique_type) {
  int ans = numeric_limits<int>::max();
  int n = static_cast<int>(cow.size());
  map<int, int> curr_types;
  int r = 0;
  for (int l = 0; l < n; ++l) {
    while (r < n && curr_types.size() < unique_type.size()) {
      ++curr_types[cow[r].type];
      ++r;
    }
    if (curr_types.size() == unique_type.size()) {
      ans = min(ans, cow[r-1].x - cow[l].x);
    }
    --curr_types[cow[l].type];
    if (curr_types[cow[l].type] == 0) {
      curr_types.erase(cow[l].type);
    }
  }
  return ans;
}


int brute_force(const vector<Cow>& cow, const map<int, int>& unique_type) {
  int ans = numeric_limits<int>::max();
  int n = static_cast<int>(cow.size());
  for (int l = 0; l < n; ++l) {
    map<int, int> curr_types;
    for (int r = l; r < n; ++r) {
      ++curr_types[cow[r].type];
      if (curr_types.size() == unique_type.size()) {
        ans = min(ans, cow[r].x - cow[l].x);
      }
    }
  }
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  
  random_device rd;
  mt19937 gen(rd());
  
  uniform_int_distribution<> n_queries(100, 1000);
  int q = n_queries(gen);
  
  int cnt_errors = 0;
  while (q--) {
    
    uniform_int_distribution<> array_size(1, 100);
    uniform_int_distribution<> x_coordinate(1, 20);
    uniform_int_distribution<> select_type(1, 20);
    
    int n = array_size(gen);
  
    vector<Cow> cow;
    map<int, int> unique_type;
    for (int i = 0; i < n; ++i) {
      int x = x_coordinate(gen);
      int type = select_type(gen);
      cow.push_back({ x, type });
      ++unique_type[type];
    }
    
    sort(begin(cow), end(cow), 
        [](const Cow& lhs, const Cow& rhs) {
      return lhs.x < rhs.x;
    });
    
    int algo_answer = algo_solution(cow, unique_type);
    int bf_answer = brute_force(cow, unique_type);
  
    if (algo_answer != bf_answer) {
      ++cnt_errors;
    }
  }
  
  if (cnt_errors > 0) {
    cout << "ERRORS ARE FOUND!";
  }
  else {
    cout << "NO ERRORS FOUND" << '\n';
    cout << "FAST ALGO gives the same result as BRUTE FORCE SOLUTION" << '\n';
  }
  
  return 0;
}
