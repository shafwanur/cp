struct dsu {
  vector<int> p;
  vector<int> r;

  dsu(int n) {
    p.resize(n + 1);
    r.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      r[i] = 0;
    }
  }
  
  int find(int u) {
    if (p[u] == u) {
      return u;
    } 
    return p[u] = find(p[u]);
  }

  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      if (r[u] < r[v]) {
        swap(u, v);
      }
      p[v] = u;
      r[u] += r[v];
    }
  }
};
