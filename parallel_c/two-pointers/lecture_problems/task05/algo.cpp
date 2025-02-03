// Input:
//   array with non-negative elements (a[i] >= 0)
//   some integer S

// Output:
//   minimum length of the array with sum >= S

// if it is not possible to get sum greater than S then output INT_MAX


#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <limits>


const int MAXN = std::numeric_limits<int>::max();


int algo(std::vector<int>& a, int S) {
  if (S == 0) {
    return 1;
  }
  int n = static_cast<int>(a.size());
  int min_length = MAXN;
  int curr_sum = 0;
  int r = 0;
  for (int l = 0; l < n; ++l) {
    while (r < n && curr_sum < S) {
      curr_sum += a[r];
      ++r;
    }
    if (curr_sum >= S && r - l >= 0) {
      min_length = std::min(min_length, r - l);
    }
    curr_sum -= a[l];
  }
  return min_length;
}

