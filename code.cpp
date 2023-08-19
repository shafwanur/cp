/**
 *    author:  shaf1
 *    created: 07.08.2023 21:35:35
**/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
  #include "C:\Users\shafw\Documents\cp\debug.h"
#else
  #define debug(...) 42
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  map<int, int> cnt;
  for (int i = 0; i < (n * (n - 1)) / 2; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
    if (cnt[x] == 1) {
      a.push_back(x);
    }
  }
  int m = (int) a.size();
  sort(a.begin(), a.end());
  vector<int> b;
  for (int i = m - 1; i >= 0; i--) {
    int cur = cnt[a[i]] - ((m - i - 1) + (int) b.size());
    debug(a[i], cur, b);
    while (cur--) {
      b.push_back(a[i]);
    }
  }
  for (int x : a) {
    cout << x << ' ';
  }
  for (int x : b) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
