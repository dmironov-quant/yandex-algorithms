// https://codeforces.com/problemset/problem/2004/C?locale=ru

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <cmath>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    sort(rbegin(a), rend(a));
    
    int64_t score = 0;
    for (int i = 0; i < n; i += 2) {
      score += a[i];
    }
    for (int i = 1; i < n; i += 2) {
      int64_t delta;
      if ( k < (a[i-1] - a[i]) ) {
        delta = k;
      }
      else {
        delta = a[i-1] - a[i];
      }
      score -= a[i] + delta;
      if ( (k - delta) < 0 ) {
        k = 0;
      }
      else {
        k -= delta;
      }
    }
    
    cout << score << '\n';
  }
  
  return 0;
}
