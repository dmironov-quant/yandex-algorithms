// Задача H: Коровы - в стойла
// https://informatics.msk.ru/mod/statements/view.php?chapterid=1#1


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;


int n, k;


bool good(const vector<int>& a, int d) {
  int prev_pos = a[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (prev_pos + d <= a[i]) {
      ++cnt;
      prev_pos = a[i];
    }
  }
  return cnt >= k;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int left = 0;
  int right = 1'000'000'000 + 3;
  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (good(a, middle)) {
      left = middle;
    }
    else {
      right = middle;
    }
  }
  
  cout << left << endl;
  
  return 0;
}
