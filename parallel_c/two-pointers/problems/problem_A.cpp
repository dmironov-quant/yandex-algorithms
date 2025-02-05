// https://informatics.msk.ru/mod/statements/view.php?id=40319&chapterid=111975#1

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, r;
  cin >> n >> r;
  
  vector<int> d(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  
  int64_t ans = 0;
  int right = 0;
  for (int left = 0; left < n; ++left) {
    while (right < n && d[right] - d[left] <= r) {
      ++right;
    }
    ans += n - right;
  }
  cout << ans;
  
  
  return 0;
}
