#include <cstdio>
#include <iostream>
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
const int MAXN = 35*35;

class Node {
public:
    int h,e,p;
    VI N;
    Node() {h=e=p=0;}
} V[MAXN*MAXN];

int n, m, src, snk;
int f[MAXN][MAXN], c[MAXN][MAXN];
int sum;

void link(int x, int y, int cap) {
    c[x][y] = cap;
    V[x].N.PB(y), V[y].N.PB(x);
}

inline int encode(int x, int y) { return (x-1)*m + y; }

inline bool valid(int x, int y) { return x>0 && x<=n && y>0 && y<=m; }

void build() {
    src = 0, snk = n*m + 1;
    vector<PII> d = {{0,-1},{1, 0},{-1,0},{0,1}};
    sum = 0;
    REP(i, 1, n)
        REP(j, 1, m) {
            int a;
            RD(a);
            sum += a;
            int c = encode(i, j);
            if (!((i+j) & 1)) {
                link(src, c, a);
                FOREACH(&p, d)
                    if (valid(i+p.F, j+p.S)) 
                        link(c, encode(i+p.F,j+p.S), INT_MAX);
            } else 
                link(c, snk, a);
        }
}

inline int cf(int u, int v) { return c[u][v]-f[u][v]+f[v][u]; }

void _push(int u, int v, int fl) { f[u][v] += fl, V[u].e -= fl, V[v].e += fl; }

void relabel(int u) {
    int h = (snk+1)<<1;
    FOREACH(v, V[u].N) 
        if (cf(u, v)>0) h = min(h, V[v].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int fl = min(V[u].e, cf(u, v));
    if (f[v][u]>0) _push(v, u, -fl);
            else   _push(u, v, fl);
}

void discharge(int u) {
    for (Node& n =V[u]; n.e;) 
        if (n.p==SZ(n.N)) {
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

void init() {
    V[src].h = snk+1; 
    FOREACH(v, V[src].N) _push(src, v, c[src][v]);
}

int relabel_to_front() {

    init();

    list<int> ls;
    REP(i, src+1, snk-1) ls.PB(i);
    for (auto it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h>oldh)
            ls.splice(ls.begin(), ls, it);
    }

    int flow = 0;
    REP(i, src+1, snk-1) flow += f[i][snk];
    return flow;
}

int main() {
    RD(n, m);

    build();

    printf("%d\n", sum - relabel_to_front());

    return 0;
}