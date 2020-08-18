#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Edge {
    int u, v;
    long long c;

    Edge (int u, int v, long long c) : u(u), v(v), c(c) {}
    bool operator < (Edge const& e) {
        return c < e.c;
    }
};

int par[N], _rank[N];

void init(int u) {
    par[u] = u;
    _rank[u] = 0;
}

int find(int u) {
    if (par[u] == u) {
        return u;
    }
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (_rank[u] < _rank[v]) {
            swap(u, v);
        }
        par[v] = u;
        if (_rank[u] == _rank[v]) {
            ++_rank[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++) {
        init(i);
    }
    sort(edges.begin(), edges.end());
    long long cost = 0;
    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            cost += e.c; 
        }
    }
    cout << cost << '\n';
}