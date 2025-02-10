// Input:
//   array with non-negative integer numbers (a[i] >= 0)
//   max(a[i]) < 10^6

// Output:
//   contiguous subarray of max length that contains no more than K different numbers

// Will output the length


#include <vector>
#include <unordered_map>


int algo(std::vector<int>& a, int K) {
  int n = static_cast<int>(a.size());
  std::unordered_map<int, int> seen;
  int max_length = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    ++seen[a[r]];
    while (l < n && static_cast<int>(seen.size()) > K) {
      --seen[a[l]];
      if (seen[a[l]] == 0) {
        seen.erase(a[l]);
      }
      ++l;
    }
    if (static_cast<int>(seen.size()) <= K) {
      max_length = std::max(max_length, r - l + 1);
    }
  } 
  return max_length;
}

