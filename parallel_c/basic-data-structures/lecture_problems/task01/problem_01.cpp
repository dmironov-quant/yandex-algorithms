// Task 01 from the lecture of week04
// basic-data-structures
//
// For every i-th element find the closest element to its left such
// that j-th element, where i > j, is smaller than i-th: a[j] < a[i]
// and j is max
//
// Input:
// 	array of strictly positive integers: a[i] > 0 for any i
// 
// Output:
//	array of indices with elements


#include <iostream>
#include <vector>
#include <random>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<> test_n(100, 1000);
    int k = test_n(gen);
    
    int count_errors = 0;
    while (k--) {
        uniform_int_distribution<> size(100, 1000);
        int n = size(gen);
        vector<int> a(n + 1, 0);
        uniform_int_distribution<> element(1, 100);
        for (int i = 1; i <= n; ++i) {
            int x = element(gen);
            a[i] = x;
        }
        
        // algorithmic solution: time-complexity O(n)
        vector<int> algo(n + 1, 0);
        vector<int> stack; // monotonic stack containing indecies
        stack.push_back(0); // stack cannot be empty size 0 is the smallest element possible
        for (int i = 1; i <= n; ++i) {
            int curr = a[i];
            while (curr <= a[stack.back()]) {
                stack.pop_back();
            }
            algo[i] = stack.back();
            stack.push_back(i);
        }
        
        // brute force solution: time-complexity O(n^2)
        vector<int> expected_answer(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (a[i] > a[j]) {
                    expected_answer[i] = j;
                    break;
                }
            }
        }
        
        if (algo != expected_answer) {
            ++count_errors;
        }
        
    }
    
    if (count_errors > 0) {
        std::cout << "ERRORS FOUND!" << '\n';
        std::cout << "NUMBER OF ERRORS=" << count_errors << '\n';
    }
    else {
        std::cout << "OK!" << '\n';
        std::cout << "ALL TEST PASSED" << '\n';
    }
    
    return 0;
}
