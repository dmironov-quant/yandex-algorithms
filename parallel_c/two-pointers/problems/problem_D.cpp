// https://informatics.msk.ru/mod/statements/view.php?chapterid=1442#1

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  uint64_t x;
  cin >> x;
  
  uint64_t ans = 0;
  uint64_t a = 1;
  uint64_t b = 1;
  uint64_t curr_a = 1;
  uint64_t curr_b = 1;
  uint64_t curr = 0;
  while (curr != x) {
    if (a == b) {
      ans = a;
      ++curr_a;
      ++curr_b;
    }
    else if (a < b) {
      ans = a;
      ++curr_a;
    }
    else {
      ans = b;
      ++curr_b;
    }
    a = curr_a * curr_a;
    b = curr_b * curr_b * curr_b;
    ++curr;
  }
  
  cout << ans;
  
  return 0;
}
