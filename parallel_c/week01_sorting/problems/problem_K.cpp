#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int>& b, vector<int>& c, vector<int>& a) {
    int n = static_cast<int>(b.size());
    int m = static_cast<int>(c.size());
    
    int i = 0;
    int j = 0;
    
    while (i < n && j < m) {
        if (b[i] < c[j]) {
            a[i+j] = b[i];
            ++i;
        }
        else {
            a[i+j] = c[j];
            ++j;
        }
    }
    while (i < n) {
        a[i+j] = b[i];
        ++i;
    }
    while (j < m) {
        a[i+j] = c[j];
        ++j;
    }
}


void MergeSort(vector<int>& a, int left, int right) {
    if ((right - left) > 1) {
        int middle = left + (right - left) / 2;
        vector<int> b;
        for (int i = left; i < middle; ++i) b.push_back(a[i]);
        vector<int> c;
        for (int i = middle; i < right; ++i) c.push_back(a[i]);
        MergeSort(b, 0, static_cast<int>(b.size()));
        MergeSort(c, 0, static_cast<int>(c.size()));
        Merge(b, c, a);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int b;
    cin >> b;
    
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    MergeSort(a, 0, n);
    
    int ans = 0;
    if (a[n - 1] < b) {
        cout << ans;
        return 0;
    }
    ++ans;
    int prev_level = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if ( (a[i] >= b) && (prev_level - a[i]) >= 3 ) {
            ++ans;
            prev_level = a[i];
        }
    }
    
    cout << ans;
    
    return 0;
}
