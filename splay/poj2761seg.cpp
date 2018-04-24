#include <cstdio>
#include <vector>
#include <algorithm>
#define cind(x) scanf("%d", &x)

using namespace std;

const int MAXN = 200007;

class Node {
public:
    int size, l, r;
    Node():size(0) {}
} t[MAXN<<1|1];

int n, m;
int pn;
int a[MAXN], dog[MAXN];
int seg[MAXN][5];
int ans[MAXN];

inline int get_mid(int l, int r) { return (l+r)>>1; }
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }
inline void refresh(int x) { t[x].size = t[ls(x)].size + t[rs(x)].size; }

void build(int node, int l, int r) {
    t[node].l = l;
    t[node].r = r;
    t[node].size = 0;    
    if (l!=r) {
        int mid = get_mid(l, r);
        build(ls(node), l, mid);
        build(rs(node), mid+1, r);
    }
}

void update(int node, int pos, int delta) {
    Node& n = t[node];
    if (n.l==n.r) 
        n.size += delta;
    else {
        int mid = get_mid(n.l, n.r);
        if (pos<=mid) update(ls(node), pos, delta);
                else  update(rs(node), pos, delta);
        refresh(node);
    }
}

int query(int node, int k) {
    Node& n = t[node];
    if (n.l==n.r)
        return a[n.l];
    else {
        if (k<=t[ls(node)].size)
            return query(ls(node), k);
        else
            return query(rs(node), k-t[ls(node)].size);
    }
}

int cmp(const void *a,const void *b) {
    const int *x =  (const int*)a;
    const int *y =  (const int*)b;
    return x[0]==y[0] ? x[1]-y[1] : x[0]-y[0];
}

int main() {
    cind(n), cind(m);

    for (int i=1; i<=n; ++i) {
        cind(a[i]);
        dog[i] = a[i];
    }

    sort(a+1, a+n+1);
    pn = unique(a+1, a+n+1) - a - 1;

    build(1, 1, pn);
    for (int i=1; i<=m; ++i) 
        cind(seg[i][0]), cind(seg[i][1]), cind(seg[i][2]), seg[i][3] = i;

    qsort(seg+1, m, sizeof(*seg), cmp);

    int start = 1, end = 1;
    for (int pos, i=1; i<=m; ++i) {
        while (end<=seg[i][1]) {
            pos = lower_bound(a+1, a+pn+1, dog[end++]) - a;
            update(1, pos, 1);
        }

        while (start<seg[i][0]) {
            pos = lower_bound(a+1, a+pn+1, dog[start++]) - a;
            update(1, pos, -1);
        }
        ans[seg[i][3]] = query(1, seg[i][2]);
    }

    for (int i=1; i<=m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}