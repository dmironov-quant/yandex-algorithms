// https://informatics.msk.ru/mod/statements/view.php?id=68254&chapterid=113124#1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Position {
  int left;
  int right;
};



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<Position> a;
  for (int i = 0; i < n; ++i) {
    int left, right;
    cin >> left >> right;
    a.push_back({ left, right });
  }
  
  sort(begin(a), end(a), 
    [](const Position& p_left, const Position& p_right) {
      return (p_left.left < p_right.left) || (p_left.left == p_right.left &&  p_left.right < p_right.right);     
    }
  );
  
  vector<Position> ans;
  for (int i = 0; i < n; ++i) {
    if (ans.empty() || ans.back().right < a[i].left) {
      ans.push_back(a[i]);
    }
    else {
      size_t k = ans.size() - 1;
      ans[k].right = std::max(ans[k].right, a[i].right);
    }
  }
  
  cout << ans.size() << "\n";
  for (const Position& position : ans) {
    cout << position.left << " " << position.right << '\n';
  }
  
  return 0;
}
