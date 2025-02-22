// Count sort  O(n) but restrictions apply


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>


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
  
  int n;
  std::cin >> n;
  
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  std::pair<std::vector<int>, int> count_sort = Count_sort(a);
  
  std::vector<int> sorted = count_sort.first;
  int shift = count_sort.second;
  
  for (int i = 0; i < static_cast<int>(sorted.size()); ++i) {
    for (int j = 0; j < static_cast<int>(sorted[i]); ++j) {
      std::cout << i - shift << ' ';
    }
  }
  
  return 0;
}

