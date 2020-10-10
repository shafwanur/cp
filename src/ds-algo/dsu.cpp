struct dsu {
  vector<int> p;
  vector<int> r;

  dsu(int n) {
    p.resize(n + 1);
    r.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      r[i] = 1;
    }
  }
  
  int find(int u) {
    if (p[u] == u) {
      return u;
    } 
    return p[u] = find(p[u]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      (r[u] < r[v] ? swap(u, v) : void());
      p[v] = u;
      r[u] += r[v];
      return true;
    }
    return false;
  }
};
