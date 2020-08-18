#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1000 + 10;

int n, m, dis[N], cnt[N], inq[N], par[N];
vector<pii> g[N];

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        g[u].emplace_back(v, cost);
    }
    queue<int> q;
    int s = 1;
    dis[s] = 0;
    q.push(s);
    inq[s] = 1;
    bool ok = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (auto p : g[u]) {
            int v = p.first, cost = p.second;
            if (dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                    par[v] = u;
                    ++cnt[v];
                }
            }
        }
        if (cnt[u] > n) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "Negative Cycle exists" << '\n';
        return 0;
    }
}   