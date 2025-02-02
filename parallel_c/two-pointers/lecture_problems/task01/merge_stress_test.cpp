// Input: two ascendingly sorted arrays
// Output: ascendingly sorted array which is the combined result of the input


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


void merge_impl_01(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  
  int i = 0;
  int j = 0;
  
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      c[i+j] = a[i];
      ++i;
    }
    else {
      c[i+j] = b[j];
      ++j;
    }
  }
  while (i < n) {
    c[i+j] = a[i];
    ++i;
  }
  while (j < m) {
    c[i+j] = b[j];
    ++j;
  }
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
    
    std::vector<int> expected_answer;
    for (const int& x : a) {
      expected_answer.push_back(x);
    }
    for (const int& x : b) {
      expected_answer.push_back(x);
    }
    sort(begin(expected_answer), end(expected_answer));
    
    std::vector<int> c(n+m);
    merge_impl_01(a, b, c);
    
    if (c != expected_answer) {
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
