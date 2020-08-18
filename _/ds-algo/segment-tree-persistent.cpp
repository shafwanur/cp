#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct node {
    node *left, *right;
    int sum;

    node(): left(nullptr), right(nullptr), sum(0) {}
    node(node *l, node *r, int x): left(l), right(r), sum(x) {}
} *t[N];

void init(node *u, int b, int e) {
    if (b == e) {
        u->sum = a[b];
        return;
    }
    int m = (b + e) >> 1;
    u->left = new node();
    u->right = new node();
    init(u->left, b, m);
    init(u->right, m + 1, e);
    u->sum = u->left->sum + u->right->sum;
}

void upd(node *u, node *v, int b, int e, int i, int x) {
    if (i < b or i > e) return;
    if (b == i and i == e) {
        v->sum = u->sum + x;
        return;
    }
    int m = (b + e) >> 1;
    if (i <= m) {
        v->right = u->right;
        v->left = new node();
        upd(u->left, v->left, b, m, i, x);
    } else {
        v->left = u->left;
        v->right = new node();
        upd(u->right, v->right, m + 1, e, i, x);
    }
    v->sum = v->left->sum + v->right->sum;
}

int q(node *u, int b, int e, int i, int j) {
    if (j < b or i > e) return 0;
    if (i <= b and e <= j) return u->sum;
    int m = (b + e) >> 1;
    return q(u->left, b, m, i, j) + q(u->right, m + 1, e, i, j);
}

int main() { 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    t[0] = new node();
    init(t[0], 1, n);
    int Q;
    cin >> Q;
    int k = 0;
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int v, i, x;
            cin >> v >> i >> x;
            ++k;
            t[k] = new node();
            upd(t[v], t[k], 1, n, i, x);
        }
        if (cmd == 2) {
            int v, l, r;
            cin >> v >> l >> r;
            cout << q(t[v], 1, n, l, r) << endl;
        }
    }
}

// Solution to SPOJ PSEGTREE 