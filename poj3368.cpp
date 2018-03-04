#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100007;

struct Node {
    int f;
    int h, t, fh, ft;
};

Node t[MAXN<<2 | 1];
Node a[MAXN];

int n, q;

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }
inline int get_mid(int l, int r) { return (l+r)>>1; }

void refresh(int x) {
    Node& n = t[x], &ls = t[ x<<1], &rs =t[x<<1|1];
    n.f = max(ls.f, rs.f);
    if (ls.t==rs.h)
        n.f = max(n.f, ls.ft + rs.fh);

    n.h = ls.h;
    n.fh = rs.h==ls.h ? ls.fh + rs.fh : ls.fh;

    n.t = rs.t;
    n.ft = ls.t==rs.t ? rs.ft + ls.ft : rs.ft;
}

void build(int node, int l, int r) {
    if (l==r) 
        t[node] = a[l];
    else {
        int mid = get_mid(l, r);
        build(ls(node), l, mid);
        build(rs(node), mid+1, r);
        refresh(node);
    }
}

int query(int node, int a, int b, const int &l, const int &r) {
    if (l<=a && b<=r) 
        return t[node].f;
    else {
        int mid = get_mid(a, b);
        if (l>=mid+1)
            return query(rs(node), mid+1, b, l, r);
        else if (r<=mid) 
            return query(ls(node), a, mid, l, r);
        else {
            int ll = ls(node), rr = rs(node);
            int res = max(query(ll, a, mid, l, r), query(rr, mid+1, b, l, r));
            if (t[ll].t==t[rr].h)
                res = max(res, min(t[ll].ft,mid-l+1) + min(t[rr].fh,r-mid));
            return res;
        }
    }
}

int main() {
    while (true) {
        scanf("%d %d", &n, &q);
        if (n==0) break;

        memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));

        for (int j, i=1; i<=n; ++i) {
            scanf("%d", &j);
            Node& x = a[i];
            x.f = x.fh = x.ft = 1;
            x.h = x.t = j;
        }

        build(1, 1, n);

        for (int l,r,i=0; i<q; ++i) {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }

    }


    return 0;
}