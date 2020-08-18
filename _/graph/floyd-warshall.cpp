#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, (ll) 1e18));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    dist[u][v] = min(dist[u][v], 1LL * c);
    dist[v][u] = min(dist[v][u], 1LL * c);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != (ll) 1e18 and dist[k][j] != (ll) 1e18) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u == v) {
      dist[u][v] = 0;
    } 
    if (dist[u][v] == (ll) 1e18) {
      dist[u][v] = -1;
    }
    cout << dist[u][v] << '\n';
  }
}
