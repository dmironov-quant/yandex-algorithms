// Bubble Sort implementation

// Program input:
// The first line of the input contains one integer n (1 ≤ n ≤ 1000) which is the number of elements in the array. 
// The second line contains n integers which do not exceed 10^9 by absolute value.

// Program output:
// The sole line of the output should contain the same array but in the non-decreasing order. 
// The elements should be separated by space.


#include <iostream>
#include <vector>


void bubble_sort(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (a[j] < a[j - 1]) {
        int tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
      }
    }
  }
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  bubble_sort(a);
  
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  
  return 0;
}
