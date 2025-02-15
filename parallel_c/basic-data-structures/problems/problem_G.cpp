// https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=57#1

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Queue_made {
    int k = 100;
    vector<int> q = vector<int>(k, 0);
    int start = 0;
    int end = 0;
    int cnt = 0;
    
    void push(int n) {
        q[start] = n;
        ++start;
        start %= k;
        ++cnt;
        cout << "ok" << '\n';
    }
    
    void pop() {
        int x = q[end];
        ++end;
        end %= k;
        --cnt;
        cout << x << '\n';
    }
    
    void front() {
        cout << q[end] << '\n';
    }
    
    void size() {
        cout << cnt << '\n'; 
    }
    
    void clear() {
        start = 0;
        end = 0;
        cnt = 0;
        q.clear();
        cout << "ok" << '\n';
    }
    
    void exit() {
        cout << "bye" << '\n';
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Queue_made q;
    
    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (cmd == "pop") {
            q.pop();
        }
        else if (cmd == "front") {
            q.front();
        }
        else if (cmd == "size") {
            q.size();
        }
        else if (cmd == "clear") {
            q.clear();
        }
        else {
            q.exit();
            break;
        }
    }
    
    return 0;
}
