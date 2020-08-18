#include <bits/stdc++.h>
#include "_/templates/printer.h"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
  uniform_int_distribution<int> get(l, r); 
  return get(rng);
}

void shuffle(vector<int>& a) {
  shuffle(a.begin(), a.end(), rng);
}

int main() {
  cout << 1 << '\n';
  int n = rand(1, 10);
  int k = rand(1, 5);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = rand(-10, 10);
  }
  print(n, k);
  print(a);
}
