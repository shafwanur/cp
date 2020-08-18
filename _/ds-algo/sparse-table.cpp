struct ST {
  vector<int> log;
  vector<vector<int>> st;
  
  void build(int n, int k, vector<int>& a) {
    for (int i = 2; i <= n; i++) {
      log[i] = log[i / 2] + 1;
    }
    for (int i = 0; i < n; i++) {
      st[i][0] = a[i];
    }
    for (int j = 1; j < k; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  
  int query(int l, int r) {
    int j = log[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
  }

  ST(int n, int k, vector<int>& a) {
    log.resize(n + 1);
    st.resize(n, vector<int>(k));
    build(n, k, a);
  }
};
