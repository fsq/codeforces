#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
vector<ll> tree;
set<int> st;
vector<int> a;
vector<int> divisor;

inline int get_mid(int l, int r) { return (l+r) >> 1; }
inline int ls(int now) { return now<<1; }
inline int rs(int now) { return (now<<1)+1; }
void refresh(int now) {
    tree[now] = tree[ls(now)] + tree[rs(now)];
}

void build(int now, int l, int r) {
    if (l==r) 
        tree[now] = a[l];
    else {
        int mid = get_mid(l, r);
        build(ls(now), l, mid);
        build(rs(now), mid+1, r);
        refresh(now);
    }
}

ll query(int now, int l, int r, int start, int end) {
    if (start<=l && r<=end) 
        return tree[now];
    else {
        int mid = get_mid(l, r);
        ll ret = 0;
        if (start<mid+1) ret += query(ls(now), l, mid, start, end);
        if (mid+1<=end)  ret += query(rs(now), mid+1, r, start, end);
        return ret;
    }
}

ll update(int now, int l, int r, int index) {
    ll ret;
    if (l==r) 
        ret = tree[now] = divisor[tree[now]];
    else {
        int mid = get_mid(l, r);
        ret = index<=mid ? update(ls(now), l, mid, index) : 
                                update(rs(now), mid+1, r, index);
        refresh(now);
    }
    return ret;
}

int main() {
    int n , m;
    scanf("%d %d", &n, &m);
    int maxn = INT_MIN;

    for (int j, i=0; i<n; ++i) {
        scanf("%d", &j);
        a.push_back(j);
        maxn = max(maxn, j);
        if (j > 2) st.insert(i);
    }

    tree = vector<ll>(n<<2, 0);
    build(1, 0, n-1);

    divisor = vector<int>(maxn+1, 0);
    for (int i=1; i<=maxn; ++i)
        for (int j=i; j<=maxn; j+=i)
            ++divisor[j];

    int t, l, r;
    while (m--) {
        scanf("%d %d %d", &t, &l, &r);
        --l, --r;
        if (t==1) {
            for (auto it=st.lower_bound(l); it!=st.end() && *it<=r; ) {
                auto newv = update(1, 0, n-1, *it);
                if (newv<=2) 
                    it = st.erase(it);
                else 
                    ++it;
            }
        } else 
            // printf("%lld\n", query(1, 0, n-1, l, r));
            printf("%I64d\n", query(1, 0, n-1, l, r));
    }

    return 0;
}