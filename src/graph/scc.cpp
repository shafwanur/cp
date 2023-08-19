struct SCC {
  int n, t = 0;
  vector<int> ord, col;
  vector<vector<int>> g;
  vector<vector<int>> gt;
  vector<vector<int>> cmp;

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

  SCC(int _n, vector<vector<int>>& _g) {
    n = _n;
    g = _g;
    gt.resize(n + 1);
    cmp.resize(n + 1);
    for (int u = 1; u <= n; u++) {
      for (int v : g[u]) {
        gt[v].push_back(u);
      }
    }
    scc();
  }
};
