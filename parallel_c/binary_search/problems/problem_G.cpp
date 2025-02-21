
// Задача G: Очень Легкая Задача
// https://informatics.msk.ru/mod/statements/view.php?chapterid=490#1

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <limits>
using namespace std;

int n, x, y;

bool good(int T) {
  return floor(T/x) + floor(T/y) >= n - 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> x >> y;
  
  int left = -1;
  int right = numeric_limits<int>::max() - 2;
  
  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (good(middle)) {
      right = middle;
    }
    else {
      left = middle;
    }
  }
  
  cout << right + min(x, y);
  
  return 0;
}
