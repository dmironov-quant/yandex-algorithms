// Input:
//    array with non-negative (a[i] >= 0) elements
//    some value S

// Output: 
//    number of segments with the sum <= S



#include <iostream>
#include <vector>
#include <random>


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
      ans += r - l + 1;
    }
  }
  return ans;
}

