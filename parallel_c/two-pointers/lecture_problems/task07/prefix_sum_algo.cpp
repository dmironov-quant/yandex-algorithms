// Input:
//   array containing integer numbers which can be both negative and positive

// Output:
//   find the contiguous subarray of the input array having maximum sum
//   return the max sum 

// It is allowed to return select empty subarray.
// The answer is then 0


#include <iostream>
#include <vector>


int prefix_sum_algo(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  std::vector<int> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix_sum[i] = prefix_sum[i-1] + a[i-1];
  }
  int ans = 0;
  int minimum_prefix = prefix_sum[0];
  for (int r = 1; r <= n; ++r) {
    ans = std::max(ans, prefix_sum[r] - minimum_prefix);
    minimum_prefix = std::min(minimum_prefix, prefix_sum[r]);
  }
  return ans;
}
