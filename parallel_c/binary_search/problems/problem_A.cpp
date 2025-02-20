// Problem A: Binary search
// https://informatics.msk.ru/mod/statements/view.php?id=13858#1


#include <iostream>
#include <vector>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    bool found = false;
    int left = 0;
    int right = n - 1;
    while (right >= left) {
      int middle = left + (right - left) / 2;
      if (a[middle] == x) {
        found = true;
        break;
      }
      else if (a[middle] > x) {
        right = middle - 1;
      }
      else {
        left = middle + 1;
      }
    }
    if (!found) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
  
  return 0;
}
