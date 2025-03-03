// Задача 3: Принтеры
// https://informatics.msk.ru/mod/statements/view.php?chapterid=490#1

#include <cmath>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
using namespace std;

const int MAX = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x, y;
    cin >> n >> x >> y;
    
    if (n == 1) {
    	cout << min(x, y);
	return 0;
    }

    int left = 0;
    int right = MAX;
    while (right > left + 1) {
        int middle = left + (right - left) / 2;
        if (floor(middle / x) + floor(middle / y) >= n - 1) {
            right = middle;
        }
        else {
            left = middle;
        }
    }
    
    cout << min(x, y) + right;
    
    return 0;
}

