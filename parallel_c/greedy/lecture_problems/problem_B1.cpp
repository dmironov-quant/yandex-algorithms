// Вариация задачи про дискретный рюкзак
// На лекции не решали тк это тема ДП
// https://informatics.msk.ru/mod/statements/view.php?id=813&chapterid=1120#1

// Задача 0-1 рюкзак: точный вес

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> m(N, 0);
    for (int i = 0; i < N; ++i) cin >> m[i];
    
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (j-m[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-m[i-1]] + m[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }   
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        if (dp[i][M] == M) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;
}
