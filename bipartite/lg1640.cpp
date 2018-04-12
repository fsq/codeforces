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

const int MAXN = 10003;
const int INF = 0x3f3f3f3f;
const int MAXM = 1e6 + 7;

VI e[MAXN];
int M[MAXN+MAXM], n;
int d[MAXN];

bool bfs(int n) {
    queue<int> q;
    REP(i, 1, n) 
        if (!M[i]) {
            q.push(i);
            d[i] = 0;
        } else 
            d[i] = INF;
    d[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u]<d[0])
            FOREACH(v, e[u])
                if (d[M[v]]==INF) {
                    q.push(M[v]);
                    d[M[v]] = d[u] + 1;
                }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    FOREACH(v, e[u]) 
        if (d[M[v]]==d[u]+1 && dfs(M[v])) {
            M[u] = v;
            M[v] = u;
            return true;
        }
    d[u] = INF; 
    return false;
}

int hk(int n) {
    FILL(M, 0);
    int ans = 0;
    while (bfs(n)) 
        REP(i, 1, n) 
            if (!M[i] && dfs(i)) 
                ++ans;
    return ans;
}

int main() {
    int m;
    RD(m);
    REP(i, 1, m){
        int x, y;
        RD(x, y);
        n = max(n, max(x, y));
        e[x].PB(MAXN+i), e[y].PB(MAXN+i);
    }

    int l = 0, r = n;
    while (l<r) {
        int mid = (l+r) >> 1;
        int mc  = hk(mid);
        if (mc==mid) {
            if (l+1==r) {
                if (hk(r)==r) l = r;
                break;
            }
            l = mid;
        } else 
            r = mid - 1;
    }
    printf("%d\n", l);


    return 0;
}