struct SGT {
  vector<vector<int>> t;

  void build(int u, int b, int e, vector<int>& a) {
    if (b == e) {
      t[u].push_back(a[b]);
      return;
    }
    int l = u << 1;
    int r = u << 1 | 1;
    int mid = (b + e) >> 1;
    build(l, b, mid, a);
    build(r, mid + 1, e, a);
    merge(t[l].begin(), t[l].end(), t[r].begin(), t[r].end(), back_inserter(t[u]));
  }

  int query(int u, int b, int e, int i, int j, int k) {
    if (j < b or e < i) return 0;
    if (i <= b and e <= j) {
      auto it = lower_bound(t[u].begin(), t[u].end(), k);
      return it - t[u].begin();
    }
    int mid = (b + e) >> 1;
    return query(u << 1, b, mid, i, j, k) + query(u << 1 | 1, mid + 1, e, i, j, k);
  }

  SGT(int n, vector<int>& a) {
    t.resize(n * 4);
    build(1, 1, n, a);
  }
};
