// Задача C: Гистограмма
// https://informatics.msk.ru/mod/statements/view.php?chapterid=111253#1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    heights.push_back(0);
    
    
    vector<int> stack;
    int64_t max_area = 0;
    for (int i = 0; i < n + 1; ++i) {
        while (!stack.empty() && heights[i] <= heights[stack.back()]) {
            int j = stack.back();
            stack.pop_back();
            int height = heights[j];
            int width;
            if (stack.empty()) {
                width = i;
            }
            else {
                width = i - stack.back() - 1;
            }
            if (height * static_cast<int64_t>(width) > max_area) {
                max_area = height * width;
            }
        }
        stack.push_back(i);
    }
    
    cout << max_area;
    
    return 0;
}
