// problem F: Провода


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;


int n;
int64_t k;

bool good(const vector<int>& a, int middle) {
  int64_t cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += static_cast<int>(a[i] / middle);
  }
  return cnt >= k;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int left = 0;
  int right = *max_element(begin(a), end(a)) + 1;

  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (good(a, middle)) {
      left = middle;
    }
    else {
      right = middle;
    }
  }
  
  cout << left;
  
  return 0;
}
