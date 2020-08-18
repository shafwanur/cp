#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, t = 0;

vector<int> g[N], gt[N], cmp[N];
vector<int> ord, col;
vector<int> gc[N];

void euler(int u) {
  col[u] = 1;
  for (int v : g[u]) {
    if (!col[v]) {
      euler(v);
    }
  }
  ord.push_back(u);
}

void dfs(int u) {
  col[u] = t;
  cmp[t].push_back(u);
  for (int v : gt[u]) {
    if (!col[v]) {
      dfs(v);
    }
  }
}

void scc() {
  col.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!col[i]) {
      euler(i);
    }
  }
  reverse(ord.begin(), ord.end());
  col.assign(n + 1, 0);
  for (int u : ord) {
    if (!col[u]) {
      ++t;
      dfs(u);
    }
  }
}

int main() { 
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    gt[v].push_back(u);
  }
  scc();
}
