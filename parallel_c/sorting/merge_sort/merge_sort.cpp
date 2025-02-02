// MergeSort
// Time Complexity: O(n logn)


#include <iostream>
#include <vector>


void Merge(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output, int start) {

  int n = first.size();
  int m = second.size();
  
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (first[i] < second[j]) {
      output[start] = first[i];
      ++i;
    }
    else {
      output[start] = second[j];
      ++j;
    }
    ++start;
  }
  while (i < n) {
    output[start] = first[i];
    ++i;
    ++start;
  }
  while (j < m) {
    output[start] = second[j];
    ++j;
    ++start;
  }
}


void MergeSort(std::vector<int>& a, int left, int right) {
  if (right - left > 1) {
    int middle = left + (right - left) / 2;
    std::vector<int> first, second;
    for (int i = left; i < middle; ++i) first.push_back(a[i]);
    for (int i = middle; i < right; ++i) second.push_back(a[i]);
    MergeSort(first, 0, first.size());
    MergeSort(second, 0, second.size());
    Merge(first, second, a, left);
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
  
  MergeSort(a, 0, n);
  
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  
  return 0;
}
