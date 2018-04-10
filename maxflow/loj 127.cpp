#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
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
const int MAXN = 1301;

class Node {
public:
    int h, p, sz, e;
    int N[MAXN];
    Node() {h=e=p=sz=0;}
} V[MAXN];

int n, m, src, snk;
int f[MAXN][MAXN], c[MAXN][MAXN];

inline void link(int x, int y, int cap) {
    c[x][y] = cap;
    V[x].N[V[x].sz++] = y;
    V[y].N[V[y].sz++] = x;
}

void build() {
    int u,v, cap;
    REP(i, 1, m) {
        scanf("%d %d %d", &u, &v, &cap);
        link(u, v, cap);
    }
}

inline int cf(int u, int v) { return c[u][v]-f[u][v]+f[v][u]; }

inline void _push(int u, int v, int fl) { f[u][v] += fl, V[u].e -= fl, V[v].e += fl; }

inline void relabel(int u) {
    int h = n<<1;
    FOR(i, V[u].sz)
        if (cf(u, V[u].N[i])>0) h = min(h, V[V[u].N[i]].h+1);
    V[u].h = h;
}

inline void push(int u, int v) {
    int fl = min(V[u].e, cf(u, v));
    if (f[v][u]>0) _push(v, u, -fl);
            else   _push(u, v, fl);
}

void discharge(int u) {
    for (Node& n =V[u]; n.e;) 
        if (n.p==n.sz) {
            relabel(u);
            n.p = 0;
        } else {
            int v = n.N[n.p];
            if (cf(u,v)>0 && n.h==V[v].h+1)
                push(u, v);
            else 
                ++n.p;
        }
}

inline void init() {
    V[src].h = n;
    FOR(i, V[src].sz)
        _push(src, V[src].N[i], c[src][V[src].N[i]]);
}

int relabel_to_front() {

    init();

    list<int> ls;
    REP(i, 1, n) if (i!=src && i!=snk) ls.PB(i);

    for (auto it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h>oldh)
            ls.splice(ls.begin(), ls, it);
    }

    return V[snk].e;
}

int main() {
    scanf("%d %d %d %d", &n,&m,&src,&snk);

    build();

    printf("%d\n", relabel_to_front());

    return 0;
}