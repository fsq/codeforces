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

const int MAXN = 701;

struct Node {
    int h,e,p;
    VI N;
    Node() {h=e=p=0; }
} V[MAXN];

int s, n, f[MAXN][MAXN], c[MAXN][MAXN], src, snk;
VI a, l;

inline int cf(int u, int v) { return c[u][v]-f[u][v]+f[v][u]; }

void solve_s() {
    l[0] = 0, a[0] = INT_MIN;
    REP(i, 1, n)
        REP(j, 0, i-1)
            if (a[i]>=a[j]) l[i] = max(l[i], l[j]+1);
    s = 0;
    REP(i, 1, n) s = max(s, l[i]);
    printf("%d\n", s);
}

void link(int u, int v, int cap) {
    c[u][v] = cap;
    V[u].N.PB(v);
    V[v].N.PB(u);
}

void build() {
    src = 0, snk = n+1;
    REP(i, 1, n) {
        bool hasi = false;
        vector<int> h; 
        h.reserve(s);
        h.PB(a[i]);
        REP(j, i+1, n) {
            int p = upper_bound(ALL(h), a[j]) - h.begin();
            if (p==0) continue;
            if (SZ(h)==p) h.PB(a[j]);
                else      h[p] = min(h[p], a[j]);
            if (p+1==s) {
                if (!hasi) hasi = true;
                link(i, j, 1), link(j, snk, 1);
            }
        }
        if (hasi) link(src, i, 1);
    }
}

void _push(int u, int v, int fl) { f[u][v]+=fl, V[u].e-=fl, V[v].e+=fl; }

void init() {
    FILL(f, 0); 
    REP(i, src, snk) V[i].e = V[i].h = V[i].p = 0;
    V[src].h = snk + 1;
    FOREACH(x, V[src].N) _push(src, x, c[src][x]);
}

void relabel(int u) {
    int h = (snk+1)<<1;
    FOREACH(x, V[u].N)
        if (cf(u, x)>0) h = min(h, V[x].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int fl = min(V[u].e, cf(u, v));
    if (f[v][u]>0) _push(v, u, -fl);
            else   _push(u, v, fl);
}

void discharge(int u) {
    for (Node& n=V[u]; n.e>0; )
        if (n.p==SZ(n.N)) {
            relabel(u);
            n.p = 0;
        } else {
            int v = n.N[n.p];
            if (cf(u, v)>0 && n.h==V[v].h+1)
                push(u, v);
            else 
                ++n.p;
        }
}

int relabel_to_front() {
    init();
    list<int> ls;
    REP(i, 1, n) ls.PB(i);
    for (auto it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h>oldh) ls.splice(ls.begin(), ls, it);
    }

    int flow = 0;
    REP(i, 1, n) if (f[i][snk]>0) flow += f[i][snk];
    return flow;
}

void rebuild() {
    if (c[src][1]>0) c[src][1] = INT_MAX;
    if (c[n][snk]>0) c[n][snk] = INT_MAX;
}

int main() {
    RD(n);
    a.resize(n+1), l.resize(n+1);
    REP(i, 1, n) RD(a[i]);

    solve_s();

    if (s==1) 
        printf("%d\n%d\n", n, n);
    else {
        build();
        
        printf("%d\n", relabel_to_front());
        
        rebuild();
        
        printf("%d\n", relabel_to_front());
    }
    
    return 0;
}