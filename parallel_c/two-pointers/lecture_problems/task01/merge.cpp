// Input: two ascendingly sorted arrays
// Output: ascendingly sorted array which is the combined result of the input


#include <iostream>
#include <vector>


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
