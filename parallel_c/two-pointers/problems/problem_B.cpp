#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n1;
    cin >> n1;
    vector<int> a(n1, 0);
    for (int i = 0; i < n1; ++i) cin >> a[i];
    sort(begin(a), end(a));
    
    int n2;
    cin >> n2;
    vector<int> b(n2, 0);
    for (int i = 0; i < n2; ++i) cin >> b[i];
    sort(begin(b), end(b));
    
    int n3;
    cin >> n3;
    vector<int> c(n3, 0);
    for (int i = 0; i < n3; ++i) cin >> c[i];
    sort(begin(c), end(c));
    
    int n4;
    cin >> n4;
    vector<int> d(n4, 0);
    for (int i = 0; i < n4; ++i) cin >> d[i];
    sort(begin(d), end(d));
    
    vector<int> selected{ a[0], b[0], c[0], d[0] };
    sort(begin(selected), end(selected));
    int ans = selected.back() - selected[0];
    
    int j = 0, k = 0, l = 0;
    int best_i = 0, best_j = 0, best_k = 0, best_l = 0;
    for (int i = 0; i < n1; ++i) {
        int target = a[i];
        
        while (j < n2 && b[j] < target) {
            ++j;
        }
        if ( j > 0 && abs(b[j - 1] - target) < abs(b[j] - target) ) {
            --j;
        }
        
        while (k < n3 && c[k] < target) {
            ++k;
        }
        if ( k > 0 && abs(c[k - 1] - target) < abs(c[k] - target) ) {
            --k;
        }
        
        while (l < n4 && d[l] < target) {
            ++l;
        }
        if ( l > 0 && abs(d[l - 1] - target) < abs(d[l] - target) ) {
            --l;
        }
        
        vector<int> candidates{ a[i], b[j], c[k], d[l] };
        sort(begin(candidates), end(candidates));
        int curr = candidates.back() - candidates[0];
        
        if (curr < ans) {
            ans = curr;
            best_i = i;
            best_j = j;
            best_k = k;
            best_l = l;
        }
    }
    
    cout << a[best_i] << " " 
         << b[best_j] << " " 
         << c[best_k] << " " 
         << d[best_l];
    
    return 0;
}
