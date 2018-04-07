#include <cstdio>
#include <vector>
#include <list>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a) for(int i=0; i<(a); ++i)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define cf(u,v) (c[u][v]-f[u][v]+f[v][u])

using namespace std;

class Node {
public:
    int h,e,p;
    vector<int> N; 
    Node() { h=e=p = 0; }
};

const int MAXN = 301;
const int INF = 2000000000;
int k,C,m,sink;

int a[MAXN][MAXN], f[MAXN][MAXN], c[MAXN][MAXN], d[MAXN][MAXN];
Node V[MAXN];

void link(int u, int v, int cap=1) {
    c[u][v] = cap;
    V[u].N.PB(v);
    V[v].N.PB(u);
}

void build() {
    sink = k + C + 1;
    REP(i, k+1, k+C) {
        link(0, i);
        REP(j, 1, k)
            if (d[i][j]!=INF) 
                link(i, j);
    }
    REP(i, 1, k) link(i, sink, m);
}

inline void _push(int u, int v, int fl) {
    f[u][v] += fl;
    V[u].e -= fl;
    V[v].e += fl;
}

void relabel(int u, int maxd) {
    int h = (sink+1)<<1;
    FOR(i, SZ(V[u].N))
        if (d[u][V[u].N[i]]<=maxd && cf(u,V[u].N[i])>0)
            h = min(h, V[V[u].N[i]].h+1);
    V[u].h = h;
}

void push(int u, int v) {
    int fl = min(V[u].e, cf(u,v));
    if (f[v][u]>0) 
        _push(v, u, -fl);
    else
        _push(u, v, fl);
}

void discharge(int u, int maxd) {
    while (V[u].e>0) 
        if (V[u].p==SZ(V[u].N)) {
            relabel(u, maxd);
            V[u].p = 0;
        } else {
            int v = V[u].N[V[u].p];
            if (d[u][v]<=maxd && cf(u,v)>0 && V[u].h==V[v].h+1) 
                push(u, v);
            else
                ++V[u].p;
        }
}

bool relabel_to_front(int maxd) {
    memset(f, 0, sizeof(f));
    list<int> ls;
    REP(i, 0, sink) {
        V[i].h = V[i].e = V[i].p = 0;
        if (i!=0 && i!=sink) ls.PB(i);
    }
    V[0].h = sink + 1;
    FOR(i, SZ(V[0].N)) 
        _push(0, V[0].N[i], 1);

    list<int>::iterator it = ls.begin();
    while (it!=ls.end()) {
        int u = *it, oldh = V[u].h;
        discharge(u, maxd);
        if (V[u].h>oldh)
            ls.splice(ls.begin(), ls, it);
        ++it;
    }

    int flow = 0;
    REP(i, 1, k) flow += f[i][sink];
    return flow==C;
}

void floyed() {
    REP(i, 0, k+C+1)
        REP(j, 0, k+C+1) d[i][j] = a[i][j]==0 ? INF : a[i][j];

    REP(w, 1, k+C)
        REP(i, 1, k+C)
            REP(j, 1, k+C)
                if (d[i][w]!=INF && d[w][j]!=INF)
                    d[i][j] = min(d[i][j], d[i][w]+d[w][j]);

    REP(i, k+1, k+C) d[0][i] = d[i][0] = 0;
    REP(i, 1, k) d[i][k+C+1] = d[k+C+1][i] = 0;
}

int main() {
    scanf("%d %d %d", &k,&C,&m);
    REP(i, 1, k+C) 
        REP(j, 1, k+C) 
            scanf("%d", &a[i][j]);
        
    floyed();
    build();
    
    int l = 1, r = (sink+1)*200;
    while (l<r) {
        int mid = (l+r) >> 1;
        if (relabel_to_front(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    printf("%d\n", l);

    return 0;
}