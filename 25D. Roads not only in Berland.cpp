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

VI fa;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {

    int n;
    RD(n);
    fa = VI(n+1, 0);
    iota(ALL(fa), 0);

    VVI rd;
    REP(i, 1, n-1) {
        int x, y;
        RD(x, y);
        int fx = find(x), fy = find(y);
        if (fx==fy) 
            rd.PB({x, y, 0, 0});
        else 
            fa[fx] = fy;
        
    }

    VI rt;
    REP_IF(i, 1, n, fa[i]==i) rt.PB(i);
    FORI_IF(i, rt, i>0) {
        rd[i-1][2] = rt[i];
        rd[i-1][3] = rt[i-1];
    }
    printf("%d\n", SZ(rt)-1);
    FOREACH(&r, rd)
        printf("%d %d %d %d\n", r[0],r[1],r[2],r[3]);



    return 0;
}