#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = log2(N) + 1;

int n, par[N][K];
vector<int> g[N];

void init() {
    for (int j = 1; j < K; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int kth_par(int u, int k) {
    int v = u;
    for (int j = K - 1; j >= 0; j--) {
        if (par[v][j] != 0 and (1 << j) <= k) {
            v = par[v][j];
            k -= (1 << j);
        }
    }
    return v;
}

int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        par[v][0] = u;
    }
    init(); 
    cout << kth_par(2, 1) << '\n';
}