#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;
const int k = cbrt(N * N);
 
struct Query {
    int l, r;
    int t;
    int id;
} q[N];
 
struct Update {
    int x;
    int prev, curr;
} upd[N];
 
int n, m;
int a[N], b[N];
int temp[N];
int f[N];
int c, x, y;
int t, id;
int l = 0, r = -1;
 
long long res = 0;
long long ans[N];
 
void in(int x) {
    ++f[a[x]];
    res += 1LL * b[f[a[x]] - 1] * a[x];
}
 
void out(int x) {
    res -= 1LL * b[f[a[x]] - 1] * a[x];
    --f[a[x]];
}
 
void apply(int x, int y) {
    if (l <= x and x <= r) {
        out(x);
        a[x] = y;
        in(x);
    } else a[x] = y;
}
 
int main() { 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &c, &x, &y);
        if (c == 1) {
            --x, --y;
            q[id].l = x, q[id].r = y, q[id].t = t, q[id].id = id;
            ++id;
        } else {
            --x, ++t;
            upd[t].x = x, upd[t].prev = temp[x], upd[t].curr = y;
            temp[x] = y;
        }
    }
    sort(q, q + id, [&](Query x, Query y) {
        int l_x = x.l / k, l_y = y.l / k;
        int r_x = x.r / k, r_y = y.r / k;
        if (l_x != l_y) return l_x < l_y;
        if (r_x != r_y) return r_x < r_y;
        return x.t < y.t;
    });
    t = 0;
    for (int i = 0; i < id; i++) {
        while (t < q[i].t) t++, apply(upd[t].x, upd[t].curr);
        while (t > q[i].t) apply(upd[t].x, upd[t].prev), t--;
 
        while (l > q[i].l) in(--l);
        while (l < q[i].l) out(l++);
        while (r < q[i].r) in(++r);
        while (r > q[i].r) out(r--);
 
        ans[q[i].id] = res;
    }
    for (int i = 0; i < id; i++) {
        printf("%lld\n", ans[i]);
    }
} 

// Solution to SPOJ HRSIAM