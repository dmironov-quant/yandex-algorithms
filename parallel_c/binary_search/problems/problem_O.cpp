
// Задача O: Индра и mex
// https://informatics.msk.ru/mod/statements/view.php?chapterid=113945#1


#include <iostream>
#include <vector>
using namespace std;

const int M = 100001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> cnt(M, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x] = 1;
  }
  
  int ans = -1;
  for (int i = 1; i < M; ++i) {
    if (cnt[i] == 0) {
      --k;
    }
    if (k == 0) {
      ans = i;
      break;
    }
  }
  
  if (ans != -1) {
    cout << ans;
  }
  else {
    cout << 100'000 + k;
  }
  
  return 0;
}

