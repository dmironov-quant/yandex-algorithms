// https://acm.timus.ru/problem.aspx?space=1&num=1613&locale=ru
// Задача P: Для любителей статистики

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct Data {
  int value;
  int org_idx;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<Data> a(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i-1] = { x, i };
  }
  
  sort(begin(a), end(a), 
        [](const Data& lhs, const Data& rhs) {
    return lhs.value < rhs.value || (lhs.value == rhs.value && lhs.org_idx < rhs.org_idx);
  });
  
  unordered_map<int, int> mapper;
  for (int i = 1; i <= n; ++i) {
      mapper[a[i-1].org_idx] = i;
  }
  
   int q;
   cin >> q;
  
   while (q--) {
     int l, r, x;
     cin >> l >> r >> x;
    
     int left = mapper[l] - 1;
     int right = mapper[r] - 1;
    
     bool found = false;
    
     while (right >= left) {
       int middle = left + (right - left) / 2;
       if (a[middle].value == x) {
         found = true;
         break;
       }
       else if (a[middle].value < x) {
         left = middle + 1;
       }
       else {
         right = middle - 1;
       }
     }
    
     if (found) {
       cout << 1;
     }
     else {
       cout << 0;
     }
    
   }
  
  return 0;
}
