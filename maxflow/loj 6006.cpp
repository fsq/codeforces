#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include <list>
using namespace std;

#define PB                  push_back
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define SZ(x) ((int)(x).size())
#define FOR(i,a) for (int i=0; i<a;++i)
const int MAXN = 3003;
struct Node {
    int h,e,p;
    vector<int> N;
    Node() {h=e=p=0;}
} V[MAXN];

int n, k, m;
int c[MAXN][MAXN], f[MAXN][MAXN];

int src, snk;

inline int cf(int u, int v) { return c[u][v]-f[u][v]+f[v][u]; }

void link(int u, int v, int cap) {
    c[u][v] = cap;
    V[u].N.PB(v);
    V[v].N.PB(u);
}

void build() {
    src = 0, snk = n+k+1;
    m = 0;
    REP(i, 1, k) {
        int j; scanf("%d", &j);
        m += j;
        link(n+i, snk, j);
    }
    REP(i, 1, n) {
        link(src, i, 1);
        int j; scanf("%d", &j);
        REP(_k, 1, j) {
            int nxt; scanf("%d", &nxt);
            link(i, n+nxt, 1);
        }
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
    FOR(i, SZ(V[src].N)) _push(src, V[src].N[i], c[src][V[src].N[i]]);
}

void relabel(int u) {
    int h = (snk+1)<<1;
    // FOREACH(x, V[u].N)
    FOR(i, SZ(V[u].N))
        if (cf(u,V[u].N[i])>0) h = min(h, V[V[u].N[i]].h+1);
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

    for (list<int>::iterator it=ls.begin(); it!=ls.end(); ++it) {
        int u = *it, oldh = V[u].h;
        discharge(u);
        if (V[u].h > oldh)
            ls.splice(ls.begin(), ls, it);
    }

    int maxflow = 0;
    REP(i, n+1, snk-1) maxflow += f[i][snk];
    return maxflow;
}

int main() {
    scanf("%d %d", &k, &n);

    build();

    int maxflow = relabel_to_front();

    if (maxflow!=m) 
        printf("No Solution!");
    else {
        vector<vector<int> > ans(k+1);
        REP(i, 1, n)
            FOR(j, SZ(V[i].N))
                if (V[i].N[j]!=src && f[i][V[i].N[j]]>0)
                    ans[V[i].N[j]-n].PB(i);
        REP(i, 1, k) {
            printf("%d:", i);
            FOR(x, SZ(ans[i])) printf(" %d", ans[i][x]);
            printf("\n");
        }
    }


    return 0;
}