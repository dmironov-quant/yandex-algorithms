// Задача G: Префикс-функция
// https://informatics.msk.ru/mod/statements/view.php?chapterid=1323#1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  
  int n = static_cast<int>(s.size());
  vector<int> pi(n, 0);
  
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    pi[i] = j;
  }
  
  for (int i = 0; i < n; ++i) {
    cout << pi[i] << ' ';
  }
  
  return 0;
}
