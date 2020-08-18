#include "bits/stdc++.h"
using namespace std;

const int N = (int)1e5 + 5;

int n, m;
vector <int> g[N];
int vis[N], d[N], f[N], t, a[N];

void euler_tour(int u) {
	vis[u] = 1;
	d[u] = ++t;
  a[t] = u;
	for (int v : g[u]) {
		if (!vis[v]) euler_tour(v);
	}
	f[u] = t;
}

int main() { 
    scanf("%d %d", &n, &m);
    while (m--) {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    euler_tour(1);
    for (int u = 1; u <= n; ++u) {
    	printf("Discovery time of node %d is %d, finishing time is %d.\n", u, d[u], f[u]);
    }
}

/* Sample IO:
4 3
1 2
2 3
3 4

Discovery time of node 1 is 1, finishing time is 4.
Discovery time of node 2 is 2, finishing time is 4.
Discovery time of node 3 is 3, finishing time is 4.
Discovery time of node 4 is 4, finishing time is 4.
