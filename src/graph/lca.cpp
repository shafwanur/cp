#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 20;

int dep[N], id[N];
vector<int> g[N];
vector<int> euler;

void dfs(int u, int par = -1, int h = 0) {
  dep[u] = h;
  id[u] = (int) euler.size();
  euler.push_back(u);
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u, h + 1);
    euler.push_back(u);
  }
}

struct SparseTable {
  int st[N][K], log[N];
  
  void init(vector<int>& a) {
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
      st[i][0] = a[i];
    }
    for (int j = 1; j < K; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
    for (int i = 2; i <= n; i++) {
      log[i] = log[i / 2] + 1;
    }
  }
  
  int query(int l, int r) {
    int j = log[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
  }
} t;

int lca(int u, int v) {
  int l = id[u], r = id[v];
  if (l > r) swap(l, r);
  return t.query(l, r);
}

int dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  t.init(euler);
  cout << lca(3, 5) << '\n';
}

/* Notes - 
 * lca(u, v) is x iff dist[u][x] + dist[x][v] + dist[x][root] is minimum possible.
**/
