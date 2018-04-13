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

const int MAXR = 203;

int a[MAXR][MAXR];
int M[2*MAXR], d[MAXR];
int e[2*MAXR][MAXR*2];
int sz[MAXR];
int n;
const int INF = 0x3f3f3f3f;

inline void link(int u, int v) {
    e[u][sz[u]++] = v;
}

bool bfs() {
    queue<int> q;
    REP(i, 1, n)
        if (M[i]) 
            d[i] = INF;
        else {
            d[i] = 0;
            q.push(i);
        }
    d[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u]<d[0])
            FOR(i, sz[u])
                if (d[M[e[u][i]]]==INF) {
                    d[M[e[u][i]]] = d[u] + 1;
                    q.push(M[e[u][i]]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    int dt = d[u];
    d[u] = INF;
    FOR(i, sz[u])
        if (d[M[e[u][i]]]==dt+1 && dfs(M[e[u][i]])) {
            M[u] = e[u][i];
            M[e[u][i]] = u;
            return true;
        }
    return false;
}

int hpk() {
    FILL(M, 0);
    int ans = 0;
    while (bfs()) 
        REP(i, 1, n) 
            if (!M[i] && dfs(i)) ++ans;
    return ans;
}

int main() {

    int T;
    RD(T);
    REP(t, 1, T) {
        RD(n);
        REP(i, 1, n)
            REP(j, 1, n) 
                RD(a[i][j]);
            
        FILL(sz, 0);
        REP(i, 1, n)
            REP(j, 1, n) 
                if (a[i][j]==1) 
                    link(i, n+j);

        int match = hpk();
        if (match==n) printf("Yes\n"); else printf("No\n");
    }

    return 0;
}