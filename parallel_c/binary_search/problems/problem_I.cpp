// https://informatics.msk.ru/mod/statements/view.php?id=1966#1
// Задача I: Дипломы

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <numeric>
#include <limits>
using namespace std;


int w, h, n;
  
bool good(int k) {
  uint64_t a = static_cast<uint64_t>(k / h);
  uint64_t b = static_cast<uint64_t>(k / w);
  return static_cast<uint64_t>(n) <= a * b; 
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> w >> h >> n;
  
  int left = 0;
  int right = 1'000'000'000 + 17;
  
  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (good(middle)) {
      right = middle;
    }
    else {
      left = middle;
    }
  }
  
  cout << right;
  
  return 0;
}
