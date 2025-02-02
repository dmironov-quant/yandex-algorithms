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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> test_n(1, 2);
  int k = test_n(gen);
  
  int count_errors = 0;
  while (k--) {
    std::uniform_int_distribution<> array_size(50, 100);
    int n = array_size(gen);
    
    std::vector<int> a(n, 0);
    std::uniform_int_distribution<> element(-100, 100);
    for (int i = 0; i < n; ++i) {
      int x = element(gen);
      a[i] = x;
    }
    
    int expected_answer = 0;
    for (int l = 0; l < n; ++l) {
      int curr_sum = 0;
      for (int r = l; r < n; ++r) {
        curr_sum += a[r];
        expected_answer = std::max(expected_answer, curr_sum);
      }
    }
    
    int kadane_answer = kadane_algo(a);
    int prefix_sum_answer = prefix_sum_algo(a);
    
    if (kadane_answer != expected_answer || prefix_sum_answer != expected_answer) {
      ++count_errors;
    }
    
    
  }
  
  if (count_errors > 0) {
    std::cout << "ERRORS FOUND!" << '\n';
    std::cout << "NUMBER OF ERRORS=" << count_errors << '\n';
  }
  else {
    std::cout << "OK!" << '\n';
    std::cout << "ALL TEST PASSED" << '\n';
  }
  
  return 0;
}
