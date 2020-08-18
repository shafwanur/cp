#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int deg[N];
vector<int> path;
set<int> g[N];

void dfs(int u) {
    while (!g[u].empty()) {
        int v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        dfs(v);
    }
    path.push_back(u);
}

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        ++deg[u], ++deg[v];
    }
    int cnt = 0, st = 1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            ++cnt;
            st = i;
        }
    }
    if (cnt > 2) {
        cout << "Impossible" << '\n';
        return 0;
    }
    dfs(st);
    reverse(path.begin(), path.end());
    for (int u : path) {
        cout << u << ' ';
    }
}
