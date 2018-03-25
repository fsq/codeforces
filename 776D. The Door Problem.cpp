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

VI fa, re;

int find(int x) {
    if (fa[x]==x) return x;
    int f = fa[x];
    fa[x] = find(fa[x]);
    re[x] ^= re[f];
    return fa[x];
}


int main() {
    int n, m;
    RD(n, m);

    VI a(n+1, 0);
    REP(i, 1, n) RD(a[i]);

    VVI e(n+1, VI{});
    REP(i, 1, m) {
        int j, rm;
        RD(j);
        while (j--) {
            RD(rm);
            e[rm].PB(i);
        }
    }

    fa = re = VI(m+1, 0);
    iota(ALL(fa), 0);

    bool bad = false;
    REP(i, 1, n) {
        int x=e[i][0], y=e[i][1];
        int fx=find(x), fy=find(y);

        if (fx==fy) {
            int rl = re[x] ^ re[y];
            if (rl==!a[i]) continue;
            bad = true;
            break;
        } else {
            fa[fx] = fy;
            re[fx] = (!a[i]) ^ re[x] ^ re[y]; // rx^fa[fx] = (!a[x])^ry
        }
    }


    if (bad) printf("NO\n");
        else printf("YES\n");

    return 0;
}