// Нужно решить уравнение 
// f(x) = x^6 + x^4 + x^2
// f(x0) = c
// найти решение x0 на области x \in [0, +inf]

#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include <cmath>
using namespace std;


const int MAX = numeric_limits<int>::max();
const double EPS = 1e-6;


double f(double x) {
    return pow(x, 6) + pow(x, 4) + pow(x, 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    random_device rd;
    mt19937 gen(rd());
    
    int cnt_errors = 0;
    uniform_int_distribution<> n_tests(5000, 10000);
    int k = n_tests(gen);
    while (k--) {
        uniform_int_distribution<> C(0, 100);
        double c = C(gen);
        double left = 0;
        double right = 1e20;
        for (int i = 0; i < 150; ++i) {
            double mid = left + (right - left) / 2.0;
            if (f(mid) > c) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        double x0 = left + (right - left) / 2.0;
        if (abs(f(x0) - c) > EPS) {
            ++cnt_errors;
            break;
        }
    }
    
    if (cnt_errors == 0) {
        cout << "ALL TESTS PASSED, OK!";
    }
    else {
        cout << "ERRORS FOUND!";
    }
    
    return 0;
}
