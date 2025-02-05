// https://informatics.msk.ru/mod/statements/view.php?chapterid=3335#1

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


void Merge(vector<uint64_t>& a, vector<uint64_t>& b, vector<uint64_t>& c, int left, uint64_t& ans) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  
  int i = 0;
  int j = 0;
  
  while (i < n && j < m) {
    if (a[i] <= b[j]) {
      c[left+i+j] = a[i];
      ++i;
    }
    else {
      c[left+i+j] = b[j];
      ++j;
      ans += n - i;
    }
  }
  
  while (i < n) {
    c[left+i+j] = a[i];
    ++i;
  }
  
  while (j < m) {
    c[left+i+j] = b[j];
    ++j;
  }
}


void MergeSort(vector<uint64_t>& a, int l, int r, uint64_t& ans) {
  if (r - l > 1) {
    int m = l + static_cast<int>((r - l) / 2);
    vector<uint64_t> b, c;
    for (int i = l; i < m; ++i) b.push_back(a[i]);
    for (int i = m; i < r; ++i) c.push_back(a[i]);
    MergeSort(b, 0, static_cast<int>(b.size()), ans);
    MergeSort(c, 0, static_cast<int>(c.size()), ans);
    Merge(b, c, a, l, ans);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, l;
  cin >> n >> l;
  
  vector<uint64_t> w(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    w[i] = static_cast<uint64_t>(l) * x + i;
  }
  
  uint64_t ans = 0;
  MergeSort(w, 0, n, ans);
  
  cout << ans;
  
  return 0;
}
