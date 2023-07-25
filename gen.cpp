#include <bits/stdc++.h>
#include "src/snippets/printer.h"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
  uniform_int_distribution<int> get(l, r); 
  return get(rng);
}

vector<int> get_array(int n, int l, int r) {
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = rand(l, r);
  }
  return a;
}

void shuffle(vector<int>& a) {
  shuffle(a.begin(), a.end(), rng);
}

void print(vector<int>& a) {
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  cout << 1 << '\n';
  int n = rand(1, 15);
  vector<int> a = get_array(n, 1, n + 1);
  cout << n << '\n';
  print(a);
}
