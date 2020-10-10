#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m, in[N], out[N];
vector<int> g[N];
vector<int> path;

void dfs(int u) {
    while (g[u].size()) {
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ++in[v], ++out[u];
    }
    int cnt = 0, st = 0;
    for (int i = 0; i < n; i++) {
        cnt += abs(in[i] - out[i]);
        if (out[i] - in[i] == 1) {
            st = i;
        }
    }
    if (cnt > 2) {
        cout << "Impossible" << '\n';
        return 0;
    }
    dfs(st);
    if ((int) path.size() != m + 1) {
        cout << "Impossible" << '\n';
        return 0;
    }
    reverse(path.begin(), path.end());
    for (int u : path) {
        cout << u << ' ';
    }
    cout << '\n';
}
