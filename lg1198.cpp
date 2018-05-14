#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long M;
int m, n;

struct Node {
    int x, l, r;
    Node() { x = 0; }
} t[800007];

inline int get_mid(int l, int r) { return (l+r)>>1; }
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }

void build(int x, int l, int r) {
    t[x].l = l, t[x].r = r;
    if (l!=r) {
        int mid = get_mid(l, r);
        build(ls(x), l, mid);
        build(rs(x), mid+1, r);
    }
}

int query(int x, int l, int r) {
    auto& n = t[x];
    if (l<=n.l && n.r<=r) return n.x;
    int mid = get_mid(n.l, n.r);
    if (r<=mid) 
        return query(ls(x), l, r);
    else if (mid<l)
        return query(rs(x), l, r);
    else 
        return max(query(ls(x), l, r), query(rs(x), l, r));
}

void update(int x, int p, int v) {
    if (t[x].l==t[x].r) {
        t[x].x = v;
    } else {
        int mid = get_mid(t[x].l, t[x].r); 
        update((p<=mid) ? ls(x) : rs(x), p, v);
        t[x].x = max(t[ls(x)].x, t[rs(x)].x);
    }
}

int main() {
    scanf("%d %lld\n", &m, &M);
    vector<pair<int,long long>> op;
    for (int i=0; i<m; ++i) {
        char c;
        long long x;
        scanf("%c %lld\n", &c, &x);
        op.push_back({c=='Q' ? 0 : 1, x});
        if (c=='A') ++n;
    }  

    build(1, 1, n);
    int cnt = 0, pre = 0;
    for (auto& p : op) {
        if (p.first==0) {
            if (p.second==0)
                pre = 0;
            else
                pre = query(1, cnt-p.second+1, cnt);
            printf("%d\n", pre);
        } else {
            int nxt = (p.second + pre) % M;
            update(1, ++cnt, nxt);
        }
    }

    return 0;
}