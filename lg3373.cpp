#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;
using ll = long long;

ll p;

struct Node {
    ll sum;
    int a, b, l, r;
    Node() { sum=b=l=r=0; a=1; }
} t[400007];

inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
inline void refresh(int x) { t[x].sum = (t[ls(x)].sum+t[rs(x)].sum) % p; }

void apply(int x, ll a, ll b) {
    t[x].sum = (t[x].sum*a + (t[x].r-t[x].l+1)*b) % p;
    t[x].a = t[x].a*a % p;
    t[x].b = (a*t[x].b + b) % p;
}

void push(int x) {
    apply(ls(x), t[x].a, t[x].b);
    apply(rs(x), t[x].a, t[x].b);
    t[x].a = 1, t[x].b = 0;
}

void build(int x, int l, int r) {
    t[x].l = l, t[x].r = r;
    if (l<r) {
        int mid = (l+r) >> 1;
        build(ls(x), l, mid);
        build(rs(x), mid+1, r);
    }
}

void update(int x, int l, int r, int a, int b) {
    auto& n = t[x];
    if (n.l>r || n.r<l) return;
    if (n.l>=l && n.r<=r)
        apply(x, a, b);
    else {
        push(x);
        update(ls(x), l, r, a, b);
        update(rs(x), l, r, a, b);
        refresh(x);
    }
}

ll query(int x, int l, int r) {
    auto& n = t[x];
    if (n.l>r || n.r<l) return 0;
    if (l<=n.l && n.r<=r) 
        return n.sum;
    else {
        push(x);
        return (query(ls(x), l, r) + query(rs(x), l, r)) % p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m >> p;

    build(1, 1, n);

    for (int x,i=1; i<=n; ++i) {
        cin >> x;
        update(1, i, i, 1, x);
    }

    for (int c, x, y, k; m; --m) {
        cin >> c >> x >> y;
        if (c==1) {
            cin >> k;
            update(1, x, y, k, 0);
        } else if (c==2) {
            cin >> k;
            update(1, x, y, 1, k);
        } else 
            cout << query(1, x, y) << '\n';
    }
    return 0;
}