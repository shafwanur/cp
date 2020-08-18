#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int p[N];

void prefix_function(string s) {
  int n = (int) s.size();
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 and s[i] != s[j]) {
      j = p[j - 1];
    }
    p[i] = j + (s[i] == s[j]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  prefix_function(s);
  for (int i = 0; i < n; i++) {
    cout << p[i] << ' ';
  }
}

