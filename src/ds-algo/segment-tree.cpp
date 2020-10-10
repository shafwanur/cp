struct SGT {
  vector<int> t;

  void build(int u, int b, int e, vector<int>& a) {
    if (b == e) {
      t[u] = a[b];
      return;
    } 
    int mid = (b + e) >> 1;
    build(u << 1, b, mid, a);
    build(u << 1 | 1, mid + 1, e, a);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }
  
  int query(int u, int b, int e, int i, int j) {
    if (i > e or j < b) return 0;
    if (i <= b and e <= j) return t[u];
    int mid = (b + e) >> 1;
    return query(u << 1, b, mid, i, j) + query(u << 1 | 1, mid + 1, e, i, j);
  }

  void update(int u, int b, int e, int i, int x) {
    if (i > e or i < b) return;
    if (b >= i and e <= i) return void(t[u] = x);
    int mid = (b + e) >> 1;
    update(u << 1, b, mid, i, x);
    update(u << 1 | 1, mid + 1, e, i, x);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }

  SGT(int n, vector<int>& a) {
    t.resize(n * 4, 0);
    build(1, 1, n, a);
  }
};
