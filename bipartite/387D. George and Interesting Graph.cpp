#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <memory>
#include <list>
#include <climits>
#include <future>
using namespace std;

#define PB                  push_back
#define F                   first
#define S                   second

#define REP(i,from,to)      for(auto i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(auto i=(from); i>=(to); --i)
#define REP_IF(i,from,to,assert)   for(auto i=(from); i<=(to); ++i) if (assert)

#define FOR(i,less_than)    for (auto i=0; i<(less_than); ++i)
#define FORI(i, container)  for (auto i=0; i<(container).size(); ++i)
#define FORI_IF(i, container, assert) for (auto i=0; i<(container).size(); ++i) if (assert)
#define ROFI(i, container)  for (auto i=(container).size()-1; i>=0; --i)

#define FOREACH(elem, container)  for (auto elem : (container))
#define FILL(container, value)    memset(container, value, sizeof(container))
#define ALL(container)            (container).begin(), (container).end()
#define SZ(container)             (int)((container).size())

#define BACK(set_map)       *prev((set_map).end(), 1)
#define FRONT(set_map)      *(set_map).begin()

inline void _RD(int &x) { scanf("%d", &x); }
inline void _RD(long long &x) { scanf("%lld", &x); }
inline void _RD(double &x) { scanf("%lf", &x); }
inline void _RD(long double &x) { scanf("%Lf", &x); }
inline void _RD(char &x) { scanf(" %c", &x); }
inline void RD() {}
template<class T, class... U> 
inline void RD(T &head, U &... tail) { _RD(head); RD(tail...); }

using PII = pair<int,int>;
using LL  = long long;
using VI  = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;

const int MAXN = 1007;

VI e[MAXN];
int n, m;
int ind[MAXN], oud[MAXN];
bool self[MAXN];
const int INF = 0x3f3f3f3f;

bool bfs(const int ignore, int M[], int d[]) {
    queue<int> q;
    REP(i, 1, n) 
        if (i!=ignore)
            if (M[i])
                d[i] = INF;
            else 
                d[i] = 0, q.push(i);
        else {}
    d[0] = INF;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        if (d[u]<d[0])
            FOREACH(v, e[u])
                if (v!=n+ignore && d[M[v]]==INF) {
                    d[M[v]] = d[u] + 1;
                    q.push(M[v]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u, const int ignore, int M[], int d[]) {
    if (!u) return true;
    int dt = d[u];
    d[u] = INF;
    FOREACH(v, e[u])
        if (v!=n+ignore && d[M[v]]==dt+1 && dfs(M[v], ignore, M, d)) {
            M[u] = v, M[v] = u;
            return true;
        }       
    return false;
}

int hpk(int ignore) {
    int M[n<<1|1], d[n<<1|1], ans=0;
    FILL(M, 0);
    while (bfs(ignore,M,d)) 
        REP(i, 1, n) 
            if (i!=ignore && !M[i] && dfs(i,ignore,M,d))
                ++ans;
    return ans;
}

int solve(int l, int r) {
    int ans = INT_MAX;
    REP(i, l, r) {
        int cnt = 0;
        cnt = self[i] ? 2*n-ind[i]-oud[i] : 2*n-ind[i]-oud[i]-1; // i as center
        int mc = hpk(i);
        cnt = cnt + m - (ind[i]+oud[i]-self[i]) + n-1 - 2*mc;

        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    RD(n, m);
    REP(i, 1, m) {
        int u, v;
        RD(u, v);
        e[u].PB(n+v);
        ++ind[v], ++oud[u];
        if (u==v) self[u] = true;
    }

    auto f1 = async(launch::async, solve, 1, n/2);
    auto f2 = solve(n/2+1, n);
    int ans = min(f1.get(), f2);

    printf("%d\n", ans);

    return 0;
}