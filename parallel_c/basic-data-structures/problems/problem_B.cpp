// https://informatics.msk.ru/mod/statements/view.php?chapterid=52#1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    getline(cin, s);
    
    vector<int> stack;
    
    for (const char& x : s) {
        if (x == ' ') continue;
        if (x == '+') {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            stack.push_back(a + b);
        }
        else if (x == '-') {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            stack.push_back(a - b);
        }
        else if (x == '*') {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            stack.push_back(a * b);
        }
        else {
            stack.push_back(x - '0');
        }
    }
    
    cout << stack.back();
    
    return 0;
}
