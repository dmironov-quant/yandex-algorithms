// Задача B: Проблема сапожника
// https://informatics.msk.ru/mod/statements/view.php?chapterid=113074#1


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(k);
  for (int i = 0; i < k; ++i) cin >> a[i];
  
  sort(begin(a), end(a));
  
  int cnt = 0;
  for (int i = 0; i < k; ++i) {
    if (n - a[i] >= 0) {
      ++cnt;
      n -= a[i];
    }
    else {
      break;
    }
  }
  
  cout << cnt;
  
  return 0;
}
