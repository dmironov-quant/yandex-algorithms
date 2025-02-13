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
    
    int i = 0, j = 0, k = 0, l = 0;
    int best_i = 0, best_j = 0, best_k = 0, best_l = 0;

    while (i < n1 && j < n2 && k < n3 && l < n4) {
        vector<int> candidates{ a[i], b[j], c[k], d[l] };
        sort(begin(candidates), end(candidates));
        int curr = candidates.back() - candidates[0];
        
        if (curr < ans) {
            curr = ans;
            best_i = i;
            best_j = j;
            best_k = k;
            best_l = l;
        }
        
        int min_ = *min_element(begin(candidates), end(candidates));
        
        while (i < n1 && a[i] == min_) {
            ++i;
        }
        while (j < n2 && b[j] == min_) {
            ++j;
        }
        while (k < n3 && c[k] == min_) {
            ++k;
        }
        while (l < n4 && d[l] == min_) {
            ++l;
        }
        
    }
    
    cout << a[best_i] << " " 
         << b[best_j] << " " 
         << c[best_k] << " " 
         << d[best_l];
    
    return 0;
}
