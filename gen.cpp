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
     
}
