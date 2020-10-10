#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, t, tin[N], low[N], vis[N], bridge[N];
vector<int> g[N];
map<pair<int, int>, int> edge;

void dfs(int u, int par = -1) {
    vis[u] = 1;
    tin[u] = low[u] = t++;
    for (int v : g[u]) {
        if (v == par) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                int id = edge[{u, v}];
                bridge[id] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[{u, v}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (bridge[i]) {
            cout << i << ' ';
        }
    }
}
