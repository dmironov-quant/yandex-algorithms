

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Goblin {
    int goblin_number; // порядковый номер гоблина
    int queue_pos;  // позиция в очереди
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    int total_goblins = 0;
    queue<Goblin> ordinary;
    queue<Goblin> privilege;
    
    int current_number = 1;  // номер который заходит к шаману
    int goblin_queue_number = 1; // порядковый номер нового гоблина в очереди
    
    while (q--) {
        char cmd;
        cin >> cmd;
        if (cmd == '+') {
            int i;
            cin >> i;
            ordinary.push({ i,  goblin_queue_number });
            ++goblin_queue_number;
            ++total_goblins;
        }
        else if (cmd == '*') {
            int i;
            cin >> i;
            if (total_goblins % 2 == 0) {
                privilege.push({ i, 1 + total_goblins / 2 });
            }
            else {
                privilege.push({ i, 2 + total_goblins / 2 });
            }
            ++goblin_queue_number;
            ++total_goblins;
        }
        else if (cmd == '-') {
            if (privilege.empty() && !ordinary.empty()) {
                cout << ordinary.front().goblin_number << '\n';
                ordinary.pop();
                ++current_number;
            }
            else if (!privilege.empty() && ordinary.empty()) {
                cout << privilege.front().goblin_number << '\n';
                privilege.pop();
            }
            else if (current_number == privilege.front().queue_pos) {
                cout << privilege.front().goblin_number << '\n';
                privilege.pop();
            }
            else {
                cout << ordinary.front().goblin_number << '\n';
                privilege.pop();
            }
            --total_goblins;
        }
    }
    
    return 0;
}
