#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> a, s;
vector<int> nxt;
vector<int> d;

int n, m;

int lowbit(int x) {
    return x & -x;
}

void update(int i, int new_val) {
    long long delta = new_val - a[i];
    a[i] = new_val;
    for (++i; i<=n; i+=lowbit(i)) 
        s[i] += delta;
}

long long query(int i) {
    long long res = 0;
    for (++i; i>0; i-=lowbit(i))
        res += s[i];
    return res;
}

// like union find set
// nxt[p] : p's next valid cell
int next(int p) {
    if (p>=n) return n;
    return a[p]>2 ? p : nxt[p] = next(nxt[p]);
}

int main() {
    scanf("%d %d", &n, &m);
    int maxn = INT_MIN;

    nxt = vector<int>(n+1, 0);
    s = a = vector<long long>(n+1, 0);
    for (int j, i=0; i<n; ++i) {
        scanf("%d", &j);
        update(i, j);
        nxt[i] = j<=2 ? i+1 : i;
        maxn = max(maxn, j);
    }

    d = vector<int>(maxn+1, 0);
    for (int i=1; i<=maxn; ++i)
        for (int j=i; j<=maxn; j+=i)
            ++d[j];

    int t, l, r;
    while (m--) {
        scanf("%d %d %d", &t, &l, &r);
        --l, --r;
        if (t==1) {
            l = next(l);
            while (l<=r) {
                update(l, d[a[l]]);
                if (a[l]<=2) 
                    nxt[l] = l + 1;
                l = next(l+1);
            }
        } else 
            cout << query(r) - query(l-1) << '\n';
        // printf("%I64d\n", query(r) - query(l-1));
    }

    return 0;
}
