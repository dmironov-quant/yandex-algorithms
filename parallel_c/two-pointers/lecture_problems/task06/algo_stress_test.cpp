// Input:
//   array with non-negative integer numbers (a[i] >= 0)
//   max(a[i]) < 10^6

// Output:
//   contiguous subarray of max length that contains no more than K different numbers

// Will output the length


#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <algorithm>
#include <cassert>


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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> test_n(50, 100);
  int k = test_n(gen);
  
  int count_errors = 0;
  while (k--) {
    std::uniform_int_distribution<> array_size(50, 100);
    int n = array_size(gen);
    
    std::vector<int> a(n, 0);
    std::uniform_int_distribution<> element(0, 100);
    for (int i = 0; i < n; ++i) {
      int x = element(gen);
      a[i] = x;
    }
    
    std::uniform_int_distribution<> K_choose(1, 20);
    int K = K_choose(gen);
    
    int expected_answer = 0;
    int count_size = 117;
    assert (*std::max_element(begin(a), end(a)) < count_size - 1);
    for (int l = 0; l < n; ++l) {
      std::vector<int> count(count_size, 0);
      for (int r = l; r < n; ++r) {
        ++count[a[r]];
        int different_numbers = 0;
        for (int i = 0; i < count_size; ++i) {
          if (count[i] > 0) {
            ++different_numbers;
          }
        }
        if (different_numbers <= K) {
          expected_answer = std::max(expected_answer, r - l + 1);
        }
      }
    }
    
    int algo_answer = algo(a, K);
    if (algo_answer != expected_answer) {
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
