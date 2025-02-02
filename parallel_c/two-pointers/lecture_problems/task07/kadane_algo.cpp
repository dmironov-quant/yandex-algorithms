// Input:
//   array containing integer numbers which can be both negative and positive

// Output:
//   find the contiguous subarray of the input array having maximum sum
//   return the max sum 

// It is allowed to return select empty subarray.
// The answer is then 0

#include <iostream>
#include <vector>
#include <random>



int kadane_algo(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  int curr = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    curr = std::max(curr + a[i], a[i]);
    ans = std::max(ans, curr);
  }
  return ans;
}
