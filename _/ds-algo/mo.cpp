#include "bits/stdc++.h"
using namespace std;

const long long N = 2e5 + 5;
const long long k = sqrt(N - 5);

struct Query {
    long long l, r;
    long long id;
} Q[N];

long long a[N], f[(int) 1e6 + 5];
long long res = 0, ans[N];

void add(long long x) {
    res -= f[a[x]] * 1LL * f[a[x]] * a[x];
    f[a[x]]++;
    res += f[a[x]] * 1LL * f[a[x]] * a[x];
}

void remove(long long x) {
    res -= f[a[x]] * 1LL * f[a[x]] * a[x];
    f[a[x]]--;
    res += f[a[x]] * 1LL * f[a[x]] * a[x];
}

int main() { 
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (long long i = 0; i < m; i++) {
        scanf("%lld %lld", &Q[i].l, &Q[i].r);
        --Q[i].l, --Q[i].r;
        Q[i].id = i;
    }
    sort(Q, Q + m, [&](Query x, Query y) {
        long long k_x = x.l / k, k_y = y.l / k;
        if (k_x == k_y) return x.r < y.r;
        return k_x < k_y;
    });
    long long l = 0, r = -1;
    for (long long i = 0; i < m; i++) {
        while (l > Q[i].l) add(--l);
        while (r < Q[i].r) add(++r);
        while (l < Q[i].l) remove(l++);
        while (r > Q[i].r) remove(r--);
        ans[Q[i].id] = res;
    }
    for (long long i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
}

// Solution to Codeforces - Powerful Array