// problem E: Корень кубического уравнения 
// https://informatics.msk.ru/mod/statements/view.php?chapterid=3722#1


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double a, b, c, d;
  
double func(double x) {
  return a*x*x*x + b*x*x + c*x + d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> a >> b >> c >> d;
  
  double left = -1e10;
  double right = 1e10;
  
  // side where function is increasing
  char side = 'L';
  
  if (func(left) > 0) {
    side = 'R';
  }
  
  for (int i = 0; i < 150; ++i) {
    double middle = left + (right - left) / 2.0;
    if (side == 'L') {
      if (func(middle) < 0) {
        left = middle;
      }
      else {
        right = middle;
      }
    }
    else {
      if (func(middle) > 0) {
        left = middle;
      }
      else {
        right = middle;
      }
    }
  }
  
  cout << setprecision(20);
  cout << left;
  
  return 0;
}
