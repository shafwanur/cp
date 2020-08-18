#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 5;
const int M = 5000 + 5;

vector<int> g[N];
vector<int> visit;

int match[N];

bool dfs(int u) {
    if (visit[u]) return false;
    visit[u] = true;
    for (int v : g[u]) {
        if (!match[v]) {
            match[v] = u;
            return true;
        } else if (match[v] != u and dfs(v)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, e;
    cin >> n >> m >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(match, 0, sizeof match);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        visit.assign(n + 1, false);
        cnt += dfs(i);
    }
    cout << "Maximum Matching: " << cnt << '\n';
    for (int u = 1; u <= n; u++) {
        cout << u << " is matched to " << match[u] << '\n';
    }
}


