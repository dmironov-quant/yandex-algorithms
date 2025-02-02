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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> test_n(50, 100);
  int k = test_n(gen);
  
  int count_errors = 0;
  while (k--) {
    std::uniform_int_distribution<> size(50, 100);
    int n = size(gen);
    
    std::vector<int> a(n, 0);
    std::uniform_int_distribution<> element(0, 100);
    for (int i = 0; i < n; ++i) {
      int x = element(gen);
      a[i] = x;
    }
    
    std::uniform_int_distribution<> sum(0, 500);
    int S = sum(gen);
    
    int expected_answer = 0;
    for (int l = 0; l < n; ++l) {
      int curr = 0;
      for (int r = l; r < n; ++r) {
        curr += a[r];
        if (curr <= S) {
          expected_answer = std::max(expected_answer, r - l + 1);
        }
      }
    }
    
    int algo_answer = algo(a, S);
    
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
