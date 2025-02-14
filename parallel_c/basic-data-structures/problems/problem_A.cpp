// https://informatics.msk.ru/mod/statements/view.php?chapterid=771#1


#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool solution(const string& s) {
    
    vector<char> stack;
    
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        char x = s[i];
        if (x == '(' || x == '[' || x == '{') {
            stack.push_back(x);
        }
        else if (stack.empty()) {
            return false;
        }
        else if (x == ')' && stack.back() == '(') {
            stack.pop_back();
        }
        else if (x == ']' && stack.back() == '[') {
            stack.pop_back();
        }
        else if (x == '}' && stack.back() == '{') {
            stack.pop_back();
        }
        else {
            return false;
        }
    }
    return stack.empty();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    bool correct_seq = solution(s);
    
    if (correct_seq) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    
    return 0;
}
