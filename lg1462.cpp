#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <set>
#define PB push_back
#define REP(i,a,b) for (int i=(a); i<=(b); ++i)

using namespace std;

using ll = long long;
const int MAXN = 10007;
int n, m, b;
int f[MAXN];
vector<pair<int,int>> e[MAXN];

ll sssp(int thresh) {
    ll d[n+1];
    REP(i, 1, n) d[i] = __LONG_LONG_MAX__;

    multiset<pair<ll,int>> st;
    st.insert({0, 1});

    REP(_t, 1, n) {
        while (!st.empty() && d[st.begin()->second]!=__LONG_LONG_MAX__)
            st.erase(st.begin());
        if (st.empty()) break;

        int u = st.begin()->second;
        d[u] = st.begin()->first;
        st.erase(st.begin());

        for (auto &p : e[u])
            if (f[p.first]<=thresh && d[p.first]==__LONG_LONG_MAX__)
                st.insert({p.second+d[u], p.first});
    }

    return d[n];
}


int main() {
    scanf("%d %d %d", &n, &m, &b);
    int r = 0, l = INT_MAX;
    REP(i, 1, n) {
        scanf("%d", &f[i]);
        r = max(r, f[i]);
        l = min(l, f[i]);
    }
    l = max(l, f[1]);

    REP(i, 1, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e[u].PB({v, c});
        e[v].PB({u, c});
    }

    while (l<r) {
        int mid = l + ((r-l)>>1);
        ll cost = sssp(mid);
        if (cost<b) 
            r = mid;
        else 
            l = mid + 1;
    }
    if (sssp(l)<b)
        printf("%d\n", l);
    else
        printf("AFK\n");



    return 0;
}