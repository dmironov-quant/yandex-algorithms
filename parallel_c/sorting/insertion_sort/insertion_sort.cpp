// Insertion sort
// Time Complexity: O(n^2)

// The idea is to keep the prefix of array sorted at each step e.g. a[:i] is sorted for any i

// Program input:
// The first line of the input contains one integer n (1 ≤ n ≤ 1000) which is the number of elements in the array. 
// The second line contains n integers which do not exceed 10^9 by absolute value.

// Program output:
// The sole line of the output should contain the same array but in the non-decreasing order. 
// The elements should be separated by space.


#include <iostream>
#include <vector>


void Insertion_sort(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  for (int i = 0; i < n - 1; ++i) {
    int min_element = a[i];
    int min_index = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < min_element) {
        min_element = a[j];
        min_index = j;
      }
    }
    int tmp = a[i];
    a[i] = min_element;
    a[min_index] = tmp;  
  }
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
  
  Insertion_sort(a);
  
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  
  return 0;
}
