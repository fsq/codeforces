#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define PB(x)       push_back(x)
#define REP(i,a,b)  for(int i=(a); i<=(b); ++i)
#define PER(i,a,b)  for(int i=(a); i>=(b); --i)

#define FOR(i,n)    for (int i=0; i<(n); ++i)
#define FORI(i, x)  for (int i=0; i<(x).size(); ++i)
#define ROFI(i, x)  for(int i=(x).size()-1; i>=0; --i)

#define FOREACH(a, x) for (auto a : (x))
#define FILL(x, a)  memset(x, a, sizeof(x))
#define ALL(x)      (x).begin(), (x).end()
#define SZ(x)       (int)((x).size())

inline void _RD(int &x) { scanf("%d", &x); }
inline void _RD(long long &x) { scanf("%lld", &x); }
inline void _RD(double &x) { scanf("%lf", &x); }
inline void _RD(long double &x) { scanf("%Lf", &x); }
inline void _RD(char &x) { scanf(" %c", &x); }
inline void RD() {}
template<class T, class... U> 
inline void RD(T &head, U &... tail) { _RD(head); RD(tail...); }

using namespace std;
using LL  = long long;
using VI  = vector<int>;
using VVI = vector<vector<int>>;

const int MAXN = 100007;
const int MOD  = 1e9 + 7;
int cost[MAXN], color[MAXN];
vector<int> e[MAXN], et[MAXN];
int n, m;

void dfs(int x, vector<int> e[], vector<int>& a, int color[]) {
    color[x] = 1;
    FOREACH(nxt, e[x])
        if (!color[nxt])
            dfs(nxt, e, a, color);
    a.PB(x);
}

int main() {
    RD(n);
    REP(i, 1, n) RD(cost[i]);

    RD(m);
    REP(i, 1, m) {
        int u, v;
        RD(u, v);
        e[u].PB(v);
        et[v].PB(u);
    }

    VI ord;
    FILL(color, 0);
    REP(i, 1, n) if (!color[i]) dfs(i, e, ord, color);

    FILL(color, 0);
    VVI scc;
    ROFI(i, ord)
        if (!color[ord[i]]) {
            VI sc;
            dfs(ord[i], et, sc, color);
            sort(ALL(sc), [](int a, int b) { return cost[a]<cost[b]; });
            scc.PB(sc);
        }

    LL min_cost=0, ways=1;

    FORI(i, scc) {
        min_cost += cost[scc[i][0]];
        LL cnt = 0;
        FORI(j, scc[i])
            if (cost[scc[i][j]]==cost[scc[i][0]]) 
                ++cnt;
            else
                break;
        ways = ways * cnt % MOD;
    }

#ifdef ONLINE_JUDGE
    printf("%I64d %d\n", min_cost, ways);
#else
    printf("%lld %lld\n", min_cost, ways);
#endif

    return 0;
}