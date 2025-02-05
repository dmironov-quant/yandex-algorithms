// https://informatics.msk.ru/mod/statements/view.php?chapterid=111641#1

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;


const int MIN = numeric_limits<int>::min();


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int curr_start = 0, curr_end = 0, curr = a[0];
  int ans_start = 0, ans_end = 0, ans = a[0];
  for (int i = 1; i < n; ++i) {
    if (curr + a[i] > a[i]) {
      curr += a[i];
      curr_end = i;
    }
    else {
      curr = a[i];
      curr_start = i;
      curr_end = i;
    }
    if (ans < curr) {
      ans = curr;
      ans_start = curr_start;
      ans_end = curr_end;
    }
  }
  
  ++ans_start;  
  ++ans_end;
  
  cout << ans_start << " "
       << ans_end   << " "
       << ans;
  
  return 0;
}
