#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
  #include "C:\Users\shafw\Documents\[archived] coding\cp\debug.h"
#else
  #define debug(...) 42
  #define int long long
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  int type = -1;
  for (int stage = 1; stage <= 2; stage++) {
    cout << "- 0" << '\n';
    cout.flush();
    map<int, int> new_cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      new_cnt[a[i]] += 1;
    }
    for (int c = 1; c <= 9; c++) {
      if (cnt[c] == new_cnt[c] - 1) {
        type = c;
        break;
      }
    }
    cnt = new_cnt;
    if (type != -1) {
      break;
    }
  }
  vector<int> to_remove;
  for (int i = 0; i < n; i++) {
    if (a[i] != type) {
      to_remove.push_back(i + 1);
    }
  }
  cout << "- " << (int) to_remove.size() << ' ';
  cout.flush();
  for (int id : to_remove) {
    cout << id << ' ';

    cnt[a[id - 1]] -= 1;
    cout.flush();
  }
  cout << '\n';
  cout.flush();

  n -= (int) to_remove.size();
  a.resize(n);
  type = -1;
  for (int stage = 1; stage <= 2; stage++) {
    map<int, int> new_cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      new_cnt[a[i]] += 1;
    }
    for (int c = 1; c <= 9; c++) {
      if (cnt[c] == new_cnt[c] - 1) {
        type = c;
        break;
      }
    }
    if (type != -1) {
      break;
    }
    cout << "- 0" << '\n';
    cout.flush();
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == type) {
      cout << "! " << i + 1 << '\n';
      cout.flush();
      return;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
