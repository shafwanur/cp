struct SGT {
  vector<int> t;
  vector<int> add;

  void build(int u, int b, int e, vector<int>& a) {
    if (b == e) {
      return void(t[u] = a[b]);
    } 
    int mid = (b + e) >> 1;
    build(u << 1, b, mid, a);
    build(u << 1 | 1, mid + 1, e, a);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }
  
  void relax(int u, int b, int e) {
    if (add[u]) {
      t[u] += (e - b + 1) * add[u];
      if (b != e) {
        add[u << 1] += add[u];
        add[u << 1 | 1] += add[u];
      }
      add[u] = 0;
    }
  }

  void update(int u, int b, int e, int i, int j, int x) {
    relax(u, b, e);
    if (j < b or i > e) return; 
    if (i <= b and e <= j) {
      add[u] += x;
      relax(u, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    update(u << 1, b, mid, i, j, x);
    update(u << 1 | 1, mid + 1, e, i, j, x);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }

  int query(int u, int b, int e, int i, int j) {
    relax(u, b, e);
    if (j < b or i > e) return 0;
    if (i <= b and e <= j) return t[u];
    int mid = (b + e) >> 1;
    return query(u << 1, b, mid, i, j) + query(u << 1 | 1, mid + 1, e, i, j);
  }

  SGT(int n, vector<int>& a) {
    t.resize(n * 4);
    add.resize(n * 4);
    build(1, 1, n, a);
  }
};
