// problem_B: Приближенный двоичных поиск
// https://informatics.msk.ru/mod/statements/view.php?chapterid=2#1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  while (k--) {
    int x;
    cin >> x;
    
    int left = -1;
    int right = n;
    while (right > left + 1) {
      int middle = left + (right - left) / 2;
      if (a[middle] <= x) {
        left = middle;
      }
      else {
        right = middle;
      }
    }
    
    if (right == n) {
      cout << a[left] << '\n';
    }
    else if (left == -1) {
      cout << a[right] << '\n';
    }
    else if (abs(x - a[left]) <= abs(x - a[right])) {
      cout << a[left] << '\n';
    }
    else {
      cout << a[right] << '\n';
    }
  }
  
  return 0;
}
