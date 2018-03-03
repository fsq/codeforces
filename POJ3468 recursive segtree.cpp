#include <cstdio>
#include <memory>

using namespace std;

const int MAXN = 100007;
typedef long long ll;
struct Node {
    ll s, d, len;
    int l, r;
} t[MAXN<<2];

int n, q;

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }
inline bool inside(Node& n, int l, int r) { return l<=n.l && n.r<=r; }
inline bool outside(Node& n, int l, int r) { return r<n.l || l>n.r; }

void refresh(int x) {
    t[x].s = t[ls(x)].s + t[rs(x)].s + t[x].d * t[x].len;
}

void build(int node, int l, int r) {
    Node& n = t[node];
    n.l = l, n.r = r;
    n.len = r - l + 1;
    n.d   = 0;

    if (l==r) {
#ifdef ONLINE_JUDGE
        scanf("%I64d", &n.s);
#else
        scanf("%lld", &n.s);
#endif
    } else {
        int mid = (l+r)>>1;
        build(ls(node), l, mid);
        build(rs(node), mid+1, r);
        refresh(node);
    }
}

void apply(int x, ll v) {
    t[x].s += v * t[x].len;
    t[x].d += v;
}

void push_down(int x) {
    if (t[x].d!=0) {
        apply(ls(x), t[x].d);
        apply(rs(x), t[x].d);
        t[x].d = 0;
    }
}

void update(int node, int l, int r, ll v) {
    Node& n = t[node];
    if (inside(n, l, r))
        apply(node, v);
    else if (outside(n, l, r))
        return;
    else {
        push_down(node);
        update(ls(node), l, r, v);
        update(rs(node), l, r, v);
        refresh(node);
    }
}

ll query(int node, int l, int r ) {
    Node& n = t[node];
    if (inside(n, l, r)) return n.s;
    if (outside(n, l, r)) return 0;
    push_down(node);
    return query(ls(node), l, r) + query(rs(node), l, r);
}

int main() {
    scanf("%d %d\n", &n, &q);
    build(1, 1, n);
    scanf("\n");

    char ch;
    int a, b, c;
    while (q--) {
        scanf("%c", &ch);
        if (ch=='C') {
            scanf("%d %d %d\n", &a, &b, &c);
            update(1, a, b, c);
        } else {
            scanf("%d %d\n", &a, &b);
#ifdef ONLINE_JUDGE
            printf("%I64d\n", query(1, a, b));
#else
            printf("%lld\n", query(1, a, b));
#endif
        }
    }

    return 0;
}