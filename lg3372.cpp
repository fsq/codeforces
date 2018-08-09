#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
public:
    int l, r;
    long long tag, sum;
    Node():tag(0),sum(0) {}
} t[400009];

inline int get_mid(int l, int r) { return (l+r)>>1; }
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }
inline void refresh(int x) { t[x].sum = t[ls(x)].sum + t[rs(x)].sum; }

void build(int x, int l, int r) {
    t[x].l = l, t[x].r = r;
    if (l<r) {
        int mid = get_mid(l, r);
        build(ls(x), l, mid);
        build(rs(x), mid+1, r);
    }
}

void addTag(int x, long long val) {
    t[x].sum += val*(t[x].r-t[x].l+1);
    t[x].tag += val;
}

void push(int x) {
    addTag(ls(x), t[x].tag);
    addTag(rs(x), t[x].tag);
    t[x].tag = 0;
}

void add(int x, int l, int r, long long val) {
    if (t[x].l>=l && t[x].r<=r)
        addTag(x, val);
    else {
        push(x);
        int mid = get_mid(t[x].l, t[x].r);
        if (l<=mid) add(ls(x), l, r, val);
        if (r>mid)  add(rs(x), l, r, val);
        refresh(x);
    }
}

long long query(int x, int l, int r) {
    if (t[x].l>=l && t[x].r<=r)
        return t[x].sum;
    else {
        push(x);
        long long ret = 0;
        int mid = get_mid(t[x].l, t[x].r);
        if (l<=mid) ret += query(ls(x), l, r);
        if (r>mid)  ret += query(rs(x), l, r);
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    
    long long k;
    for (int i=1; i<=n; ++i) {
        cin >> k;
        add(1, i, i, k);
    }
    for (int c,x,y; m; --m) {
        cin >> c >> x >> y;
        if (c==1) {
            cin >> k;
            add(1, x, y, k);
        } else 
            cout << query(1, x, y) << '\n';
    }

    return 0;
}