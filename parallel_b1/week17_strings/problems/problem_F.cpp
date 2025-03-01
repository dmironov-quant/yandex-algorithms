// Задача F: N-функция
// Следует вычислить N-функция для строки, 
// которая подается на вход


// N-функция определяется как 
// nf[i] = max_{k}  ( s[0...k] == s[i...i+k] )
// nf[0] - можно взять любым, зависит от задачи


#include <cmath>
#include <string>
#include <vector>


vector<int> optimal_solution(const string& s) {
  int n = static_cast<int>(s.size());
  vector<int> nf(n, 0);
  int l = 0;
  int r = 0;
  for (int i = 1; i < n; ++i) {
    if (r > i) {
      nf[i] = min(nf[i-l], r-i);
    }
    while ( (i + nf[i] < n) && (s[nf[i]] == s[i + nf[i]]) ) {
      ++nf[i];
    }
    if (i + nf[i] > r) {
      l = i;
      r = i + nf[i];
    }
  }
  return nf;
}
