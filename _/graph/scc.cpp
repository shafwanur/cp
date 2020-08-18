#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, t = 0;
vector<int> g[N], gt[N], cmp[N];
vector<int> ord, col;

vector<int> gc[N];

void euler(int u) {
    col[u] = 1;
    for (int v : g[u]) {
        if (!col[v]) {
            euler(v);
        }
    }
    ord.push_back(u);
}

void dfs(int u) {
    col[u] = t;
    cmp[t].push_back(u);
    for (int v : gt[u]) {
        if (!col[v]) {
            dfs(v);
        }
    }
}

void scc() {
    col.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            euler(i);
        }
    }
    reverse(ord.begin(), ord.end());
    col.assign(n + 1, 0);
    for (int u : ord) {
        if (!col[u]) {
            ++t;
            dfs(u);
        }
    }
}

void make() {
    map<pair<int, int>, int> f;
    for (int i = 1; i <= t; i++) {
        for (int u : cmp[i]) {
            for (int v : g[u]) {
                int id = col[v];
                if (id != i) {
                    if (f.find({i, id}) == f.end()) {
                        gc[i].push_back(id);
                        f[{i, id}] = 1;
                    }
                }
            }
        }
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
        gt[v].push_back(u);
    }
    scc();
    make();
    for (int i = 1; i <= t; i++) {
        if (gc[i].empty()) continue;
        cout << "Component " << i << " is connected to component ";
        for (int u : gc[i]) {
            cout << u << ' ';
        }
        cout << '\n';
    }
}

// g = original graph
// gt = transposed graph
// ord = vertices sorted by decreasing finish time
// t = total number of components
// col = in first dfs it's used as a visited array, in second dfs, col[i] stores the component in which i belongs to.
// cmp[i] = members of component i
// gc = the final graph
/* f = if there doesn't exist an edge between {u, v}, then only add edge between {u, v}. 
       I noticed my way of doing it might introduce duplicate edges, so I used this map.
*/
