
// Задача G: Cow Lineup
// https://usaco.org/index.php?page=viewproblem2&cpid=89

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <limits>
using namespace std;


struct Cow {
  int x;
  int type;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<Cow> cow;
  map<int, int> unique_type;
  for (int i = 0; i < n; ++i) {
    int x, type;
    cin >> x >> type;
    cow.push_back({ x, type });
    ++unique_type[type];
  }
  
  sort(begin(cow), end(cow), 
      [](const Cow& lhs, const Cow& rhs) {
    return lhs.x < rhs.x;
  });
  
  int ans = numeric_limits<int>::max();
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
  
  cout << ans;
  
  return 0;
}
