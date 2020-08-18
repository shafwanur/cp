#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, vis[N], t = 0, tin[N], low[N], ap[N];
vector<int> g[N];

void dfs(int u, int par = -1) {
    vis[u] = 1;
    tin[u] = low[u] = ++t;
    int child = 0;
    for (int v : g[u]) {
        if (v == par) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] and par != -1) {
                ap[u] = 1;
            }
            ++child;
        }
    }
    if (par == -1 and child > 1) {
        ap[u] = 1;
    }
}

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ap[i]) {
            cout << i << ' ';
        }
    }
}