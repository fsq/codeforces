#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
int n;
int h;
vector<ll> tree, d, len;

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }

// add tag v to node i
void apply(int i, ll v) {
    tree[i] += len[i] * v;
    if (i<n) d[i] += v;
}

void build() {
    h = geth(n);
    tree = vector<ll>(n<<1 | 1, 0);
    len = d = tree;
    for (int i=0; i<n; ++i) {
        scanf("%lld", &tree[n+i]);
        len[n+i] = 1;
    }
    scanf("\n");
    for (int i=n-1; i>0; --i) {
        tree[i] = tree[ls(i)] + tree[rs(i)];
        len[i] = len[ls(i)] + len[rs(i)];
    }
}
// update parents
void build(int p) {
    while (p > 1) p >>= 1, tree[p] = tree[ls(p)] + tree[rs(p)] + d[p]*len[p];
}
// propagate tags
void push(int p) {
    for (int s=h; s>0; --s) {
        int i = p >> s;
        if (d[i]!=0) {
            apply(ls(i), d[i]);
            apply(rs(i), d[i]);
            d[i] = 0;
        }
    }
}

// add tags to [l, r)
void update(int l0, int r0, ll v) {
    l0 += n, r0 += n;
    for (int l=l0, r=r0; l<r; l>>=1, r>>=1) {
        if (l&1) apply(l++, v);
        if (r&1) apply(--r, v);
    }
    build(l0); // update parents of modifed nodes
    build(r0-1);
}

ll query(int l, int r) {
    ll res = 0;
    // push tags to nodes to be visited
    for (push(l+=n), push((r+=n)-1); l<r; l>>=1, r>>=1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}
// height of first [1, n) nodes, starting from 1
int geth(int n) {
    int h = 0;
    for (int i=31; i>=0; --i)
        if (n>>i & 1) 
            break;
        else
            ++h;
    return sizeof(int)*8 - h;
}

int main() {
    int q;
    scanf("%d %d\n", &n, &q);

    // h = sizeof(int) * 8 - __builtin_clz(n); // of first n nodes

    build();

    char c;
    int a, b;
    ll v;
    while (q--) {
        scanf("%c ", &c);
        if (c=='C') {
            scanf("%d %d %lld\n", &a, &b, &v);
            update(a-1, b, v);
        } else {
            scanf("%d %d\n", &a, &b);
            printf("%lld\n", query(a-1, b));
        }
    }
    return 0;
}