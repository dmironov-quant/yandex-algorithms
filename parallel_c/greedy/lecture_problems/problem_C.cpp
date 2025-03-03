// Непересекающиеся отрезки
// https://informatics.msk.ru/mod/statements/view.php?chapterid=113073#1


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


struct Schedule {
  int left;
  int right;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<Schedule> schedule;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    schedule.push_back({ start, end });
  }
  
  sort(begin(schedule), end(schedule), 
      [](const Schedule& lhs, const Schedule& rhs) {
          return lhs.right < rhs.right || (lhs.right == rhs.right && lhs.left > rhs.left);      
    }
  );
  
  int ans = 1;
  int prev_right = schedule[0].right;
  for (int i = 1; i < n; ++i) {
    if (schedule[i].left >= prev_right) {
      ++ans;
      prev_right = schedule[i].right;
    }
  }
  
  cout << ans;
  
  return 0;
}
