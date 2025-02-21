// Задача L: Дремучий Лес
// https://informatics.msk.ru/mod/statements/view.php?chapterid=3859#1

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


double vp, vf, a;

double g(double x0) {
  return sqrt(x0*x0 + (1-a)*(1-a)) / vp + sqrt(a*a + (1-x0)*(1-x0)) / vf;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> vp >> vf;
  cin >> a;
  
  
  double left = 0;
  double right = 1;
  
  for (int i = 0; i < 150; ++i) {
    double a = left + (right - left) / 3.0;
    double b = left + 2 * (right - left) / 3.0;
    // cout << "g(a) = " << g(a) << ", a = " << a << ", g(b) = " << g(b) << ", b = " << b << endl;
    if (g(a) < g(b)) {
      right = b;
    }
    else {
      left = a;
    }
  }
  
  cout << setprecision(20);
  cout << left;
  
  return 0;
}
