#include <vector>
#include <algorithm>
#include <cstdio>
#define REP(i,a,b) for (int i=(a);i<=(b);++i)

using ll = long long;
using namespace std;

struct Node {
    int l, r;
    ll a, b, v; // a*v + b;
} t[400007]; 

int n, a[100007];
ll M;

inline int get_mid(int l, int r) { return (l+r)>>1; }
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }
inline void refresh(int i) { t[i].v = (t[ls(i)].v + t[rs(i)].v) % M; }

void build(int i, int l, int r) {
    t[i].l = l, t[i].r = r, t[i].a = 1;
    if (l==r) 
        t[i].v = a[l];
    else {
        int mid = get_mid(l, r);
        build(ls(i), l, mid);
        build(rs(i), mid+1, r);
        refresh(i);
    }
};

void apply_tag(int i, ll a, ll b) {
    auto& n = t[i];
    n.v = (n.v * a + (b*(n.r-n.l+1))) % M;
    n.a = (n.a * a) % M;
    n.b = (n.b * a + b) % M;
}

void push(int i) {
    if (t[i].a==1 && t[i].b==0) return;
    apply_tag(ls(i), t[i].a, t[i].b);
    apply_tag(rs(i), t[i].a, t[i].b);
    t[i].a = 1, t[i].b = 0;
}

ll query(int i, int l, int r) {
    Node& n = t[i];
    if (l<=n.l && n.r<=r)
        return t[i].v;
    else {
        push(i);
        int mid = get_mid(n.l, n.r);
        ll ret = 0;
        if (l <= mid) ret =  query(ls(i), l, r); 
        if (mid < r)  ret += query(rs(i), l, r);
        return ret % M;
    }
}

void update(int i, int l, int r, ll a, ll b) {
    Node& n = t[i];
    if (l<=n.l && n.r<=r)
        apply_tag(i, a, b);
    else {
        push(i);
        int mid = get_mid(n.l, n.r);
        if (l <= mid) update(ls(i), l, r, a, b);
        if (mid < r)  update(rs(i), l, r, a, b);
        refresh(i);
    }
}

int main() {
    scanf("%d %lld", &n, &M);
    REP(i, 1, n) scanf("%d", &a[i]);

    build(1, 1, n);

    int m;
    scanf("%d", &m);
    for (int t,l,r,i=0; i<m; ++i) {
        scanf("%d", &t);
        if (t==1) {
            long long c;
            scanf("%d %d %lld", &l, &r, &c);
            update(1, l, r, c, 0);
        } else if (t==2) {
            long long c;
            scanf("%d %d %lld", &l, &r, &c);
            update(1, l, r, 1, c); //a must be 1
        } else {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }

    return 0;
}