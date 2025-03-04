// Задача С: Гистограмма 


#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <queue>
#include <numeric>
#include <limits>
using namespace std;


const int MAX = numeric_limits<int>::max();


struct Node {
    int minimum;
    int index;
};


Node combine(Node a, Node b) {
    if (a.minimum > b.minimum) {
        return b;
    }
    return a;
}


struct Segtree {
    vector<Node> tree;
    int size;
    
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size - 1, {MAX, 0});
    }
    
    void build(const vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[x] = { a[lx], lx };
            }
        }
        else {
            int m = lx + (rx - lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }
    
    void build(const vector<int>& a) {
        init((int)a.size());
        build(a, 0, 0, size);
    }
    
    Node get_minimum(int l, int r, int x, int lx, int rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        if (lx >= r || rx <= l) {
            return {MAX, 0};
        }
        int m = lx + (rx - lx) / 2;
        Node m1 = get_minimum(l, r, 2 * x + 1, lx, m);
        Node m2 = get_minimum(l, r, 2 * x + 2, m, rx);
        return combine(m1, m2);
    }
    
    Node get_minimum(int l, int r) {
        return get_minimum(l, r, 0, 0, size);
    }
    
};


struct Interval {
    int left;
    int right;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    Segtree st;
    st.build(heights);
    
    int64_t max_area = 0;
    
    queue<Interval> q;
    q.push({0, n});
    
    while (!q.empty()) {
        Interval interval = q.front();
        q.pop();
        int left = interval.left;
        int right = interval.right;
        Node node = st.get_minimum(left, right);
        int minimum = node.minimum;
        int index = node.index;
        int64_t curr_area = static_cast<int64_t>(minimum) * (right - left);
        if (max_area < curr_area) {
            max_area = curr_area;
        }
        if (index > left) {
            q.push({left, index});
        }
        if (right > index + 1) {
            q.push({index + 1, right});
        }        
    }
    
    cout << max_area;
    
    return 0;
}
















































