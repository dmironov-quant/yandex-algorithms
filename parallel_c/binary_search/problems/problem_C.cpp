// Problem C. Arrays
// https://informatics.msk.ru/mod/statements/view.php?id=5457&chapterid=742#1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  sort(begin(a), end(a));
  
  int m;
  cin >> m;
  
  while (m--) {
    int x;
    cin >> x;
    int s = lower_bound(begin(a), end(a), x) - begin(a);
    int e = upper_bound(begin(a), end(a), x) - begin(a);
    cout << (e - s) << ' ';
  }
  
  
  
  return 0;
}
