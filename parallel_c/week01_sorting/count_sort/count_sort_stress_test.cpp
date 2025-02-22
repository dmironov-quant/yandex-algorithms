// Count sort  O(n) but restrictions apply


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <map>
#include <random>


const int MAX = std::numeric_limits<int>::max();
const int MIN = std::numeric_limits<int>::min();


std::pair<std::vector<int>, int> Count_sort(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  int min_element = MAX;
  for (int i = 0; i < n; ++i) {
    if (a[i] < min_element) {
      min_element = a[i];
    }
  }
  int shift = 0;
  if (min_element < 0) {
    shift = abs(min_element);
  }
  int max_element = MIN;
  for (int i = 0; i < n; ++i) {
    if (a[i] + shift > max_element) {
      max_element = a[i] + shift;
    }
  }
  int k = max_element + 1;
  std::vector<int> count(k, 0);
  for (int i = 0; i < n; ++i) {
    ++count[a[i] + shift];
  }
  return { count, shift };
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> number_of_tests(1000, 10000);
  int k = number_of_tests(gen);
  
  std::cout << "Number of tests: " << k << '\n';
  
  int count_errors = 0;
  int p = 10;
  for (int test_n = 1; test_n < k + 1; ++test_n) {
    std::uniform_int_distribution<> size_of_array(30, 100);
    int n = size_of_array(gen);
    
    std::vector<int> a(n, 0);
    std::vector<int> b(n, 0);
    std::uniform_int_distribution<> element(-50, 50);
    for (int i = 0; i < n; ++i) {
      int x = element(gen);
      a[i] = x;
      b[i] = x;
    }
    
    std::pair<std::vector<int>, int> count_sort = Count_sort(a);
    
    std::vector<int> sorted = count_sort.first;
    int shift = count_sort.second;
    
    std::vector<int> count_algorithm;
    for (int i = 0; i < static_cast<int>(sorted.size()); ++i) {
      for (int j = 0; j < static_cast<int>(sorted[i]); ++j) {
        count_algorithm.push_back(i - shift);
      }
    }
    
    std::sort(begin(b), end(b));
    
    if (count_algorithm != b) {
      ++count_errors;
    }
    
    if (test_n % 1000 == 0 || test_n == k) {
      std::cout << test_n << " tests done" << '\n'; 
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
