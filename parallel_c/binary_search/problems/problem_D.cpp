// Problem D: Квадратный корень и квадраный квадрат
// https://informatics.msk.ru/mod/statements/view.php?id=42589&chapterid=111403#1

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  double C;
  cin >> C;
  
   double left = 0;
   double right =  sqrt(C);
   
   for (int i = 0; i < 100; ++i) {
     double middle = left + (right - left) / 2.0;
     if ((middle*middle + sqrt(middle)) > C) {
       right = middle;
     }
     else {
       left = middle;
     }
   }
   
   cout << setprecision(10);
   cout << left;
  
  return 0;
}
