#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  vector<int> a;
  int k;
  vector<int> b;
  auto input = [&]() {
    ifstream cin("in");
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> k;
    b.resize(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
  };
  input();

  string s;
  cin >> s;
  if (s == "YES") {
    int i; char c;
    while (cin >> i >> c) {
      --i;
      int j = i;
      (c == 'L' ? --j : ++j);
      a[i] += a[j];
      a.erase(a.begin() + j);
    }
    cout << (a == b ? "YES" : "NO") << '\n';
  } 
  else {
    cout << "NO" << '\n';
  }
}
