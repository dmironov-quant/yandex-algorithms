// Задача F: N-функция
// Следует вычислить N-функция для строки, 
// которая подается на вход


// N-функция определяется как 
// nf[i] = max_{k}  ( s[0...k] == s[i...i+k] )
// nf[0] - можно взять любым, зависит от задачи


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
using namespace std;


vector<int> bruteforce_solution(const string& s) {
  int n = static_cast<int>(s.size());
  vector<int> nf(n, 0);
  for (int i = 1; i < n; ++i) {
    while ( (i + nf[i] < n) && (s[nf[i]] == s[i + nf[i]]) ) {
      ++nf[i];
    }
  }
  return nf;
}


vector<int> optimal_solution(const string& s) {
  int n = static_cast<int>(s.size());
  vector<int> nf(n, 0);
  int l = 0;
  int r = 0;
  for (int i = 1; i < n; ++i) {
    if (r > i) {
      nf[i] = min(nf[i-l], r-i);
    }
    while ( (i + nf[i] < n) && (s[nf[i]] == s[i + nf[i]]) ) {
      ++nf[i];
    }
    if (i + nf[i] > r) {
      l = i;
      r = i + nf[i];
    }
  }
  return nf;
}


void test01() {
  random_device rd;
  mt19937 gen(rd());
  
  uniform_int_distribution<> n_tests(3, 10);  
  
  const vector<int> alphabet{'a','b','c','d','e','f','g', 'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  int t = n_tests(gen);
  int cnt_errors = 0;

  while (t--) {
    
    uniform_int_distribution<> array_size(10, 100);
    int n = array_size(gen);
    
    uniform_int_distribution<> idx(0, static_cast<int>(alphabet.size()));
    
    string s="";
    for (int i = 0; i < n; ++i) {
      int j = idx(gen);
      s += alphabet[j];
    }
    
    vector<int> nf_bf = bruteforce_solution(s);
    vector<int> nf_opt = optimal_solution(s);
    
    if (nf_bf != nf_opt) {
      ++cnt_errors;
    }
  }
  
  if (cnt_errors == 0) {
    cout << "ALL TESTS " << "in test01()" << " OK!\n";
  }
  else {
    cout << "ERRORS FOUND!";
  }
}


void test02() {
  random_device rd;
  mt19937 gen(rd());
  
  uniform_int_distribution<> n_tests(3, 10);  
  
  const vector<int> alphabet{'a','b','c'};
  
  int t = n_tests(gen);
  int cnt_errors = 0;

  while (t--) {
    
    uniform_int_distribution<> array_size(10, 20);
    int n = array_size(gen);
    
    uniform_int_distribution<> idx(0, static_cast<int>(alphabet.size()));
    
    string s="";
    for (int i = 0; i < n; ++i) {
      int j = idx(gen);
      s += alphabet[j];
    }
    
    vector<int> nf_bf = bruteforce_solution(s);
    vector<int> nf_opt = optimal_solution(s);
    
    if (nf_bf != nf_opt) {
      ++cnt_errors;
    }
  }
  
  if (cnt_errors == 0) {
    cout << "ALL TESTS " << "in test02()" << " OK!\n";
  }
  else {
    cout << "ERRORS FOUND!";
  }
}


void test03() {
  random_device rd;
  mt19937 gen(rd());
  
  uniform_int_distribution<> n_tests(3, 10);  
  
  const vector<int> alphabet{'a','b'};
  
  int t = n_tests(gen);
  int cnt_errors = 0;

  while (t--) {
    
    uniform_int_distribution<> array_size(10, 20);
    int n = array_size(gen);
    
    uniform_int_distribution<> idx(0, static_cast<int>(alphabet.size()));
    
    string s="";
    for (int i = 0; i < n; ++i) {
      int j = idx(gen);
      s += alphabet[j];
    }
    
    vector<int> nf_bf = bruteforce_solution(s);
    vector<int> nf_opt = optimal_solution(s);
    
    if (nf_bf != nf_opt) {
      ++cnt_errors;
    }
  }
  
  if (cnt_errors == 0) {
    cout << "ALL TESTS " << "in test03()" << " OK!\n";
  }
  else {
    cout << "ERRORS FOUND!";
  }
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  test01();
  test02();
  test03();
  
  // additional TESTS
  {
    string s = "abacaba";
    vector<int> nf_bf = bruteforce_solution(s); 
    vector<int> nf_opt = optimal_solution(s);
    if (nf_bf != nf_opt) {
      cout << "ERROR FOUND in " << s << "TEST!" << '\n';
    }
    else {
      cout << "EXAMPLE01 from lecture is OK!\n";
    }
  }
  
  {
    string s = "aaabbaabb";
    vector<int> nf_bf = bruteforce_solution(s);
    vector<int> nf_opt = optimal_solution(s);
    if (nf_bf != nf_opt) {
      cout << "ERROR FOUND in " << s << "TEST!" << '\n';
    }
    else {
      cout << "EXAMPLE02 from lecture is OK!\n";
    }
  }
  
  return 0;
}
