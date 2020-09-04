#include <bits/stdc++.h>
#include "_/templates/printer.h"

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

int main() {
  int n = rand(1, 10);
  vector<int> a = get_array(n, 1, 100);
  print(n);
  print(a);
}
