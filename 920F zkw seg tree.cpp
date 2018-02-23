#include <vector>
#include <iostream>

using namespace std;

using ll = long long;

vector<ll> tree;
vector<int> d;
vector<int> fa;
int n, m;

void build() {
    for (int i=n-1; i>0; --i)
        tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

ll query(int l, int r) {
    ll res = 0;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l & 1) res += tree[l++];
        if (r & 1) res += tree[--r];
    }
    return res;
}

void modify(int p, int val) {
    for (tree[p+=n]=val; p>1; p>>=1)
        tree[p>>1] = tree[p] + tree[p^1];
}

int find(int x) {
    if (x>=n) return n;
    return tree[n+x]<=2 ? fa[x]=find(fa[x]) : x;
}

int main() {
    scanf("%d %d", &n, &m);

    tree = vector<ll>(n<<1 | 1, 0);   
    fa = vector<int>(n+1, 0);

    ll maxx = -1;
    for (int i=0; i<n; ++i) {
#ifdef ONLINE_JUDGE
        scanf("%I64d", &tree[n+i]);
#else
        scanf("%lld", &tree[n+i]);
#endif
        maxx = max(maxx, tree[n+i]);
        fa[i] = (tree[n+i]>2) ? i : i+1;
    }
    build();

    // calculate # divisors
    d = vector<int>(maxx+1, 0);
    for (int i=1; i<=maxx; ++i) 
        for (int j=i; j<=maxx; j+=i)
            ++d[j];

    int t, l, r;
    while (m--) {
        scanf("%d %d %d", &t, &l, &r);
        --l, --r;
        if (t == 1) {
            for (l=find(l); l<=r; l=find(l+1)) {
                modify(l, d[tree[n+l]]);
                if (tree[n+l]<=2)
                    fa[l] = l + 1;
            }
        } else 
#ifdef ONLINE_JUDGE
            printf("%I64d\n", query(l, r+1));
#else
            printf("%lld\n", query(l, r+1));
#endif
    }


    return 0;
}