// Вариация задачи про дискретный рюкзак
// На лекции не решали тк это тема ДП
// https://informatics.msk.ru/mod/statements/view.php?id=813&chapterid=1119#1

// Задача 0-1 рюкзак: наибольший вес

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, M;
    cin >> n >> M;

    vector<int> m(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (j - m[i - 1] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - m[i-1]] + m[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][M];

    return 0;
}
