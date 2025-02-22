#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void Merge(vector<string>& b, vector<string>& c, vector<string>& a) {
    int n = static_cast<int>(b.size());
    int m = static_cast<int>(c.size());
    
    int i = 0;
    int j = 0;
    
    while (i < n && j < m) {
        if (b[i] + c[j] < c[j] + b[i]) {
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


void MergeSort(vector<string>& a, int left, int right) {
    if ((right - left) > 1) {
        int middle = left + (right - left) / 2;
        vector<string> b;
        for (int i = left; i < middle; ++i) b.push_back(a[i]);
        vector<string> c;
        for (int i = middle; i < right; ++i) c.push_back(a[i]);
        MergeSort(b, 0, static_cast<int>(b.size()));
        MergeSort(c, 0, static_cast<int>(c.size()));
        Merge(b, c, a);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<string> a;
    
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        a.push_back(number);
    }
    
    MergeSort(a, 0, static_cast<int>(a.size()));
    
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        cout << a[i];
    }
    
    return 0;
}
