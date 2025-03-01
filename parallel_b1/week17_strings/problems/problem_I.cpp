// Задача I: Строчечки
// https://informatics.msk.ru/mod/statements/view.php?chapterid=112577#1

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

vector<int> zfn(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    string t;
    cin >> s >> t;
    
    string w = s + "#" + t + t;
    
    vector<int> ng = zfn(w);
    
    int ans = -1;
    
    for (int i = (int)s.size(); i < (int)w.size(); ++i) {
        if (ng[i] == (int)s.size()) {
            ans = i - (int)s.size() - 1;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
