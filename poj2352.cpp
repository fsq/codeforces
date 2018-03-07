#include <cstdio>
#include <algorithm>
#include <vector>
#define cind(x) scanf("%d", &x)
#define coutd(x) printf("%d\n", x);

using namespace std;

int n;
int maxy;
vector<pair<int,int> > a;
vector<int> t;

inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }

void refresh(int x) {
    t[x] = t[ls(x)] + t[rs(x)];
}

void build() {
    ++maxy; // coordinate [0, maxy]
    t = vector<int>(maxy<<1 | 1, 0);
}

void update(int p) {
    ++t[p+=maxy];
    while (p>1)
        p>>=1, refresh(p);
}

int query(int l, int r) {
    int res = 0;
    for (l+=maxy, r+=maxy; l<r; l>>=1, r>>=1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    cind(n);
    maxy = -1;
    for (int x,y,i=0; i<n; ++i) {
        cind(x), cind(y);
        maxy = max(y, maxy);
        a.push_back(pair<int,int>(x, y));
    }
    sort(a.begin(), a.end());

    build();

    vector<int> ans(n+1, 0);
    for (int i=0; i<n; ++i) {
        update(a[i].second);
        int rank = query(0, a[i].second+1) - 1;
        ++ans[rank];
    }
    for (int i=0; i<n; ++i) coutd(ans[i]);

    return 0;
}