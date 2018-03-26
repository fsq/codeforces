#include <cstdio>
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
using namespace std;

#define PB(x)               push_back(x)
#define F                   first
#define S                   second

#define REP(i,from,to)      for(int i=(from); i<=(to); ++i)
#define PER(i,from,to)      for(int i=(from); i>=(to); --i)

#define FOR(i,less_than)    for (int i=0; i<(less_than); ++i)
#define FORI(i, container)  for (int i=0; i<(container).size(); ++i)
#define ROFI(i, container)  for(int i=(container).size()-1; i>=0; --i)

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

int n, m;
VI a;
VI fa, rk;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    RD(n, m);
    fa = a = rk = VI(n+1, 0);
    REP(i, 1, n) RD(a[i]);

    iota(ALL(fa), 0);

    REP(i, 1, m) {
        int a, b;
        RD(a, b);
        int fx = find(a), fy = find(b);
        if (fx!=fy) 
            if (rk[fx]==rk[fy]) {
                fa[fx] = fy;
                ++rk[fy];
            } else if (rk[fx]<rk[fy]) 
                fa[fx] = fy;
            else
                fa[fy] = fx;
        else{}      
    }

    VVI group(n+1, VI{});

    REP(i, 1, n) group[find(i)].PB(i);

    FOREACH(&g, group)
        if (!g.empty()) {
            VI s;
            FOREACH(pos, g) s.PB(a[pos]);
            sort(ALL(s), greater<int>());
            FORI(i, g) a[g[i]] = s[i];
        }

    REP(i, 1, n) printf("%d ", a[i]); printf("\n");



    return 0;
}