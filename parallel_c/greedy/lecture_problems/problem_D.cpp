// Задача 4: Монетки
// Даны монеты какими-то номиналами в неограниченном количестве
// задача найти каким минимальным количеством монет можно собрать сумму S
//
// https://codeforces.com/problemset/problem/1061/A

#include <iostream>
#include <cmath>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, S;
  cin >> n >> S;
  
  int p = floor(S / n);
  int cnt = p;
  S -= n * p;
  for (int i = n - 1; i >= 1; --i) {
    p = floor(S / i);
    cnt += p;
    S -= i * p;
  }
  
  cout << cnt;
  
  return 0;
}
