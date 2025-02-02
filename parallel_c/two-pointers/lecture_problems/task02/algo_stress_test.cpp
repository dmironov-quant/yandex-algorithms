// Given two ascendingly sorted arrays a and b, 
// for each element in b count the number of elements in a
// such that a < this element


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> algo(std::vector<int>& a, std::vector<int>& b) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  
  std::vector<int> ans(m, 0);
  
  int i = 0;
  for (int j = 0; j < m; ++j) {
    while (i < n && a[i] < b[j]) {
      ++i;
    }
    ans[j] = i;
  }
  
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> test_n(100, 1000);
  int k = test_n(gen);

  int count_errors = 0;
  while (k--) {
    std::uniform_int_distribution<> size(100, 1000);
    int n = size(gen);
    int m = size(gen);
    
    std::uniform_int_distribution<> element(-1000, 1000);
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      int x = element(gen);
      a[i] = x;
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      int x = element(gen);
      b[i] = x;
    }
    
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    
    std::vector<int> expected_answer(m, 0);
    for (int j = 0; j < m; ++j) {
      int count = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] < b[j]) {
          ++count;
        }
      }
      expected_answer[j] = count;
    }
    
    std::vector<int> algo_answer = algo(a, b);
    
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


