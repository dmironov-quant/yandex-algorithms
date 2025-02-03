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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  
  std::uniform_int_distribution<> test_n(100'000, 100'000 + 17);
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
    
    std::uniform_int_distribution<> S_choose(0, 50);
    int S = S_choose(gen);
    
    int expected_answer = MAXN;
    for (int l = 0; l < n; ++l) {
      int curr_sum = 0;
      for (int r = l; r < n; ++r) {
        curr_sum += a[r];
        if (curr_sum >= S) {
          expected_answer = std::min(expected_answer, r - l + 1);
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
