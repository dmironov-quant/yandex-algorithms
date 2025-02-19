

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

struct P {
  int64_t area;
  int i;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<P> areas(n, { 0, 0 });
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<int64_t> x(k, 0);
        vector<int64_t> y(k, 0);
        for (int j = 0; j < k; ++j) {
            cin >> x[j] >> y[j];
        }
        int64_t area = 0;
        for (int j = 1; j < k; ++j) {
            area += (x[j] - x[j-1]) * (y[j] + y[j-1]);
        }
        areas[i] = { area, i } ;
    }
    
    sort(begin(areas), end(areas), [](const P& lhs, const P& rhs) {
            return lhs.area > rhs.area;
        }
    );
    
    vector<int> answer(n, 0);
    for (int i = 0; i < n; ++i) {
        answer[areas[i].i] = i;
    }
    
    for (const int& a : answer) {
        cout << a << " ";
    }
    
    return 0;
}
