// Problem Q: Equation
// Need to find a numerical solution to cos(x) = a*x 
// with a - given real non-negative number

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  double a;
  cin >> a;
  
  double left = 0;
  double right = M_PI / 2;
  
  for (int i = 0; i < 100; ++i) {
    double middle = left + (right - left) / 2.0;
    if (cos(middle) > a * middle) {
      left = middle;
    }
    else {
      right = middle;
    }
  }
  
  
  cout << setprecision(100);
  cout << left << endl;
  
  return 0;
}
