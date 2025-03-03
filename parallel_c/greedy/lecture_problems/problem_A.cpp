// Задача 1 с лекции по жадным алгоритмам с лекции 2024 года

// Непрерывный рюкзак 

// Дано N предметов
// Каждый предмет имеет вес w[i] и стоимость c[i]
// Предметы можно дробить на части от 0 до 1
// 0 означает что предмет совсем не берем
// 1 означает что предмет берется целиком
// другое значение p[i] из интервала (0, 1) означает что берем долю равную p[i]

// Задача состоит в том, чтобы максимизировать суммарную стоимость предметов в рюкзаке
// При этом вес рюкзака не может быть больше предельного веса W, заданного на перед по условию


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-50;

struct Item {
  int idx; // idx in original array, starts with 1
  int cost;
  int weight;
  double ratio; // ratio = c / w
};

bool items_sort(const Item& lhs, const Item& rhs) {
    if (lhs.weight == rhs.weight) {
        return lhs.cost > rhs.cost;
    }
    return lhs.ratio > rhs.ratio;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, W;
    cin >> n >> W;
    
    vector<int> w(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    vector<int> c(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        items.push_back({ 
            i + 1, 
            c[i], 
            w[i], 
            static_cast<double>(c[i]) / w[i] 
        });
    }
    
    sort(begin(items), end(items), &items_sort);
    
    cout << "sorted (ratio) = ";
    for (const Item& item : items) {
        cout << item.ratio << " ";
    }
    cout << endl;
    
    vector<int> selected_items;
    vector<double> parts;
    double knapsack_value = 0;
    double knapsack_weight = 0;
    int i = 0;
    while (i < n && static_cast<double>(W) - items[i].weight > EPS) {
        selected_items.push_back(items[i].idx);
        parts.push_back(1);
        knapsack_value += items[i].cost;
        knapsack_weight += items[i].weight;
        W -= items[i].weight;
        ++i;
    }
    double delta = 0;
    if (i < n && W > 0) {
        double p = static_cast<double>(W) / items[i].weight;
        selected_items.push_back(items[i].idx);
        parts.push_back(p);
        knapsack_value += items[i].cost;
        knapsack_weight += p * items[i].weight;
        W -= p * items[i].weight;
    }
    
    cout << "items selected: ";
    for (const int& items_idx : selected_items) {
        cout << items_idx << " ";
    }
    cout << '\n';
    cout << "item part: ";
    for (const double& part : parts) {
        cout << part << " ";
    }
    cout << '\n';
    cout << "knapsack_value: " << knapsack_value << '\n';
    cout << "knapsack_weight: " << knapsack_weight << '\n';
    
    return 0;
}
