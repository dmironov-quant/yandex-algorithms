// Задача H: Поиск подстроки
// https://informatics.msk.ru/mod/statements/view.php?chapterid=99#1

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


vector<int> solution(const string& w) {
  int k = (int)w.size();
  vector<int> nf(k, 0);
  int l = 0;
  int r = 0;
  for (int i = 1; i < k; ++i) {
    if (r > i) {
      nf[i] = min(nf[i - l], r - i);
    }
    while (i + nf[i] < k && w[i + nf[i]] == w[nf[i]]) {
      ++nf[i];
    }
    if (i + nf[i] > r) {
      l = i;
      r = i + nf[i];
    }
  }
  return nf;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  
  string t;
  cin >> t;
  
  string w = t + '#' + s;
  
  vector<int> ans = solution(w);
  
  for (int i = (int)t.size() + 1; i < (int)w.size(); ++i) {
    if (ans[i] == (int)t.size()) {
      cout << i - (int)t.size() - 1 << ' ';
    }
  }
  
  return 0;
}
