// Segment with given sum
// Input: 
//    array with non-negative integer numbers (a[i] >= 0)
//    number S 
// Output:
//    maximum length of segment with sum of elements <= S



#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


int algo(std::vector<int>& a, int S) {
  int n = static_cast<int>(a.size());
  int ans = 0;
  int curr = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    curr += a[r];
    while (l < n && curr > S) {
      curr -= a[l];
      ++l;
    }
    if (curr <= S) {
      ans = std::max(ans, r - l + 1);
    }
  }
  return ans;
}
