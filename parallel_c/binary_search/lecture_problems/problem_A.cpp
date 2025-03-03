// Задача 1 с лекции 
// Угадай число 
// Друг загадывает число от 1 до MAXN (обозначим его за х)
// Наша задача отгадать это число
// Когда мы называем число, то друг говорит называли ли мы большее или меньшее число 


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <random>
using namespace std;


const int MAXN = numeric_limits<int>::max();


int guesser(int n, int x) {
  int left = 1;
  int right = n;
  int guess = -1;
  while (right >= left) {
    int middle = left + (right - left) / 2;
    if (middle == x) {
      guess = middle;
      break;
    }
    else if (middle > x) {
      right = middle - 1;
    }
    else {
      left = middle + 1;
    }
  }
  return guess;
}


int guesser2(int n, int x) {
  int left = 0;
  int right = n;
  int guess = -1;
  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (middle < x) {
      left = middle;
    }
    else {
      right = middle;
    }
  }
  return right;
}


int guess3(int n, int x) {
  int left = 1;
  int right = n + 1;
  while (right > left + 1) {
    int middle = left + (right - left) / 2;
    if (middle <= x) {
      left = middle;
    }
    else {
      right = middle;
    }
  }
  return left;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  random_device rd;
  mt19937 gen(rd());
  
  uniform_int_distribution<> n_tests(1000, 10000);
  
  int cnt_errors = 0;
  
  int k = n_tests(gen);
  while (k--) {
    uniform_int_distribution<> number_to_guess(1, MAXN);
    int x = number_to_guess(gen);
    int guess = guesser(MAXN, x);
    int guess2 = guesser(MAXN, x);
    int guess3 = guesser(MAXN, x);
    if (x != guess || x != guess2 || x != guess3) {
      ++cnt_errors;
    }
  }
  
  if (cnt_errors == 0) {
    cout << "ALL TESTS PASSED, OK!";
  }
  else {
    cout << "ERRORS FOUND!";
  }
  
  return 0;
}
