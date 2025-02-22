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
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n*m, 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[cnt];
            ++cnt;
        }
    }
    MergeSort(a, 0, static_cast<int>(a.size()));
    
    int k;
    cin >> k;
    vector<int> g(k, 0);
    for (int i = 0; i < k; ++i) cin >> g[i];
    MergeSort(g, 0, static_cast<int>(g.size()));
    
    int ans = 0;
    int i = n*m - 1;
    int j = k - 1;
    while (j >= 0) {
        if (a[i] >= g[j]) {
            ++ans;
            --i;
            --j;
        }
        else {
            --j;
        }
    }
    
    cout << ans;
    
    return 0;
}
