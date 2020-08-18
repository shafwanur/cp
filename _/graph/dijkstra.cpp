void dijkstra(vector<vector<int>>& g, vector<ll>& dist) {
  int n = (int) g.size() - 1;
  vector<bool> visited(n + 1, 0);

  int root = 1;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.emplace(0, root);
  dist[root] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (visited[u]) {
      continue;
    }
    visited[u] = 1;
    for (auto i : g[u]) {
      int v = i.first, c = i.second;
      if (dist[v] > dist[u] + 1LL * c) {
        dist[v] = dist[u] + 1LL * c;
        q.emplace(dist[v], v);
      }
    }
  }
}
