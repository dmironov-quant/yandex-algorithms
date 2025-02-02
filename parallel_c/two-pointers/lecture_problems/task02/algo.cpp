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
