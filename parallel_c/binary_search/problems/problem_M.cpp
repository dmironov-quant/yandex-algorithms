// https://informatics.msk.ru/mod/statements/view.php?chapterid=3398#1 
// Задача M: Велогонка

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double t, const vector<int>& x0, vector<int>& v0) {
  double maximum = -1e20;
  double minimum =  1e20;
  int n = static_cast<int>(x0.size());
  for (int i = 0; i < n; ++i) {
    maximum = max(maximum, x0[i] + v0[i] * t);
    minimum = min(minimum, x0[i] + v0[i] * t);
  }
  return maximum - minimum;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<int> x0(n);
  vector<int> v0(n);
  for (int i = 0; i < n; ++i) {
    cin >> x0[i];
    cin >> v0[i];
  }
  
  double left = 0;
  double right = 1e10;
  for (int i = 0; i < 200; ++i) {
    double a = left + (right - left) / 3.0;
    double b = left + 2 * (right - left) / 3.0;
    if (f(b, x0, v0) > f(a, x0, v0)) {
      right = b;
    }
    else {
      left = a;
    }
  }
  
  cout << setprecision(20);
  cout << left << " " << f(left, x0, v0);
  
  return 0;
}
