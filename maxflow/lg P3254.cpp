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

const int MAXN = 3003;
struct Node {
    int h,e,p;
    vector<int> N;
    Node() {h=e=p=0;}
} V[MAXN];

int n, m, peop;
int c[MAXN][MAXN], f[MAXN][MAXN];

int src, snk;

inline int cf(int u, int v) { return c[u][v]-f[u][v]+f[v][u]; }

void link(int u, int v, int cap) {
    c[u][v] = cap;
    V[u].N.PB(v);
    V[v].N.PB(u);
}

void build() {
    src = 0, snk = n+m+1;
    peop = 0;
    REP(i, 1, m) {
        int j; RD(j);
        peop += j;
        link(src, i, j);
    }
    REP(i, 1, n) {
        int j; RD(j);
        link(i+m, snk, j);
        REP(k, 1, m) link(k, i+m, 1);
    }
}

void _push(int u, int v, int fl) {
    f[u][v] += fl;
    V[u].e -= fl;
    V[v].e += fl;
}

void push(int u, int v) {
    int fl = min(cf(u,v), V[u].e);
    if (f[v][u]>0)
        _push(v, u, -fl);
    else
        _push(u, v, fl);
}

void init() {
    V[src].h = snk + 1;
    FOREACH(x, V[src].N) _push(src, x, c[src][x]);
}

void relabel(int u) {
    int h = (snk+1)<<1;
    FOREACH(x, V[u].N)
        if (cf(u,x)>0) h = min(h, V[x].h+1);
    V[u].h = h;
}

void discharge(int u) {
    Node& n = V[u];
    while (n.e>0) 
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

int relabel_to_front() {
    init();
    list<int> ls;
    REP(i, 1, snk-1) ls.PB(i);

    for (auto it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h > oldh)
            ls.splice(ls.begin(), ls, it);
    }

    int maxflow = 0;
    REP(i, m+1, snk-1) maxflow += f[i][snk];
    return maxflow;
}

int main() {
    RD(m,n);

    build();

    int maxflow = relabel_to_front();


    if (maxflow!=peop) 
        printf("0\n");
    else {
        printf("1\n");
        REP(i, 1, m) {
            FOREACH(j, V[i].N)
                if (j!=src && f[i][j]>0)
                    printf("%d ", j-m);
            printf("\n");
        }

    }


    return 0;
}